#include <iostream>

using namespace std;

/*

Desarrollar un algoritmo que permita ingresar un conjunto de valores, cada uno de los cuales 
representa el sueldo de un empleado (se sabe que un sueldo igual a 0 indica el fin del conjunto), e 
informe:
a) Cuántos empleados ganan menos de $900
b) Cuántos ganan $900 o más, pero menos de $1200
c) Cuántos ganan $1200 o más, pero menos de $2000
d) Cuántos ganan $2000 o más

*/

int main()
{
    int sueldo, i = 0,uno = 0,dos = 0,tres = 0,cuat = 0;

    cout<<"ingrese su sueldo (cero para finalizar): ";
    cin>>sueldo;

    while (sueldo != 0)
    {
    cout<<"ingrese su sueldo: ";
    cin>>sueldo;
    i++;

    if(sueldo < 900) 
    {
        uno++;
    }
    if(sueldo > 900 && sueldo < 1200) 
    {
        dos++;
    }
    if(sueldo > 1200 && sueldo < 2000)
    {
        tres++;
    }
    if(sueldo > 2000)
    {
        cuat++;
    }

    }
    cout<<uno<<" ganan menos de 900"<<endl;
    cout<<dos<<" ganan entre 900 y 1200"<<endl;
    cout<<tres<<" ganan entre 1200 y 2000"<<endl;
    cout<<cuat<<" ganan mas de 2000"<<endl;
    
return 0;
}
