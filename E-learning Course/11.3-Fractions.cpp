#include <iostream>
#include <string>
using namespace std;

// Create the class Fraction representing the vulgar fraction. Two integers, i.e. numerator and denominator
// should be stored in the class. The variables storing the numerator and denominator should be private.
// The class should include the constructor assuming two integers (numerator and denominator) as the argument and
// the method writing the value of the fraction.
// Four operators must be overloaded in the program (+, -, *, /).
// Overloaded operators should perform arithmetic operations on two objects of the class Fraction and return the new object
// of the class Fraction storing the result of the given arithmetic operation.
// In the function main, we ask the user to give values for two fractions and we create two objects of the class Fraction.
// Next, we call the operation of adding, subtracting, multiplying and dividing.The result of each operation is saved to new objects. 
// After completion of each operation, we call the method writing the fraction.
// Please note: After completing the arithmetic operation, you do not have to reduce the fraction.


class Fraction
{
    private:
        int a;
        int b;
    public:
        Fraction(int a, int b)
        {
            this->a = a;
            this->b = b;
        }

        double getValue()
        {
            return (double)a/b;
        }

        Fraction operator+(const Fraction& other)
        {
            return Fraction(this->a*other.b + other.a*this->b, this->b *other.b);
        }

        Fraction operator-(const Fraction& other)
        {
            return Fraction(this->a*(-other.b) + other.a*this->b, this->b *(-other.b));
        }

        Fraction operator*(const Fraction& other)
        {
            return Fraction(this->a*other.a, this->b*other.b);
        }

        Fraction operator/(const Fraction& other)
        {
            return Fraction(this->a*other.b, this->b*other.a);
        }

};

int main()
{
    int a, b;
    cin >> a >> b;
    Fraction f1(a, b);
    cin >> a >> b;
    Fraction f2(a, b);

    
    cout << (f1 + f2).getValue() << endl;
    cout << (f1 - f2).getValue() << endl;
    cout << (f1 * f2).getValue() << endl;
    cout << (f1 / f2).getValue() << endl;

    return 0;
}