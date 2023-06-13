// #include <iostream>
// #include <functional>

// //std::function object that takes an int parameter and returns void
// void doSomething(int y, std::function<void(int)> callback) {
//     std::cout << "Doing something with " << y << "...\n";
//     callback(y);
// }

// int main() {
//     int myVar = 42;


//     doSomething(10, [myVar](int j){
//     std::cout << "Callback function called with x=" << j
//                 << " and myVar=" << myVar << "\n";
//     });

//     return 0;
// }



#include <iostream>

int main() {

    int blabla = 42;
  // Define a lambda function that takes two integer parameters and returns their sum
  auto add = [&blabla](int x, int y) -> int {
    blabla ++;
    return x + y + blabla;


  };

  // Call the lambda function with arguments 2 and 3
  int result = add(2, 3);
  std::cout << blabla <<std::endl;
  // Print the result
  std::cout << "The result is: " << result << "\n";

  return 0;
}