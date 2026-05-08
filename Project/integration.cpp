#include <iostream>
#include <functional>
using namespace std;


// ======================= Trapezoidal Method Implementation =======================

double trapezoidalRule(function<double(double)> f, double a, double b, int n) 
{
    // Approximates the integral of f(x) from a to b using n intervals.
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1 ; i < n ; i++)
        sum += f(a + i * h);
    return sum * h;
}

// ======================= Simpson Method Implementation =======================
double simpsonsRule(function<double(double)> f, double a, double b, int n)
{
    if (n % 2 == 1)
        n++; // number of intervals must be even
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    for (int i = 1 ; i < n ; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x); // Even
        else
            sum += 4 * f(x); // Odd
    }
    return sum * h / 3.0;
}

// ======================= Adaptive Integration =======================

// Doubles the number of intervals until expected precision
double integrate(function<double(double)> f, double a, double b, double precision, bool useSimpson = true)
{
    int n = 2;
    double lastResult = 0.0;

    // Choose Method
    double currentResult = useSimpson ? simpsonsRule(f, a, b, n) : trapezoidalRule(f, a, b, n);

    // Loop while the difference between iterations is smaller than the desired precision
    while (abs(currentResult - lastResult) > precision)
    {
        n *= 2;
        lastResult = currentResult;
        currentResult = useSimpson ? simpsonsRule(f, a, b, n) : trapezoidalRule(f, a, b, n);
        
        // Security for potential infinite loop
        if (n > 1000000)
        {
            cout << "Warning: Maximum iterations reached." << endl;
            break;
        }
    }
    cout << "(n=" << n << ")" << endl;
    return currentResult;
}

