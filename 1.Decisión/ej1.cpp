#include <iostream>

using namespace std;

/*
Dados dos valores que se ingresan por teclado, mostrar por pantalla el menor de ellos
*/

int main()
{
    int nro1,nro2;
    cout<<"Ingrese dos numeros ";
    cin>>nro1>>nro2;
    
    if(nro1 < nro2)
    {
        cout<<nro1<<" es el menor"<<endl;
    }
    else
        cout<<nro2<<" es el menor"<<endl;

    return 0;
}