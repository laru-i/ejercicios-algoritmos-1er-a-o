#include <iostream>

using namespace std;

/*
Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los 
menores que –10.
*/

int main()
{
    int num, i, sumaMayor = 0, sumaMenor = 0, numMa = 0;
    float prom = 0;
      
 for(int i = 0; i < 10; i++)
    {
      cout << "Ingrese un número "<<endl;
      cin >> num;

      if (num > 100)
      {
          sumaMayor += num;
          numMa++;
      }
      if (num < -10)
      {
        sumaMenor += num;
      }
   }
    prom = (float)sumaMayor / numMa;
    cout<< "el promedio de los numeros mayores a 100 es "<< prom << " y la suma de los menores a -10 es " << sumaMenor; 
   
       
    return 0;
}