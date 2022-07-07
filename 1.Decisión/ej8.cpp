#include <iostream>

using namespace std;

/*
Dados tres valores que representan los lados de un triángulo, informar si el mismo es
equilátero, isósceles o escaleno.

*/


int main()
{
    float l1,l2,l3;

    cout<<"Ingrese los tres lados de un triángulo ";
    cin>>l1>>l2>>l3;

    if (l1 == l2 && l2 == l3)
    {
        cout<<"El triangulo es equilatero"<<endl;
    }

    if (l1 != l2 && l2 != l3)
    {       
        cout<<"El triángulo es escaleno"<<endl;   
    }

    if (l1 == l2 && l2 != l3)
    {       
        cout<<"El triángulo es isoceles"<<endl;   
    }
       

    return 0;

}