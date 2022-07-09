#include <iostream>

using namespace std;
/*
Dados dos valores, m (<=30) y n (<=25), ingresar por filas todos los componentes de una matriz de
m filas y n columnas. Desarrollar un programa que:
✓ Imprima la matriz por columna.
✓ Calcule e imprima el valor promedio de los componentes de la matriz.
✓ Genere e imprima un vector donde cada componente sea la suma de la columna homóloga.
✓ Genere e imprima un vector donde cada componente sea el valor máximo de cada fila.
*/
void cargarXColumna(int m[][25], int cf, int cc);
void mostrarCol(int m[][25], int cf, int cc);
float promedio(int m[][25], int cf, int cc);
void sumatoria(int m[][25], int vc[], int cf, int cc);
void inicializar(int v[], int t);
void mostrarVector(int v[], int t);
void mostrarMayor(int m[][25], int vm[], int cf, int cc);

int main()
{

    int matriz[30][25], cf, cc;

    cout << "ingrese cant de filas: " << endl;
    cin >> cf;

    cout << "ingrese cant de columnas: " << endl;
    cin >> cc;

    int vc[cc], vm[cc];

    cargarXColumna(matriz, cf, cc);
    mostrarCol(matriz, cf, cc);
    cout << "el promedio es " << promedio(matriz, cf, cc);
    inicializar(vc, cc);
    sumatoria(matriz, vc, cf, cc);
    cout << endl;
    mostrarVector(vc, cf);
    cout << endl;
    mostrarMayor(matriz, vm, cf, cc);
    mostrarVector(vm, cf);

    return 0;
}

void cargarXColumna(int m[][25], int cf, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < cf; j++)
        {
            cout << "Columna " << i << " Fila " << j << endl;
            cin >> m[i][j];
        }
    }
}

void mostrarCol(int m[][25], int cf, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < cf; j++)
        {
            cout << m[j][i] << " ";
        }
        cout << endl;
    }
}

float promedio(int m[][25], int cf, int cc)
{
    float suma = 0, prom = 0;
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < cf; j++)
            suma += m[j][i];
    }
    prom = (float)suma / (cf * cc);
    return prom;
}

void inicializar(int v[], int t)
{
    for (int i = 0; i < t; i++)
        v[i] = 0;
}

void sumatoria(int m[][25], int vc[], int cf, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < cf; j++)
            vc[i] += m[j][i];
    }
}

void mostrarVector(int v[], int t)
{
    for (int i = 0; i < t; i++)
        cout << v[i] << endl;
}

void mostrarMayor(int m[][25], int vm[], int cf, int cc)
{
    for (int i = 0; i < cf; i++)
    {
        int mayor = m[i][0];
        for (int j = 0; j < cc; j++)
        {
            if (m[i][j] > mayor)
                mayor = m[i][j];
        }
        vm[i] = mayor;
    }
}