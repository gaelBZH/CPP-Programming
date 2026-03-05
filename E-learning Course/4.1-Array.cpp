#include <iostream>
using namespace std;

// Write a program which will fill a one-dimensional array with the size 20
// with the numbers given by user.
// Next, the program should ask the user to give the number which will be sought.
// In the for loop, check and write how many times the given number exists in the array.

int main()
{
    int tab[20];
    for (int i = 0; i < 20; i++)
    {
        cin >> tab[i];
    }

    cout << "Quel nombre souhaitez vous chercher ? ";
    int input;
    cin >> input;
    int res = 0;
    for (int i = 0 ; i < 20 ; i++)
    {
        if (tab[i] == input)
            res++;
    }

    cout << "Le nombre '" << input << "' est present " << res << "fois dans le tableau\n";
    return 0;
}