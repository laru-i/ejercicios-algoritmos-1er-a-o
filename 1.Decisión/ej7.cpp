#include <iostream>

using namespace std;

/*
Dado tres valores que representan las longitudes de segmentos determinar e imprimir una
leyenda según sea: “Forman triangulo” o “No forman triangulo”.

*/

int main()
{
    float l1,l2,l3;

    cout<<"Ingrese tres longitudes ";
    cin>>l1>>l2>>l3;

    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1)
    {
        cout<<"Forman triangulo"<<endl;
    }

    else 
        cout<<"No forman triangulo"<<endl;     

    return 0;

}