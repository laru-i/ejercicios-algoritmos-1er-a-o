#include <iostream>

using namespace std;

/*
consigna del 8:
Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
b) Dado un código de producto informar su precio

REPETIR EL 8 CON STRUCT
*/

struct Productos
{
    int codigo, precio;
};

int cargarDatos(Productos p[], int n);
void burbujeo(Productos p[], unsigned t);
int secuencial(Productos p[], unsigned t, int bus);

int main()
{
    int n;
    do
    {
        cout << "ingrese cant de prod ";
        cin >> n;
    } while (n == 0);

    Productos productos[n];

    cargarDatos(productos, n);
    burbujeo(productos, n);

    for (int i = 0; i < n; i++)
        cout << productos[i].precio << endl;

    int cod, sueldo;
    cout << "ingrese código para mostrar precio ";
    cin >> cod;

    sueldo = secuencial(productos, n, cod);
    if (sueldo == -1)
        cout << "prod no encontrado ";
    else
        cout << " el precio es " << productos[sueldo].precio;
    return 0;
}

int cargarDatos(Productos p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ingresar codigo de prod" << endl;
        cin >> p[i].codigo;

        cout << "ingresar precio " << endl;
        cin >> p[i].precio;
    }
}

void burbujeo(Productos p[], unsigned t)
{
    unsigned i = 1, j;
    int aux, auxa;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (p[j].precio < p[j + 1].precio)
            {
                aux = p[j].codigo;
                auxa = p[j].precio;
                p[j].codigo = p[j + 1].codigo;
                p[j].precio = p[j + 1].precio;
                p[j + 1].codigo = aux;
                p[j + 1].precio = auxa;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

int secuencial(Productos p[], unsigned t, int bus)
{
    unsigned i = 0;
    while (i < t && p[i].codigo != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}