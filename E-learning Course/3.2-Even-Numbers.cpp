#include <iostream>
using namespace std;

// Write a program writing 20 subsequent even numbers, starting from the number given by user. Use the for loop to do this.

int main()
{
    int input;
    cin >> input;
    if (input%2 == 1)
        input += 1;
    
    for (int i = 0; i < 20; i++)
    {
        cout << "-> " << input << endl;
        input += 2;
    }
    
    return 0;
}