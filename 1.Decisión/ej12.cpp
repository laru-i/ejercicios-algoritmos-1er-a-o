#include <iostream>

using namespace std;

/*
Confeccionar un programa que pueda determinar el importe a pagar por una prestación 
médica según su código. Los importes se cobran según la siguiente tabla : 
Código Importe $ 
A 200 
D 400
F 600 
M 1500 
T 150 0 
Por cada prestación se debe ingresar el número de historia del paciente y el código de la 
prestación. Se debe emitir un ticket para cada uno, con el número de la historia, el código y el 
importe a pagar.

*/

int main()
{
    int numH, imp;
    char codP;
    
  cout << "Ingrese el número de historia y código de prestación ";
  cin >> numH >> codP;

  switch (codP)
  {

  case 'A':
  case 'a':
    imp = 200;
    break;

  case 'D':
  case 'd':
  imp = 400;
    break;

  case 'F':
  case 'f':
    imp = 600;
    break;

    case 'M':
    case 'm':
    case 'T':
    case 't':
    imp = 1500;
    break;

}

   cout<< "numero de historia " << numH << " codigo " << codP << " IMPORTE A PAGAR $" << imp;
  
  return 0;

}