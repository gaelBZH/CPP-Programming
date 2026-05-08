#include <iostream>
#include "integration.cpp"
#include <cmath>

// --- Test Functions and Analytical Solutions ---
double testFunc1(double x) { return x * x; } // f(x) = x^2
double exactFunc1(double a, double b) { return (pow(b, 3) / 3.0) - (pow(a, 3) / 3.0); }

double testFunc2(double x) { return sin(x); } // f(x) = sin(x)
double exactFunc2(double a, double b) { return -cos(b) - (-cos(a)); }

int main()
{
    double a;
    double b;
    double precision;
    
    cout << "================ Numerical Integration Tester ================" << endl;
    cout << "Enter integration interval [a,b]:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Enter desired precision (e.g., 1e-6): "; cin >> precision;
    cout << "==============================================================" << endl << endl << endl;
    
    // Test 1: f(x) = x^2
    cout << "=========================== Test 1 ===========================" << endl;
    cout << "Integrating f(x) = x^2 on [" << a << "," << b << "]" << endl;
    double exact1 = exactFunc1(a, b);
    cout << "Exact Analytical Solution : " << exact1 << endl << endl;
    
    cout << "Trapezoidal Rule Result   : ";
    double trap1 = integrate(testFunc1, a, b, precision, false);
    cout << "\tValue = " << trap1 << "\t | Error = " << abs(exact1 - trap1) << endl << endl;
    
    cout << "Simpson's Rule Result     : ";
    double simp1 = integrate(testFunc1, a, b, precision, true);
    cout << "\tValue = " << simp1 << "\t | Error = " << abs(exact1 - simp1) << endl;
    cout << "==============================================================" << endl << endl << endl;
    
    // Test 2: f(x) = sin(x)
    cout << "=========================== Test 2 ===========================" << endl;
    cout << "Integrating f(x) = sin(x) on [" << a << "," << b << "]" << endl;
    double exact2 = exactFunc2(a, b);
    cout << "Exact Analytical Solution : " << exact2 << endl << endl;
    
    cout << "Trapezoidal Rule Result   : ";
    double trap2 = integrate(testFunc2, a, b, precision, false);
    cout << "\tValue = " << trap2 << "\t | Error = " << abs(exact2 - trap2) << endl << endl;
    
    cout << "Simpson's Rule Result     : ";
    double simp2 = integrate(testFunc2, a, b, precision, true);
    cout << "\tValue = " << simp2 << "\t | Error = " << abs(exact2 - simp2) << endl;
    cout << "==============================================================" << endl << endl << endl;

    return 0;
}