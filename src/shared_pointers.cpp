#include <iostream>
#include <memory>

class MyClass {
public:
    int var;


    MyClass() {

        std::cout << "MyClass created" << std::endl;
        var = 30;
    }

    void print_class_name()
    {
        std::cout << "This is the class name" << std::endl;
    }


    ~MyClass() {
        std::cout << "~MyClass destroyed" << std::endl;
    }
};

void foo (const std::shared_ptr<MyClass> ptr)
{
    ptr->print_class_name();
    ptr->var = 4332;
}

int main() {
    // Create a shared_ptr to an instance of MyClass
    std::shared_ptr<MyClass> myClassPtr(new MyClass());

    // Use the shared_ptr to access the instance of MyClass
    std::cout << "Accessing MyClass through shared_ptr" << std::endl;

    std::cout << "print internal var " << myClassPtr->var <<std::endl;
    // Create another shared_ptr that points to the same instance of MyClass
    std::shared_ptr<MyClass> myClassPtr2 = myClassPtr;

    myClassPtr2->var = 22;
    std::cout << "print internal var " << myClassPtr->var <<std::endl;
    std::cout << "print internal var " << myClassPtr2->var <<std::endl;

    // The reference count of the shared_ptr is now 2
    std::cout << "Reference count: " << myClassPtr.use_count() << std::endl;
    foo(myClassPtr2);

    std::cout << "print internal var " << myClassPtr->var <<std::endl;
    std::cout << "print internal var " << myClassPtr2->var <<std::endl;

    std::cout << "Reference count: " << myClassPtr.use_count() << std::endl;
    // The instance of MyClass will be destroyed when the last shared_ptr referencing it is destroyed
    return 0;
}