#include <iostream>

using namespace std;

/*
 Dado un conjunto de triángulos representados por sus lados lado1, lado2 y lado3 dados como 
datos, determinar e imprimir la cantidad de triángulos equiláteros, isósceles y escalenos. El 
ingreso de datos finaliza cuando un lado es nulo.
*/


int main()
{
   float l1,l2,l3;
   int triEq = 0, triIs = 0, triEs = 0;


    do
    {
     cout<<"Ingrese los tres lados de un triángulo ";
     cin>>l1>>l2>>l3;

     if (l1 != 0 && l2 != 0 && l3 != 0)
     {
      
        if (l1 == l2 && l2 == l3)
    {
        cout<<"El triangulo es equilatero"<<endl;
        triEq++;
    }

    if (l1 != l2 && l2 != l3)
    {       
        cout<<"El triángulo es escaleno"<<endl;
        triEs++;   
    }

    if (l1 == l2 && l2 != l3)
    {       
        cout<<"El triángulo es isoceles"<<endl;
        triIs++;   
    }
         
     }
     

    } while (l1 != 0 && l2 != 0 && l3 != 0);
    
    cout << "Hay " << triIs << " triangulos isosceles" << endl;
    cout << "Hay " << triEq << " triangulos equilateros" << endl;
    cout << "Hay " << triEs << " triangulos escalenos" << endl;
    

    return 0;
}