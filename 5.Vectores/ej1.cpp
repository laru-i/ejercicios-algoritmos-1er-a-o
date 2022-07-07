#include <iostream>

using namespace std;

/*
 Hacer un algoritmo que lea 30 notas las cargue un vector y luego muestre la nota máxima
*/

int main()
{
    int i, nota[10], notaMax = 0;

    while (i < 10)
    {
        cout << "ingrese una nota: ";
        cin >> nota[i];

        if (notaMax < nota[i])
        {
            notaMax = nota[i];
        }
        i++;
    }
    cout << "la nota máxima es " << notaMax;

    return 0;
}

/*

int recorrer (int a[])
{
    for (int i = 0; i < 10; i++)
    {
        a[i];

    }

}*/
