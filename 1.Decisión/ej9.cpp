#include <iostream>

using namespace std;

/*
Dado un número de cinco cifras informar si es capicúa
*/

int main()
{
    int num,primerCifra, segundaCifra, tercerCifra, cuartaCifra,quintaCifra; 
;

    cout<<"Ingrese un numero de 5 cifras ";
    cin>>num;

    primerCifra = num / 10000;

    segundaCifra = (num - (primerCifra * 10000)) / 1000;

    tercerCifra = (num - (primerCifra * 10000) - (segundaCifra * 1000)) / 100;

    cuartaCifra = (num - (primerCifra * 10000) - (segundaCifra * 1000) - (tercerCifra * 100)) / 10;

    quintaCifra = (num - (primerCifra * 10000) - (segundaCifra * 1000) - (tercerCifra * 100) - (cuartaCifra * 10));

    if (primerCifra == quintaCifra && segundaCifra == cuartaCifra)
    {
        cout<<"Es capicua"<<endl;
    }
    else
        cout<<"no es capicua"<<endl;


    return 0;

}