#include <iostream>

using namespace std;

int main(){
    int a,b;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "Enter + - * or / : ";
    char c;
    cin >> c;

    int res;
    switch (c)
    {
        
    case '+':
        res = a + b;
        cout << "The sum of a and b is " << res << ".\n";
        break;
    case '-':
        res = a - b;
        cout << "The substraction of a and b is " << res << ".\n";
        break;
    case '*':
        res = a * b;
        cout << "The product of a and b is " << res << ".\n";
        break;
    case '/':
        if (b == 0)
            cout << "You can't divide by 0 !";
        else
        {
            res = a / b;
            cout << "The division of a and b is " << res << ".\n";
        }
        break;
    default:
        cout << c << " is not a valid operator.";
        break;
    }

    return 0;
}