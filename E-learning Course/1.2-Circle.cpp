#include <iostream>

using namespace std;

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