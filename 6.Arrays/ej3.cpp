#include <iostream>

using namespace std;
/*
Una empresa cuenta con una flota de vehículos. Se requiere
un algoritmos que dada la cantidad de vehículos y las
patentes de los mismos analice los pagos del impuesto
al automotor de los mismos del año pasado.
Los pagos se ingresan por teclado, sin orden.
Por cada pago se ingresa:
Mes abonado (1 a 12)
Patente
Importe abonado
El ingreso de datos finaliza con mes cero.
Se pide informar:
a) Por cada vehículo, patente e importe total abonado.
b) Por cada vehículo, patente y meses adeudados.
c) Mes o meses en los que se abonó por todos los vehículos.
*/
void ingreso(int m[][12], int cc, int cf);
void inicializar(int m[][12], int cc, int cf);
void mostrarCol(int m[][12], int cc, int cf);

int main()
{
    int cantVehiculos, matriz[cantVehiculos][12], patente[cantVehiculos];

    cout << "ingrese cant de vehiculos ";
    cin >> cantVehiculos;

    for (int i = 0; i < cantVehiculos; i++)
    {
        cout << "ingrese patente ";
        cin >> patente[cantVehiculos];
    }

    ingreso(matriz, cantVehiculos);
    inicializar(matriz, 12, cantVehiculos);
    mostrarCol(matriz, 12, cantVehiculos);

    return 0;
}

void ingreso(int m[][12], int cant)
{
    for (int i = 0; i < cant; i++)
    {
            cout << "ingresar importe ";
            cin >> m[j][i + 1];

            cout << "ingresar mes ";
            cin >> m[j][i + 2];
    }
}

void inicializar(int m[][12], int cc, int cf)
{
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < cf; j++)
        {
            m[j][i] = 0;
        }
    }
}

void mostrarCol(int m[][12], int cc, int cf)
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