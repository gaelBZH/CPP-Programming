#include <iostream>
#include <string>
using namespace std;

struct Commodity
{
    string name;
    int price;
};

int main()
{
    Commodity T[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "What's the name of Commodity " << i << " ? ";
        cin >> T[i].name;
        cout << "What's it's price ? ";
        cin >> T[i].price;
    }

    for (int i = 0 ; i < 10; i++)
        cout << "Commodity n°" << i << " (" << T[i].name << ") costs " << T[i].price << " PLN.\n";
    
    return 0;
}