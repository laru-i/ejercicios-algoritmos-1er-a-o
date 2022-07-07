#include <iostream>

using namespace std;

/*
 Hacer un algoritmo que lea 40 números y los muestre en orden inverso.
*/

int main()
{
    int v[4];

    for (int j = 0; j < 4; j++)
    {
        cout << "ingrese un numero ";
        cin >> v[j];
    }

    for (int i = 3; i >= 0; i--)
    {
        cout << v[i];
    }

    return 0;
}

/*
 Hacer un algoritmo que lea 40 números y los muestre en orden inverso.

int main()
{
    int i, num[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "ingrese un nro: ";
        cin >> num[i];
    }

    for (int j = 2; j >= 0; j--)
    {
        cout << num[j];
    }

return 0;

}

*/
