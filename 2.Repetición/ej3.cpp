
#include <iostream>

using namespace std;

/*
Informar los primeros n números pares positivos, siendo n un número entero positivo ingresado 
por teclado.
*/

int main()
{
    int num;

    cout << "Ingrese un numero entero positivo ";
    cin >> num;
    
    for (int i = 1; i <= num * 2; i++)
    {
      if (i % 2 == 0)
        cout << i << " ";
    }
       
    return 0;
}