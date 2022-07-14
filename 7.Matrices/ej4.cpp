#include <iostream>
#define f 2
#define c 2

using namespace std;
/*
Una fábrica de calzados elabora 7 modelos en 5 colores diferentes. Se ingresan los datos de las
ventas, para finalizar se ingresa nro. de modelo 0
Nro. modelo (1..7) Color (1..5) Cantidad vendida
Se pide emitir un listado que informe:
a) Totales de cada uno de los modelos y por cada uno de los colores
b) Totales por cada modelo
c) Totales por cada color
d) Total general
*/
void inicializar(int m[][c]);
void ingreso(int m[][c]);
void puntoa(int m[][c]);
void puntob(int m[][c], int v[]);
void puntoc(int m[][c], int v[]);
void puntod(int m[][c]);

int main()
{
    int matriz[f][c], vf[f], vc[c];

    inicializar(matriz);
    ingreso(matriz);
    puntoa(matriz);
    puntob(matriz, vc);
    puntoc(matriz, vf);
    puntod(matriz);

    return 0;
}
void inicializar(int m[][c])
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            m[i][j] = 0;
    }
}

void ingreso(int m[][c])
{

    int modelo, color;
    cout << "ingrese modelo ";
    cin >> modelo;

    while (modelo != 0)
    {
        cout << "ingrese color ";
        cin >> color;

        cout << "ingrese cantidad ";
        cin >> m[modelo - 1][color - 1];

        cout << "ingrese modelo ";
        cin >> modelo;
    }
}

void puntoa(int m[][c])
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "el modelo " << i + 1 << " en el color " << j + 1 << " está: " << m[i][j] << endl;
        }
    }
}

void puntob(int m[][c], int v[])
{
    for (int j = 0; j < f; j++)
    {
        int total = 0;
        for (int i = 0; i < c; i++)
            total += m[j][i];

        cout << "el modelo " << j + 1 << " está: " << total << endl;
    }
}

void puntoc(int m[][c], int v[])
{
    for (int j = 0; j < c; j++)
    {
        int total = 0;
        for (int i = 0; i < f; i++)
            total += m[i][j];

        cout << "el color " << j + 1 << " está: " << total << endl;
    }
}

void puntod(int m[][c])
{
    int total = 0;
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < f; i++)
        {
            total += m[i][j];
        }
    }
    cout << "total completo: " << total << endl;
}