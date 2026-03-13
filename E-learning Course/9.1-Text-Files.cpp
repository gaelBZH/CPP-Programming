#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// This one was bad

// Write a program which will load the text file with the name given by user and will find,
// in this file, the most frequently appearing character and will write on the screen what character
// it is and how many times it occurred. 
// We consider small and capital letters as separate characters.
// Example:
// If the file contains only one line of text:
// Alice has a cat and the cat has Alice.
// The most frequently occurring character is: a and it appears 4 times.

string readTextFile(string filename)
{
    fstream file;
    string s;

    file.open(filename, ios::in);

    if (file.good())
    {
        cout << "File is opened !\n";
        string line;
        while (!file.eof())
        {
            getline(file, line);
            s = s + line;
        }
        file.close();
    }

    return s;

}

int main()
{
    string filename;
    string s;
    int nmax = 1;
    int n;
    char c;
    char cmax;

    cout << "Enter file name : ";
    cin >> filename;

    s = readTextFile(filename);
    cmax = s[0];

    for (int i = 1; i < s.length(); i++)
    {
        n = 0;
        c = s[i];
        for (int j = i; j < s.length(); j++)
            if (s[j] == c)
                n++;
        if (n > nmax)
        {
            nmax = n;
            cmax = c;
        }
    }

    cout << "The most often character is '" << cmax << "' (" << nmax << " times).\n";
    return 0;
}