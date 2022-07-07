#include <iostream>

using namespace std;

/*
 Dados tres valores que se ingresan por teclado, mostrar por pantalla el valor mayor.
*/

int main()
{
    int n1,n2,n3;

    cout<<"Ingrese tres valores ";
    cin>>n1>>n2>>n3;
    
    if(n1>n2 && n1>n3)
    {
        cout<<"el mayor es "<<n1<<endl;
    }
    if(n2>n3)
    {
        cout<<"el mayor es "<<n2<<endl;
    }
    else 
        cout<<"el mayor es "<<n3<<endl;     

    return 0;
}