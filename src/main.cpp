// #include <iostream>
// #include "..\include\vector.h"

// using namespace std;

// // double sqrt(double);



// // Vector::operator[](int i)// definition of subscripting
// // {
// //     return elem[i];
// // }

// // Vector::Vector(int s)// definition of the constructor
// //     :elem{new double[s]},sz{s}// initialize members
// // {

// // }
// // Vector::size()
// // {
// //     return sz;
// // }


// int main()
// {
//     int v[] = {0,1,2,3,4,5,6,7,8,9};

//     /*
//     for every element of v, from the first to the last, place
//     a copy in x and print it.
//     */
//     for (auto x : v) // add 1 to each x in v
//     {
//         ++x;
//         cout << x << endl;
//     }


//     /*
//     If we didn’t want to copy the values from v into the variable x, but rather just have x refer to an
//     element, we could write:
//     */
//     for (auto &x : v) // add 1 to each x in v
//     {
//         ++x;
//         cout << x << endl;
//     }
// }



// CPP code for bubble sort
// using template function
#include <iostream>
using namespace std;

// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T, class U>
void bubbleSort(T a[], U n) {
    cout << a[1];
    cout<< "\n";
    cout << n;
}

// Driver Code
int main() {
    int a[5] = {10, 50, 30, 40, 20};
    char ch = 'a';
    int n = sizeof(a) / sizeof(a[0]);

    // calls template function
    bubbleSort<int,char>(a, ch);

  return 0;
}