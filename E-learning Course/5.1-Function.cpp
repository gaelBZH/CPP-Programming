#include <iostream>
using namespace std;

// Write a program containing the following function: 

int whichQuarter(float x, float y);

// which for the point with the coordinates (x, y) will return the value 1..4,
// identifying one of the quarters of the coordinate system inside which this point is located.
// If the point is located on any coordinate axis, the function should return 0

//      II  | I
//      -------
//      III | IV

// The program asks the user to give the coordinates,
// calls the function and writes the number returned by the function on the screen,
// i.e. number of the system quarter.

int whichQuarter(float x, float y)
{
    if (x == 0 || y == 0)
        return 0; // On a line

    if (x < 0)
        return (y < 0) ? 3 : 2;
    else
        return (y < 0) ? 4 : 1;
}

int main()
{
    cout << "(1,2) is in part " << whichQuarter(1, 2) << ".\n";
    cout << "(-1,2) is in part " << whichQuarter(-1, 2) << ".\n";
    cout << "(-1,-2) is in part " << whichQuarter(-1, -2) << ".\n";
    cout << "(1,-2) is in part " << whichQuarter(1, -2) << ".\n";
    return 0;
}