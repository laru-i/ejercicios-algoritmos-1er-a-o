#include <iostream>
using namespace std;

/* Desarrollar la función porcentaje que dados los parámetros a y b devuelva el porcentaje que 
representa a sobre b. */

int porcentaje(int,int);

int main()
{
    int n1, n2;

    cout<<"ingrese dos numeros: ";
    cin>>n1>>n2;
    
    cout<<"el porcentaje de el primer numero sobre el segundo es: "<<porcentaje(n1,n2)<<"%";

       
    return 0;
}

int porcentaje(int a, int b){
    float porcentaje;
    porcentaje = (a * b) / 100;
    return porcentaje;
}