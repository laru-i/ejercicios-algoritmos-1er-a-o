#include <iostream>

using namespace std;

/*
Ingresar la cantidad de alumnos de un curso. Ingresar por cada alumno el nombre y una nota. Por 
cada alumno informar su nombre y si está aprobado o desaprobado. Informar también el 
porcentaje de alumnos aprobados y la cantidad de desaprobados
*/

int main()
{
    int cantA, nota, cantAprob = 0, i, cantDesap = 0;
    string nom;
    float porcA;

    cout<<"ingrese la cantidad de alumnos: ";
    cin>>cantA;

    for(int i = 0; i < cantA; i++)
    {
      cout << "Ingrese nombre y nota "<<endl;
      cin >> nom >> nota;

      if (nota >= 6)
      {
          cout << nom << " está aprobado"<<endl;
          cantAprob++;
      }
      else {
          cout << nom << " está desaprobado"<<endl;
          cantDesap++;
      }
   
      }

    porcA = (float(cantAprob) * 100) / cantA;
    cout << "el porcentaje de alumnos aprobados es " << porcA << "% y la cantidad de desaprobados " << 100 - porcA << "%";
     
       
    return 0;
}