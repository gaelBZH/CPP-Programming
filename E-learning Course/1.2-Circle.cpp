#include <iostream>
using namespace std;

// Write a program which will load length of a radius given by user. Next, it will calculate and write the area and perimeter of a circle.

int main(){

    double radius;
    double PI = 3.14;
    cout << "Please enter the radius of the circle : ";
    cin >> radius;

    double perimeter = 2 * PI * radius;
    double area = PI * radius * radius;

    cout << "The radius of the circle is " << radius << ".\n";
    cout << "The perimeter of the circle is " << perimeter << ".\n";
    cout << "The area of the circle is " << area << ".\n";
    return 0;
}