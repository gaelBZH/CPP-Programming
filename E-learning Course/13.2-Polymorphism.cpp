#include <iostream>

using namespace std;

class Quadrangle
{
    protected:
        int a, b, c, d;

    public:
        Quadrangle(int s1, int s2, int s3, int s4) : a(s1), b(s2), c(s3), d(s4) {}

        void write()
        {
            cout << "(Quadrangle) : " << a << ", " << b << ", " << c << ", " << d << "\n";
        }

        virtual int Area() = 0;
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(int w1, int w2) : Quadrangle(w1, w2, w1, w2) {}

    void dimensions(int w1, int w2)
    {
        a = c = w1;
        b = d = w2;
    }

    int Area()
    {
        return a * b;
    }
};

class Square : public Quadrangle
{
public:
    Square(int w) : Quadrangle(w, w, w, w) {}

    void dimension(int w)
    {
        a = b = c = d = w;
    }

    int Area()
    {
        return a * a;
    }
};

int main()
{
    Quadrangle* q = nullptr;
    int input1, input2;

    cout << "Enter 1 number for square : ";
    cin >> input1;
    q = new Square(input1);
    cout << "Square ";
    q->write();
    cout << "Area of Square: " << q->Area() << "\n";


    cout << "--------------------------\n";


    cout << "Enter 2 numbers for rectangle : ";
    cin >> input1 >> input2;
    q = new Rectangle(input1, input2);
    cout << "Rectangle ";
    q->write();
    cout << "Area of Rectangle: " << q->Area() << "\n";

    return 0;
}