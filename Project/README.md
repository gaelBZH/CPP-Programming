# Numerical Integration Tool

This project provides a C++ implementation of numerical integration using the **Trapezoidal Rule**
and **Simpson’s Rule**. It provides an adaptive algorithm that iteratively doubles the number of
intervals until a user-given precision target is achieved. It is designed to evaluate both standard
test functions and custom mathematical functions.

**Author:** Gaël KERNINON  
**University:** Cracow University of Technology, Poland  
**Date:** May 26, 2026

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/330px-ISO_C%2B%2B_Logo.svg.png" width="100px" style="padding: 5px 10px"></img>

---

## Project Architecture ⚙️

The project is organized into three main files to maintain modularity :

```
Project/
├── main.cpp              # Main program with test functions and user interface
├── integration.cpp       # Numerical integration algorithms (Trapezoidal & Simpson's)
├── givenfunction.cpp     # Custom function to integrate
├── report.pdf
└── README.md
```

## Compilation and Execution 💻
Open your terminal or command prompt, navigate to the directory containing the project files,
and compile `main.cpp` with your compiler. Because `main.cpp` includes the other `.cpp` files directly
via `#include`, you only need to compile the main file:

```bash
# Compile with your Compiler (c++, g++, ...)
c++ main.cpp -o numerical_integration

# Run
./numerical_integration      # Linux/MacOS
.\numerical_integration.exe  # Windows 11 (PowerShell)
```

### Running the Program

When you run the program, you'll see the following prompt:

```
================ Numerical Integration Tester ================
Enter integration interval [a,b]:
a = 0
b = 3.14159
Enter desired precision (e.g., 1e-6): 1e-6
==============================================================
```

### Input Parameters

| Parameter | Description | Example |
|-----------|-------------|---------|
| **a** | Lower bound of integration interval | 0 |
| **b** | Upper bound of integration interval | 3.14159 |
| **precision** | Desired accuracy (smaller = more accurate) | 1e-6 (0.000001) |

### Output

The program performs three sequential tests:

#### Test 1 and 2 : f(x) = x² and f(x) = sin(x)
```
=========================== Test 1 ===========================
Integrating f(x) = x^2 on [1,5]
Exact Analytical Solution : 41.3333

Trapezoidal Rule Result   : Value = 41.3333 | Error = 1.58946e-07

Simpson's Rule Result     : Value = 41.3333 | Error = 7.10543e-15
==============================================================
```

- **Exact Analytical Solution**: The true integral value calculated mathematically with the antiderivative.
- **Value**: The numerical approximation computed by the algorithm
- **Error**: The absolute difference $|exact - approximation|$
- Number of intervals (`n`) used to achieve the desired precision

#### Custom Function: f(x) = cos(x) + x³
```
=========================== Given Function ===========================
Integrating given function f(x) on [1,5]
Trapezoidal Rule Result   : Value = 154.2

Simpson's Rule Result     : Value = 154.2
======================================================================
```

No analytical solution is provided for the custom function, only the numerical results.

## Customization 💡

### Changing the Custom Function

Edit `givenfunction.cpp` to integrate a different function:

```cpp
#include <cmath>

// Current function: f(x) = cos(x) + x^3
double f(double x) { return cos(x) + x*x*x; }
```

**Examples of other functions:**

```cpp
// Exponential function
double f(double x) { return exp(x); }

// Polynomial
double f(double x) { return x*x*x - 2*x*x + x + 1; }

// Rational function
double f(double x) { return 1.0 / (1.0 + x*x); }

// Trigonometric
double f(double x) { return sin(x) * cos(x); }
```

## Additionnal Informations ℹ️
For more informations, please take a look at `report.pdf`.