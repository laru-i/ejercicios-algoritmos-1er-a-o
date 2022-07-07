#include <iostream>

using namespace std;

/*
Dado un vector de códigos de productos y un vector paralelo de precios correspondiente a los
productos, se pide:
a) Informar código y precio de todos los productos ordenados de mayor a menor por precio.
b) Dado un código de producto informar su precio
*/
void burbujeo(int v[], int s[], unsigned t);
int cargarDatos(int pro[], int pre[], int t);
int secuencial(int v[], unsigned t, int bus);

int main()
{
    int n;

    cout << "ingrese cant de prod ";
    cin >> n;

    int prod[n], precio[n];
    cargarDatos(prod, precio, n);
    burbujeo(precio, prod, n);

    for (int i = 0; i < n; i++)
        cout << precio[i] << endl;

    int cod, sueldo;
    cout << "ingrese código para mostrar precio ";
    cin >> cod;
    sueldo = secuencial(prod, n, cod);
    if (sueldo == -1)
        cout << "prod no encontrado ";
    else
        cout << " el precio es " << precio[sueldo];
    return 0;
}

int cargarDatos(int pro[], int pre[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ingresar codigo de prod" << endl;
        cin >> pro[i];

        cout << "ingresar precio " << endl;
        cin >> pre[i];
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
            if (v[j] < v[j + 1])
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

int secuencial(int v[], unsigned t, int bus)
{
    unsigned i = 0;
    while (i < t && v[i] != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}