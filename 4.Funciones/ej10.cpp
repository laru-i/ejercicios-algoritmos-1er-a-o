#include <iostream>
using namespace std;

/*  Desarrollar un procedimiento tal que dada una hora (HHMMSS) y un tiempo también en 
formato HHMMSS devuelva la nueva hora que surge de sumar el tiempo a la hora inicial, 
considere también si cambió el día.
*/
void fechabien(int);

int main()
{
    int hora, tiempo;
    cout<<"ingrese una hora (HHMMSS) ";
    cin>>hora;
    cout<<"ingrese un tiempo (HHMMSS) ";
    cin>>tiempo;


    return 0;
}

void hora(int a){
    int ano, mes, dia;
    ano = a / 10000;
    mes = (a - (ano * 10000)) / 100;
    dia = (a - (ano * 10000)) - mes * 100;
    
  cout << "El ano es: " << ano << endl;
  cout << "El mes es: " << mes << endl;
  cout << "El dia es: " << dia << endl;

}