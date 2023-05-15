#include <iostream>
#include <functional>
/**
 * @brief
 *  In this example, we have a Delegate class that can be used to delegate work to a callback function.
 * The SetCallback() method takes a std::function object as a parameter, which can be used to set the callback function.
 * The Execute() method can then be called to execute the callback function.
 * We also have a MyClass class that has a method called DoSomething().
 *
 * In main(), we create an instance of MyClass called obj, and a Delegate instance called del. We then set the callback function
 * for del using a lambda expression that calls obj.DoSomething().
 * Finally, we call del.Execute() to execute the callback function. This will call obj.DoSomething(),
 * and print the message "MyClass::DoSomething() called" to the console.
 *  This example demonstrates how the delegate design pattern can be used to allow an object to delegate
 * work to a callback function, without having to know anything about the implementation of the callback function.
 * The Delegate class provides a generic way to set and execute the callback function, and the MyClass class can use the Delegate to delegate work to a callback function without having to know anything about the implementation of the callback function.
 */
class Delegate {
public:
    //std::function returns void and take no params,
    void SetCallback(std::function<void()> callback) {
        m_Callback = callback;
    }

    void Execute() {
        if (m_Callback) {
            m_Callback();
        }
    }

private:
    std::function<void()> m_Callback;
};

class MyClass {
public:
    void DoSomething() {
        std::cout << "MyClass::DoSomething() called" << std::endl;
    }
};

int main() {
    MyClass obj;   //Do the work
    Delegate del;  //

    del.SetCallback([&obj](){
        obj.DoSomething();
        });

    std::cout << "Calling Delegate::Execute()" << std::endl;

    del.Execute();

    return 0;
}