#include <iostream>
using namespace std;

// Write a function which will assume the number of int type as the parameter and will
// return the pointer to the character arrays (char*)

// The task of the function is to convert the decimal number to the binary number.
// Individual numbers should be saved in the character array as the characters ’0’ or ’1’.
// The array should have length equal to 32 characters. 

// Create a program which will convert the decimal number given by user to the binary number,
// using the written function. After calling the function, it is necessary to write 32 characters returned by the function.

char* dec_to_binary(int a)
{
    char* tab = new char[32];

    for (int i = 31; i >= 0; i--)
    {
        tab[i] = (a&1);
        a = a >> 1;
    }

    return tab;
}

int main()
{
    int a;
    cout << "a = ";
    cin >> a;
    char* tab = dec_to_binary(a);
    
    for (int i = 0; i < 32; i++)
        cout << (int)tab[i];

    delete tab;
    return 0;
}