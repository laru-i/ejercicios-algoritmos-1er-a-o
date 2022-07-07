#include <iostream>
using namespace std;

/* Desarrollar la función unsigned edadAGrupoEtario (unsigned edad) que retorne un valor de 
1 a 8, de acuerdo al siguiente cuadro: 
Edad Valor
Hasta 14 años 1
De 15 a 21 - 2
De 22 a 28 - 3
De 29 a 35 - 4
De 36 a 42 - 5
De 43 a 49 - 6
De 50 a 63 - 7
Mayores de 64 - 8
*/
unsigned edadAGrupoEtario(unsigned);

int main()
{
    int edad;

    cout<<"ingrese su edad ";
    cin>>edad;
    cout<<edadAGrupoEtario(edad);
         
    return 0;
}
unsigned edadAGrupoEtario(unsigned edad){
   bool caso1, caso2, caso3, caso4, caso5, caso6, caso7, caso8;

   caso1 = edad >= 0 && edad <= 14;
   caso2 = edad >= 15 && edad <= 21;
   caso3 = edad >= 22 && edad <= 28;
   caso4 = edad >= 29 && edad <= 35;
   caso5 = edad >= 36 && edad <= 42;
   caso6 = edad >= 43 && edad <= 49;
   caso7 = edad >= 50 && edad <= 63;
   caso8 = edad >= 64;

   if (caso1)
    return 1;
   if (caso2)
    return 2;
   if (caso3)
    return 3;
   if (caso4)
    return 4;
   if (caso5)
    return 5;
   if (caso6)
    return 6;
   if (caso7)
    return 7;
   if (caso8)
    return 8;
    
}