#include <iostream>

using namespace std;

/*
Confeccionar un programa que solicite dos valores reales positivos, expresados en cm. El
primero corresponde a la base y el segundo a la altura de un triángulo, se desea calcular el
valor de la superficie. Si la superficie calculada es menor a 100 cm2, expresarla en milímetros 
cuadrados, caso contrario en metros cuadrados. Informar resultado con unidades. 
( 1 m2 = 10.000 cm2)
*/

int main()
{
    float base,h,sup,mm,m;

    cout<<"Ingrese la base del triangulo en cm";
    cin>>base;

    cout<<"Ingrese la altura del triangulo en cm";
    cin>>h;
    
    sup = (base * h) / 2;

    if(sup < 100)
    {
        mm = sup * 100; 
        cout<<"la superficie es "<<mm<<"mm2"<<endl;
    }
    else
    {
        m = sup / 10000; 
        cout<<"la superficie es "<<m<<"m2"<<endl;
    }    

    return 0;
}