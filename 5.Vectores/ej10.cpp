#include <iostream>

using namespace std;

/*
Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados), se pide 
determinar el/los empleados de máximo sueldo
a) Los números de legajo son números correlativos de 1 a 100
b) Los números de legajo son números no correlativos de 4 cifras.

FALTA TERMINAR 
*/

int cargarDatos(int leg[], int sueldo[]);


int main()
{
    int leg[10], sueldos[10];
    cargarDatos(leg, sueldos);

    return 0;
}
int cargarDatos(int leg[], int sueldo[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "ingresar leg " << endl;
        cin >> leg[i];

        cout << "ingresar sueldo " << endl;
        cin >> sueldo[i];
    }
}
void burbujeo(int v[], int s[], unsigned t)
{
    unsigned i = 1, j;
    int aux, auxa;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                auxa = s[j];
                v[j] = v[j + 1];
                s[j] = s[j + 1];
                v[j + 1] = aux;
                s[j + 1] = auxa;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}
void repetir(int notas[], int dni[], int n)
{
    cout << "los dni de la nota menor " << notas[0] << " son: ";
    for (int i = 0; i < n; i++)
    {
        if (notas[0] == notas[i])
            cout << dni[i] << " ";
    }
    cout << "los dni de la nota mayor " << notas[n - 1] << " son: ";
    for (int i = n - 1; i >= 0; i--)
    {
        if (notas[n - 1] == notas[i])
            cout << dni[i] << " ";
    }
}