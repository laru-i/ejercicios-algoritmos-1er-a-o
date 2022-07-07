#include <iostream>

using namespace std;

/*
Dados n y m enteros positivos, informar su producto obtenido por sumas sucesivas
*/

int main()
{
    int nro1, nro2, res;

cout<<"ingrese 2 numeros enteros: "<<endl;
cin>>nro1>>nro2;

    for (int i = 0; i < nro1; i++)
    {
        res += nro2; 
    }

cout<<"el producto es "<<res;
    
return 0;
}