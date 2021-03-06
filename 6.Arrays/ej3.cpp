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

void ingreso(int m[][12], int cant, int patente[]);
void inicializar(int m[][12], int cc, int cf);
int secuencial(int v[], unsigned t, int bus);
void mostrarPorFila(int m[][12], int cf, int cc);
void mostrarTotal(int m[][12], int cc, int imp[], int cf);
void inicializarV(int v[], int cf);
void mesesAdeudados(int m[][12], int cant, int cc, int p[]);
void abonotodo(int m[][12], int cant, int cc);

int main()
{
    int cantVehiculos;

    cout << "ingrese cant de vehiculos ";
    cin >> cantVehiculos;

    int matriz[cantVehiculos][12], patente[cantVehiculos], importe[cantVehiculos];

    for (int i = 0; i < cantVehiculos; i++)
    {
        cout << "ingrese patente para cargar en el sistema";
        cin >> patente[i];
    }

    inicializar(matriz, 12, cantVehiculos);
    ingreso(matriz, cantVehiculos, patente);
    mostrarPorFila(matriz, cantVehiculos, 12);
    inicializarV(importe, cantVehiculos);
    mostrarTotal(matriz, 12, importe, cantVehiculos);

    // mostrar punto a
    for (int j = 0; j < cantVehiculos; j++)
    {
        cout << " el importe total de la patente " << patente[j] << " es de " << importe[j] << endl;
    }

    // punto b
    mesesAdeudados(matriz, cantVehiculos, 12, patente);

    // punto c
    abonotodo(matriz, cantVehiculos, 12);

    return 0;
}

void ingreso(int m[][12], int cant, int patente[])
{
    int mes, pat, posPat;
    for (int i = 0; i < cant; i++)
    {

        cout << "ingrese la patente a abonar ";
        cin >> pat;
        posPat = secuencial(patente, cant, pat);

        while (posPat == -1)
        {
            cout << "ingrese la patente a abonar ";
            cin >> pat;
            posPat = secuencial(patente, cant, pat);
        }
        cout << "ingresar mes ";
        cin >> mes;

        while (mes != 0)
        {
            if (mes > 0 && mes <= 12)
            {
                cout << "ingresar importe ";
                cin >> m[posPat][mes - 1];
            }
            cout << "ingresar mes ";
            cin >> mes;
        }
    }
}

void mostrarTotal(int m[][12], int cc, int imp[], int cf)
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            imp[i] += m[i][j];
        }
    }
}

void mesesAdeudados(int m[][12], int cant, int cc, int p[])
{
    for (int i = 0; i < cant; i++)
    {
        cout << "la patente " << p[i] << " adeuda los meses " << endl;
        for (int j = 0; j < cc; j++)
        {
            if (m[i][j] == 0)
            {
                cout << j + 1 << " ";
            }
        }
    }
}

void abonotodo(int m[][12], int cant, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        int j = 0;
        for (j; j < cant; j++)
        {
            if (m[j][i] == 0)
                j = cant;
        }
        if (j == cant)
            cout << "el mes " << i + 1 << " abonaron todos los vehiculos" << endl;
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

void inicializarV(int v[], int cf)
{
    for (int j = 0; j < cf; j++)
    {
        v[j] = 0;
    }
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

int secuencialm(int v[], unsigned t, int bus)
{
    unsigned i = 0;
    while (i < t && v[i] != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}

void mostrarPorFila(int m[][12], int cf, int cc)
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
            cout << m[i][j] << "   ";
        cout << endl;
    }
}
