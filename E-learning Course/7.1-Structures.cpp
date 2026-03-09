#include <iostream>
using namespace std;

// Define the structure (struct Triangle) storing length of sides of the triangle.
// 
// Write the function perimeter which obtains the struct Triangle type variable
// as the parameter and returns the triangle perimeter as the value.
// (perimeter of the triangle formula: Ob=a+b+c, where a,b,c - is length of sides of the triangle).
// 
// In the function main, create the variable of the type (struct Triangle),
// load 3 numbers given by user. Save them in the created variable of the struct Triangle type.
// 
// Call the written function perimeter and write the result returned by the function

struct Triangle{
    int a,b,c;
};

int perimeter(Triangle t)
{
    return t.a + t.b + t.c;
}

int main()
{
    int a,b,c;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;
    Triangle t = {a,b,c};
    int p = perimeter(t);
    cout << "Le perimetre du triangle est " << p << ".\n";

    return 0;
}