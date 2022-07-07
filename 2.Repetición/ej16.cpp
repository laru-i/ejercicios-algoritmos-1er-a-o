#include <iostream>

using namespace std;

/* 
Hacer un algoritmo que calcule e informe el factorial de números positivos ingresados por teclado. 
El lote de números finaliza con cero
*/

int main()
{
    int num, i = 0, factorial = 1;

    do
    {
        cout<<"ingrese un numero: ";
        cin>>num;
        i++;
        factorial = 1;

        for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
        
         cout<<"el factorial es: "<<factorial;
         
    } while (num != 0);

   


    return 0;
}
