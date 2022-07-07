#include <iostream>
using namespace std;

/*  Desarrollar una función que dados el día, el mes y el año de una fecha correcta, devuelva la 
misma en formato de entero de 8 dígitos con el formato AAAAMMDD.

*/
int fecha(int, int, int);

int main()
{
    int dia, mes, ano;
    do
    {
        
    cout<<"ingrese un dia ";
    cin>>dia;
    cout<<"ingrese un mes ";
    cin>>mes;
    cout<<"ingrese un ano ";
    cin>>ano;
         
    } while (dia > 31 || dia < 1 || mes > 12 || mes < 1);

    cout<<fecha(dia, mes, ano);
    
    return 0;
}
int fecha(int dia, int mes, int ano){

    return ano * 1000 + mes * 100 + dia;
    
}