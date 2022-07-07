#include <iostream>

using namespace std;
/*
 Dados 50 valores que se ingresan por teclado, mostrar el mayor y la cantidad de veces que fue 
ingresado
*/

int main()
{
    int i, num, mayor, cant;
    
    do
    {
        cout<<"ingrese numero: ";
        cin>>num;
        

        if (i==0 || num>mayor)
        {
            mayor = num;
            cant = 1; 
        }
        else 
        {
            if (num==mayor)
               cant++;
        }
        i++;
        
    } while (i<5);

    cout<<"el numero mas grande es: "<<mayor<<" y se ingreso "<<cant<<"veces";
    

    
    return 0;
}
