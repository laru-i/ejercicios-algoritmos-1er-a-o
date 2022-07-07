#include <iostream>

using namespace std;

/*
Calcular e informar la sumatoria de 10 números ingresados por teclado.
*/

int main()
{
    int num, suma = 0, i;
      
    while (i <= 10)
    {
      cout << "Ingrese un número ";
      cin >> num;
      i++;
      suma = suma + num;  
    }
       
    return 0;
}