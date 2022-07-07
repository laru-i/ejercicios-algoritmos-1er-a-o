#include <iostream>

using namespace std;

/*
Escribir un algoritmo que lea dos fechas (día, mes y año) e informe cual es la más reciente
*/

int main()
{
    int dia1,mes1,ano1,dia2,mes2,ano2,diaA = 04, mesA = 05, anoA = 2022,fecha1,fecha2,fechaA;

    cout<<"Ingrese una fecha en formato dd/mm/aaaa ";
    cin>>dia1>>mes1>>ano1;

    cout<<"Ingrese otra fecha en formato dd/mm/aaaa ";
    cin>>dia2>>mes2>>ano2;


    fecha1 = (ano1 * 10000) + (mes1 * 100) + dia1;
    fecha2 = (ano2 * 10000) + (mes2 * 100) + dia2;
    fechaA = (anoA * 10000) + (mesA * 100)+ diaA;

    if((fechaA - fecha2) > (fechaA - fecha1))
    {
        cout<<"La fecha más reciente es "<<dia1<< "/" <<mes1<< "/"<<ano1;
    }
    else {
         cout<<"La fecha más reciente es "<<dia2<< "/" <<mes2<< "/" <<ano2;
    }


    return 0;

}