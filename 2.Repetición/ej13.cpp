#include <iostream>

using namespace std;

/*

Hacer un algoritmo que calcule el promedio de números enteros positivos ingresados por teclado 
hasta que se ingrese un cero. Este cero sólo indica el fin de ingreso de datos, no se incluirá en el 
promedio.

*/

int main()
{
    int num, suma, i = 0;
    float prom;

    cout<<"ingrese un numero entero positivo (cero para finalizar): ";
    cin>>num;

    while (num != 0)
    {
    suma += num;
    cout<<"ingrese numeros enteros positivos: ";
    cin>>num;
    i++;
    }

    if(i != 0) {
        prom =  (float)suma/i;
        cout<<"el promedio es: "<<prom;
    }
    else {
        cout<<"no se ingresaron valores ";
    }
    
    
return 0;
}
