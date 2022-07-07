#include <iostream>

using namespace std;

/*
Dado un número entero positivo entre 1 y 3999 informar su correspondiente número Romano
*/

/* FALTA TERMINAR */

int main()
{
    int num,primerCifra, segundaCifra, tercerCifra, cuartaCifra; 

    cout<<"Ingrese un número entero entre 1 y 3999 ";
    cin>>num;

    primerCifra = num / 10000;

    segundaCifra = (num - (primerCifra * 10000)) / 1000;

    tercerCifra = (num - (primerCifra * 10000) - (segundaCifra * 1000)) / 100;

    cuartaCifra = (num - (primerCifra * 10000) - (segundaCifra * 1000) - (tercerCifra * 100)) / 10;

    if ()
    {
      /* code */
    }
    
   

    return 0;
}