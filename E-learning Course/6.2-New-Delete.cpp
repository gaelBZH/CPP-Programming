#include <iostream>
using namespace std;

// Write a program in which the user gives a size of the array,

// By means of the operator new, the program reserves memory for the array with the size given by the user.
// We complete the array with the numbers given by the user.
// We write the array contents, and calculated arithmetic average of the numbers saved in the array. 
// We release memory.

int main()
{
    int n = -1;
    while (n <= 0)
    {
        cout << "Size of the array : n=";
        cin >> n;
    }

    // Init tab
    int *tab = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i << "/" << n << " (" << n-i << " remaining) : ";
        cin >> tab[i];
    }
    
    // Calculate Average and Print
    int sum = 0;
    cout << "[ ";
    for (int i = 0 ; i < n ; i++)
    {
        sum += tab[i];
        cout << tab[i] << " ";
    }
    cout << "]\n";

    float average = (float)sum/n;
    cout << "The average is " << average << ".\n";

    delete tab;
    return average;  
}