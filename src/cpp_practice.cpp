#include <iostream>
#include "cpp_practice.h"

using namespace std;

void Person::about_me()
{
    cout<<"Person my id is "<< id<<"\n";
}

void Student::about_me()
{
    cout<<"Student my id is "<< id<<"\n";
}

void Teacher::about_me()
{
    cout<<"Teacher my id is "<< id<<"\n";
}

int main()
{
    Student* student1 = new Student();
    Person* person1 = new Person(555);
    student1->about_me();
    person1->about_me();

    if(student1)
        delete student1;

    return 0;
}