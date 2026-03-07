#include <iostream>
using namespace std;

// This one was more difficult

// Write a function which assumes: pointer for the character array as the parameters.
// The task of the function is to liquidate all the same characters in the array occurred many times.
// Save the characters which do not repeat to a new array.
// The function should return the pointer for the new character array as the result.
// We assume that the maximum size of the character array is 100.
// In the function main, we load the string of characters and call the written function.
// Next, we write the inscription returned by the function.
// Example: 
// input string: Allice has a cattt
// output string: Alice has a cat.
// Please remember that the character string ends with zero.


int main()
{
    // Input
    char* input = new char[100];
    cin.getline(input, 100);

    // Parse
    char* output = new char[100];
    int index = 0;
    int i = 0;
    while (input[i] != 0 && i < 99)
    {
        if (input[i] != input[i+1])
            output[index++] = input[i];
        i = i+1;
    }
    output[index] = '\0';
    
    // Print
    cout << output;

    // Free
    delete input, output;
    return 0;
}