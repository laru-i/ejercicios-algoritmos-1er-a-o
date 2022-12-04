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

// INICIALIZAR EN 0

int main()
{
    int cantVehiculos, mes, importe, patente;

    cin >> cantVehiculos;

    int importes[cantVehiculos][12];
    int patentes[cantVehiculos];

    for (int i = 0; i < cantVehiculos; i++)
        cin >> patentes[i];

    return 0;
}

void ptoA(int fila, int columna, int m[][12], int v[])
{
    for (int i = 0; i < columna; i++)
    {
        int total = 0;
        for (int j = 0; j < fila; j++)
        {
            total += m[i][j];
        }
        cout << v[i] << "patente" << total;
    }
}

void ptoB(int fila, int columna, int m[][12], int v[])
{
    for (int i = 0; i < columna; i++)
    {
        cout << "patente" << v[i];
        cout << "meses adeudados";
        for (int j = 0; j < fila; j++)
        {
            if (m[i][j] == 0)
                cout << j + 1;
        }
    }
}

void ptoC(int fila, int columna, int m[][12], int v[])
{
    for (int i = 0; i < fila; i++)
    {
        int cont = 0;
        for (int j = 0; j < columna; j++)
        {
            while (m[i][j] != 0)
                cont++;
        }
        if (cont == 12)
            cout << "mes" << i + 1 << "abonaron todos";
        }
}

void ingresoImportes(int cant, int patentes[], int m[][12])
{
    for (int i = 0; i < cant; i++)
    {
        int mes, patente, importe, pos;

        cin >> patente;

        pos = buscar(patentes, cant, patente);

        while (pos == -1)
        {
            cin >> patente;
            pos = buscar(patentes, cant, patente);
            if (pos == -1)
                cout << "no existe patente";
        }

        cin >> mes;

        while (mes != 0)
        {
            cin >> m[pos][mes]; // importe;
            cin >> mes;
        }
    }
}

int buscar(int patentes[], int t, int pat)
{
    int i = 0;
    while (i < t && patentes[i] != pat)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}