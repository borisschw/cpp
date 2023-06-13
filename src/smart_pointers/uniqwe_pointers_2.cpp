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

int main() {
    // Create a unique_ptr to an instance of MyClass
    std::unique_ptr<MyClass> myClassPtr(new MyClass());
    std::unique_ptr<MyClass> myClassPtr2;
    myClassPtr->var = 40;
    std::cout << "address = " << myClassPtr.get() <<std::endl;
    // Use the unique_ptr to access the instance of MyClass
    std::cout << "Accessing MyClass through unique_ptr" << std::endl;
    std::cout << "print internal var " << myClassPtr->var <<std::endl;

    // We cannot create another unique_ptr that points to the same instance of MyClass,
    // because unique_ptr does not allow multiple owners
    //std::unique_ptr<MyClass> myClassPtr2 = myClassPtr; // This line would cause a compile error

    // We can transfer ownership of the unique_ptr to another function by using std::move
    std::unique_ptr<MyClass> transferOwnership(std::unique_ptr<MyClass> ptr);
    myClassPtr2 = transferOwnership(std::move(myClassPtr));
    std::cout << "address 2 = " << myClassPtr2.get() <<std::endl;
    std::cout << "print internal var " << myClassPtr2->var <<std::endl;
    // After the unique_ptr has been moved, it is no longer pointing to anything
    if (myClassPtr == nullptr) {
        std::cout << "myClassPtr is null" << std::endl;
    }

    return 0;
}

std::unique_ptr<MyClass> transferOwnership(std::unique_ptr<MyClass> ptr) {


    std::cout << "Transfering ownership of MyClass to transferOwnership()" << std::endl;
    ptr->var = 50;
    std::cout << "address 2 = " << ptr.get() <<std::endl;
    std::cout << "print internal var " << ptr->var <<std::endl;
    return ptr;
    // do something with ptr
}
