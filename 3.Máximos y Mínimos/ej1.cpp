#include <iostream>

using namespace std;

/* 
Dados 50 valores distintos que se ingresan por teclado, mostrar el menor.
*/
int main()
{
   int i, num, menor;

    do
    {
        cout<<"ingrese numero: ";
        cin>>num;

        if (i==0 || num<menor)
        {
            menor = num;
        }
        i++;
        
    } while (i<5);
    cout<<"el número más chico es: "<<menor;

    return 0;
}
