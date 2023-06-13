#include <iostream>
#include <functional>
#include <set>
#include <vector>
#include <memory>

class SpellChecker {
private:
    std::set<std::string> _dict;

public:
    SpellChecker()
    {
        std::cout<<"SpellChecker const"<<std::endl;
    };

    virtual ~SpellChecker()
    {
        std::cout<<"SpellChecker dist"<<std::endl;
    };

    virtual std::vector<std::string> spell_check(const std::string &data)
    {
        std::cout<<"simple spell_check "<<data << std::endl;
    };
};

class AdvancedSpellChecker : public SpellChecker {
    std::vector<std::string> spell_check(const std::string &data)
    {
        std::cout<<"Advanced Spell checker"<<std::endl;
    };
};

class TextData {
private:
    std::string _data;
    std::unique_ptr<SpellChecker> _spell_checker;

public:
    TextData(const std::string &s,
            std::unique_ptr<SpellChecker> sc){
                _spell_checker = move(sc);
                _data = s;
                std::cout<<"TextData constructor"<<std::endl;
            };
    TextData(const TextData &other);

    TextData& operator=(const TextData &other);

    ~TextData()
    {
        std::cout<<"TextData dist"<<std::endl;
    };

    std::string get_data()
    {
        return _data;
    };

    void spell_check()
    {
        std::cout<<"TextData spell check"<<std::endl;
        _spell_checker->spell_check(_data);
    };
};

int main()
{
    // SpellChecker my_spell;
    // SpellChecker *my_spell = new SpellChecker();
    std::string some_string = "blabla";
    std::unique_ptr<SpellChecker> my_sp (new SpellChecker());
    std::unique_ptr<SpellChecker> adv_sp (new AdvancedSpellChecker());

    my_sp ->spell_check("---- my text----");


    std::unique_ptr<TextData> my_text (new TextData(some_string, move(my_sp)));
    my_text->spell_check();


    return 0;
}

