#include <iostream>

using namespace std;

/*
 Escriba un programa que permita ingresar la tirada de un par de dados 50 veces y muestre una lista
donde se vea cuántas veces se dio cada uno de los resultados posibles. Por cada tirada se deberán
ingresar 2 valores, cada uno representa el valor de un dado. El formato de la salida debe ser el
siguiente:
2 salió ... veces
3 salió ... veces
.
.
12 salió ... veces

*/
int main()
{

    int i, dado1, dado2, res[5], veces;

    while (i < 5)
    {
        cout << "ingrese los valores de los dados " << endl;
        cin >> dado1 >> dado2;
        res[i] = dado1 + dado2;
        i++;
    }

    for (int j = 2; j <= 12; j++)
    {
        veces = 0;
        for (i = 0; i < 5; i++)
        {
            if (res[i] == j)
                veces++;
        }
        cout << j << " salio " << veces << endl;
    }
}

/*
int main()
{
    int i, dado1, dado2, resultado[5], veces;

    //lleno el vector
    while (i<5)
    {
        cout << "Ingrese el valor de los dados: ";
        cin >> dado1 >> dado2;

        resultado[i] = dado1 + dado2;

        i++;
    }

    //recorres posibles valores para ver los repetidos
    for (int i = 2; i <= 12; i++)
    {
        veces = 0;
        for (int j = 0; j < 5; j++)
        {
          if (resultado[j] == i)
          veces++;
        }
        cout<< i << " salio " << veces << endl;
    }

    return 0;

}
*/

