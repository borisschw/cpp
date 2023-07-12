#include <iostream>

using namespace std;

class flyBehaviour{
    public:
        virtual void fly() = 0;
    private:

};



class rocketFly:public flyBehaviour
{
    private:
    int x = 0;

    public:
    void fly() override
    {
        cout << "fly by rocket"<< endl;
    }
};


class wingFly:public flyBehaviour
{

    private:

    public:
    void fly() override
    {
        cout << "fly with wings"<< endl;
    }
};


class Bird
{
    private:
    flyBehaviour *fb;

    public:
    Bird(flyBehaviour *fb)
    {
        this->fb = fb;
    }

    void fly()
    {
        fb->fly();
    }

    void change_strategy(flyBehaviour *fb)
    {
        this->fb = fb;
    }
};

int main()
{

    rocketFly *rocket_fly = new rocketFly();
    wingFly *wing_fly = new wingFly() ;

    Bird *sparrow = new Bird(wing_fly);

    sparrow->fly();
    sparrow->change_strategy(rocket_fly);
    sparrow->fly();
}




