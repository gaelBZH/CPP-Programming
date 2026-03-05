#include <iostream>

// This is my first programm in C++ !

using namespace std;

// Write a program which will load two numbers entered by user. Next, perform the operations: addition, subtraction, multiplication and division of the given numbers. After carrying out each operation, write its result.

int main(){
    int a,b;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    int sum = a + b;
    cout << "The sum of a and b is " << sum << ".\n";
    
    int sub = a - b;
    cout << "The substraction of a and b is " << sub << ".\n";

    int prod = a * b;
    cout << "The product of a and b is " << prod << ".\n";

    if (b == 0)
    {
        cout << "You can't divide by 0 !";
    }
    else
    {
        int div = a / b;
        cout << "The division of a and b is " << div << ".\n";
    }
    
    return 0;
}