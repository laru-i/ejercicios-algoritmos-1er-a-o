#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
En un comercio se tiene el archivo “VentasJunio.dat” con un registro por cada uno de los 30 días del mes de junio con
las ventas acumuladas de ese día. Cada registro tiene día, importe total y cantidad de ventas. El archivo está ordenado
por día. Hacer un programa que informe el importe de las ventas del día 15 y además que informe cuándo hubo más
ventas, si el primero o el último día del mes
*/

void registros(FILE *avj);

struct Registro
{
    int dia, impTot, cantVent;
};

int main()
{
    FILE *aVentasJunio;
    aVentasJunio = fopen("VentasJunio.dat", "rb");

    registros(aVentasJunio);

    fclose(aVentasJunio);

    return 0;
}

void registros(FILE *avj)
{
    Registro registro;

    if (avj == NULL)
    {
        cout << "error" << endl;
    }
    else
    {

        fseek(avj, (15 - 1) * sizeof(Registro), SEEK_SET);
        fread(&registro, sizeof(Registro), 1, avj);
        cout << "el importe del día 15 es: " << registro.impTot << endl;

        fseek(avj, 0, SEEK_SET);
        fread(&registro, sizeof(Registro), 1, avj);
        int primerD = registro.cantVent;

        fseek(avj, 0, SEEK_END);
        fread(&registro, sizeof(Registro), 1, avj);
        int ultimoD = registro.cantVent;

        if (primerD < ultimoD)
            cout << "el ultimo dia hubo mas ventas" << endl;
        else
            cout << "el primer dia hubo mas ventas" << endl;
    }
}