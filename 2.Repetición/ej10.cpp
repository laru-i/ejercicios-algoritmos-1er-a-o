#include <iostream>

using namespace std;

/*
 En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de todos contra 
todos. Por cada partido disputado por un equipo se dispone de la siguiente información :
a) Nombre del equipo,
b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado).
Se arma un lote de datos con todos los resultados del torneo, agrupados por nombre del
equipo.
Desarrollar el programa que imprima:
Por cada equipo, su nombre y el puntaje total que obtuvo (suma 3 si gana, y 1 si empata).
*/


int main()
{
   int cant, puntos, puntaje;
   string nom;
   char res;
   
   cout<<"cantidad de equipos: ";
   cin>>cant;

    for (int i = 0; i < cant; i++)
    {
        cout<<"Nombre del equipo: ";
        cin>>nom;

    puntaje = 0;
    
    for (int i = 0; i < cant; i++) {
        
        cout<<"Código de Resultado: ";
        cin>>res;
        
        switch (res)
      {
      case 'G':
      case 'g':
        puntos = 3;
        break;
      case 'E':
      case 'e':
        puntos = 1;
        break;
      case 'P':
      case 'p':
        puntos = 0;
        break;
    }
      puntaje += puntos;

      }

       cout << nom << " obtuvo " << puntaje << " puntos" << endl;
    }
       

    return 0;
}