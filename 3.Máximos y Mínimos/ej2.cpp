#include <iostream>

using namespace std;

/*
Dados 50 valores distintos que se ingresan por teclado, mostrar en qué posición se ingresó el 
mayor
*/

int main()
{
    int i, num, mayor, pos;
    
    do
    {
        cout<<"ingrese numero: ";
        cin>>num;

        if (i==0 || num>mayor)
        {
            mayor = num;
            pos = i + 1;
        }
        i++;
        
    } while (i<5);
    cout<<"el número más grande es: "<<mayor<<" y se ingreso en la posición "<<pos;
    
    
    return 0;
}
