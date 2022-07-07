#include <iostream>

using namespace std;

/* 
Dados 5 valores distintos que se ingresan por teclado, mostrar los dos mayores

*/

int main()
{
    int num, mayoruno, mayordos;
    
    for (int i = 0; i < 5; i++)
    {
        cout<<"ingrese numero: ";
        cin>>num;

        if (i==0)
        {
            mayoruno = num;
        }
        else {
            if(i == 1)
                mayordos = num;
            else if (num > mayoruno)
            {
                mayordos = mayoruno;
                mayoruno = num;
            }
            else if (num > mayordos)
            {
                mayordos = num;
            }
        }
    }
    
    cout<<"los números más grandes son: "<<mayoruno<<" y "<<mayordos;
  
    
    return 0;
}
