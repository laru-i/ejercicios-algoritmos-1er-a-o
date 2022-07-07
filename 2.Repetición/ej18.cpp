#include <iostream>

using namespace std;

/*
Ingresar por teclado el nombre de un alumno, y a continuación la calificación que obtuvo para 
cada materia rendida (hasta ingresar una calificación cero) por cada alumno de los 25 del curso. 
Informar por cada alumno nombre y su promedio.
*/


int main()
{   
   float prom; 
   int nota, i = 0;
   string nombre; 

    do
    {
     cout<<"Ingrese nombre del alumno ";
     cin>>nombre;

     cout<<"Ingrese nota de "<< nombre <<" (cero para finalizar)";
     cin>>nota;
     i++;

    } while (nota != 0 && i < 25);

    prom = nota / i;
  
    cout<<nombre<<" tiene un promedio de "<<prom;

    return 0;
}