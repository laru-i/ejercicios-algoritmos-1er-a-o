
#include <iostream>

using namespace std;

/*
Ingresar 10 números por teclado y mostrar sólo los positivos.
*/

int main()
{
    int nro;

    for (unsigned i = 1; i < 10; i++)
    {
        cout<<"Ingrese el número de orden "<< i <<endl;
        cin>>nro;

        if (nro > 0)
        {
            cout << "Numero positivo: " << nro << endl;
        }
        
    }
       
    return 0;
}