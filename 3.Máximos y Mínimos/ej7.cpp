#include <iostream>

using namespace std;

/* 
Un jugador arroja 5 dados y se registra como puntaje la suma de los dos valores más altos. Dada 
una serie de tiros, que finaliza al ingresar ‘N’ ante la consulta “Continúa? S/N”, determinar e 
imprimir la cantidad de tiros, el máximo puntaje obtenido, y el puntaje promedio.

*/
int main()
{
    int i = 0, num, mayoruno, mayordos, suma = 0;
    float prom;
    string cont;
    
    do
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
        suma += num;
        i++;
        prom = (float)suma / i;
        cout<<" continua? (s/n) ";
        cin>>cont;

    }while (cont != "n");

    cout<<" los tiros fueron "<<i<<endl;
    cout<<" el max puntaje fue "<<mayoruno<<endl;
    cout<<" el prom es "<<prom;
    
    
    return 0;
}