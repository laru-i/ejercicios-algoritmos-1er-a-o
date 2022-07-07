#include <iostream>
using namespace std;

/*

Ingresar edades comprendidas entre 18 y 22, e imprimir cuántas veces se ingresó cada una de estas 
edades. El lote finaliza con una edad igual a cero.

*/

int main()
{
    int edad, i = 0,dieciocho = 0,diecinueve = 0,veinte = 0,veintiuno = 0, veintidos = 0;

   do
   {
    cout<<"ingrese una edad entre 18 y 22 (cero para finalizar): ";
    cin>>edad;
    i++;

    switch (edad)
    {
        case 18:
            dieciocho++;
        break;
        case 19:
            diecinueve++;
        break;
        case 20:
            veinte++;
        break;
        case 21:
            veintiuno++;
        break;
        case 22:
            veintidos++;
        break;   
    }

   } while (edad != 0);

    cout<<dieciocho<<" tiene 18"<<endl;
    cout<<diecinueve<<" tiene 19"<<endl;
    cout<<veinte<<" tiene 20"<<endl;
    cout<<veintiuno<<" tiene 21"<<endl;
    cout<<veintidos<<" tiene 22"<<endl;
  
    
    return 0;
}
