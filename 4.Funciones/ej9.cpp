#include <iostream>
using namespace std;

/*  Desarrollar una función tal que dada una fecha en formato número de 8 dígitos 
(AAAAMMDD), devuelva el día, el mes y el año correspondientes.

*/
void fechabien(int);

int main()
{
    int fecha;
    cout<<"ingrese una fecha en formato AAAAMMDD ";
    cin>>fecha;
    fechabien(fecha);

    return 0;
}

void fechabien(int a){
    int ano, mes, dia;
    ano = a / 10000;
    mes = (a - (ano * 10000)) / 100;
    dia = (a - (ano * 10000)) - mes * 100;
    
  cout << "El ano es: " << ano << endl;
  cout << "El mes es: " << mes << endl;
  cout << "El dia es: " << dia << endl;

}