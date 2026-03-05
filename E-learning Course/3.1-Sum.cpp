#include <iostream>
using namespace std;

// Write a program loading numbers given by user from the keyboard and ending when sum of all the given numbers exceeds 100.
// Use the while loop or do-while loop in the program.

int main()
{
    int sum = 0;
    while (sum < 100)
    {
        int input;
        cin >> input;
        sum += input;
    }
    
    cout << "End.";
    return 0;
}