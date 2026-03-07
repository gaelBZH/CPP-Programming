#include <iostream>
using namespace std;

// Write a program which will include two int type variables (e.g. with the names a and b)

// and two int type pointers.

// Assign address of a different variable to each of the pointers.
// Using the pointer, save the number given by user to the first variable.
// To the second variable, using the pointer too, save the number bigger by 10
// that the first number (given by user in step 2).

// Write values of the variables a and b.
// Write values saved in memory, using the pointers.

int main()
{
    int a;
    int b;
    int* p1 = &a;
    int* p2 = &b;

    cout << "Setting a=";
    cin >> a;
    b = a + 10;

    cout << "The values are a=" << a << " et b=" << b << ".\n";

    cout << "a's address is " << p1 << endl;
    cout << "b's address is " << p2 << endl;

    return 0;
}