
/**
 * The loss of type and dimensions of an array is known as decay of an array.
 * This generally occurs when we pass the array into function by value or pointer.
 * What it does is, it sends first address to the array which is a pointer,
 * hence the size of array is not the original one,
 * but the one occupied by the pointer in the memory.
 */

// C++ code to demonstrate array decay
#include <iostream>
using namespace std;

// Driver function to show Array decay
// Passing array by value
void aDecay(int *p)
{
    // Printing size of pointer
    cout << "Modified size of array is by "
            " passing by value: ";
    cout << sizeof(p) << endl;
}

// Function to show that array decay happens
// even if we use pointer
void pDecay(int (*p)[7])
{
    // Printing size of array
    cout << "Modified size of array by "
            "passing by pointer: ";
    cout << sizeof(p) << endl;
}

int main()
{
    int a[7] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
    };
    int b = 10;
    cout << "size of int: " << sizeof(b) << endl;
    // Printing original size of array
    cout << "Actual size of array is: ";
    cout << sizeof(a) << endl;

    // Passing a pointer to array
    aDecay(a);

    // Calling function by pointer
    pDecay(&a);

    return 0;
}