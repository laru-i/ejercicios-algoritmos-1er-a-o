#include <iostream>

using namespace std;

/* 
 Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo 
valores):
a) El valor máximo negativo
b) El valor mínimo positivo
d) El promedio de todos los valores

*/
int main()
{
    int i, num, maxneg, minpos, suma = 0, cantsuma = 0, prom;
    
    
    do
    {
        cout<<"ingrese numero: ";
        cin>>num;
        suma += num;

        if (num != 0)        
        cantsuma++;

        if (num < 0)
        {
            if (maxneg > num)
            maxneg = num;      
        }
    else {
        if (num > 0)
        {
            if (minpos > num)
            minpos = num;              
        }
        }        
    }  while (num != 0);

    prom = (float)suma/ cantsuma;

    cout << "El valor maximo negativo es: " << maxneg << endl;
    cout << "El valor minimo positivo es: " << minpos << endl;
    cout << "El promedio de todos los valores es: " << prom;
    
    return 0;
}
