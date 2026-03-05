#include <iostream>
using namespace std;

// Write a program loading the numbers from user and save them to the two-dimensional array of integers with 3 lines and 4 columns.
// In this array, find the smallest number in each line and write it on the screen.

int main()
{
    int tab[3][4];
    for (int line = 0 ; line < 3 ; line++)
    {
        for (int col = 0 ; col < 4 ; col++)
        {
            cout << "Which number to you want for tab[" << line << "][" << col << "] ?";
            cin >> tab[line][col];
        }
    }

    for (int line = 0 ; line < 3 ; line ++)
    {
        int maxi = tab[line][0];
        for (int col = 1 ; col < 4 ; col++)
            if (tab[line][col] > maxi)
                maxi = tab[line][col];
        cout << "The maximum of line " << line << " is " << maxi << " !\n";
    }

    return 0;
}