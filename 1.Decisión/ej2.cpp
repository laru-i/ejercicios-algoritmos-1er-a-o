#include <iostream>

using namespace std;

/*
Informar si un número es par o impar
*/

int main()
{
    int nro,resto;
    cout<<"Ingrese un numero ";
    cin>>nro;
    resto=nro%2;
    //if(resto==0)
    if(nro%2==0)
    {
        cout<<"PAR"<<endl;
    }
    else
        cout<<"IMPAR"<<endl;
    return 0;
}
