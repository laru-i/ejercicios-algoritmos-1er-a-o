#include <iostream>

using namespace std;

/*
Hacer un algoritmo que ingrese por teclado un número entero n y a continuación ingrese n
números más de los que tendrá que informar su promedio.
*/


int main()
{
    int i,suma = 0;
    float prom,numProm,num;

    cout<<"Ingrese un número entero ";
    cin>>num;

    while (i < num)
    {
      cout<<"Ingrese un número para promediar";
      cin >> numProm;
      i++;
      suma = suma + numProm;
 
    }
    
      prom = suma / num;
    
    cout << "El promedio es: " << prom;

    return 0;
}