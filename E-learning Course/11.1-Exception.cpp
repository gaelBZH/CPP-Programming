#include <iostream>
#include <string>
using namespace std;

// Write a class with the name INT
// inside the class place the following components:

string s;
int number; // public
// and public method getnumber()

// The method getnumber() loads the text string given by user,
// saving it to variable s and checks whether in the variable s there are only digits,
// if yes, then:
// - it converts the text string to the int type integer saving it to the variable number
// otherwise, the method getnumber throws the exception in the form of stringwith the inscription “it is not a number”
// in the function main, we create the object from the INT class and in
// the infinite loop we call the method getnumber. After calling this method, we write the value of the variable number.
// Inside the function main we must catch the string type exception and if it appears,
// we write the message received as the exception.

class INT
{
    private:
        string s;

    public:
        int number;

        void getnumber()
        {
            cout << "Number=";
            cin >> s;
            
            for (int i = 0; i < s.length(); i++) 
                if (s[i] < '0' || s[i] > '9') 
                    throw string("it is not a number");
            
            number = 0;
            int n = 1;
            for (int j = s.length() - 1; j >= 0; j--)
        
            {
                number += (s[j] - '0') * n;
                n *= 10;
            }
        }
};

int main()
{
    INT obj;

    while (true)
    {
        try
        {
            obj.getnumber();
            cout << "Converted value: " << obj.number << endl;
        }
        catch (string e)
        {
            cout << "Error: " << e << endl;
        }
        cout << "---" << endl;
    }

    return 0;
}