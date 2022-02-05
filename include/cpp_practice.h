#ifndef __CPP_PRACTICE__
#define __CPP_PRACTICE__

#define NAME_SIZE 50

class Person{

    public:
    int id = 123;
    virtual void about_me();

    Person()
    {}

    Person(int a): id(a)
    {}

    private:
    char name[NAME_SIZE];
};
class Student: public Person{
    public:
    void about_me();
};

class Teacher: public Person{
    public:
    void about_me();
};


#endif
