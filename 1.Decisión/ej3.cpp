#include <iostream>

using namespace std;

/*
Se ingresan dos valores por teclado si el primero es mayor al segundo, informar la resta de los
valores, en caso contrario la suma
*/

int main()
{
    int nro1,nro2,suma,resta;
    cout<<"Ingrese dos numeros ";
    cin>>nro1>>nro2;
    
    if(nro1 > nro2)
    {
        resta = nro1 - nro2;
        cout<<resta<<endl;
    }
    else
        suma = nro1 + nro2;
        cout<<suma<<endl;

    return 0;
}