#include <iostream>

using namespace std;

/*
Hacer un algoritmo que ingresando por teclado el mes (1 a 12) y el año (4 dígitos), informe la
cantidad de días que tiene el mes.
*/

int main()
{
    int mes, año;

  cout << "Ingrese un mes y un año en formato m/yyyy ";
  cin >> mes >> año;

  switch (mes)
  {

  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    cout << "El mes tiene 31 dias";
    break;

  case 4:
  case 6:
  case 9:
  case 11:
    cout << "El mes tiene 30 dias";
    break;

  case 2:
    if (año % 4 != 0)
      cout << "El mes tiene 28 dias";
    else
      cout << "El mes tiene 29 dias";
    break;

  default:
    cout << "ERROR";
    }

}