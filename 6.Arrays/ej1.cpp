
#include <iostream>
#define max 5

using namespace std;

/*
Una empresa de aviación realiza 500 vuelos semanales a distintos puntos del país y requiere desarrollar un programa
para la venta de pasajes. Para ello se ingresan los datos de los 500 vuelos que realiza, sin ningún orden, por cada vuelo
se ingresa:
código de vuelo
cantidad de pasajes disponibles

A continuación se ingresan los datos de los potenciales compradores, el ingreso finaliza con código de vuelo cero, por
cada uno se ingresa:
código de vuelo
cantidad de pasajes solicitados
DNI del solicitante
apellido y nombre del solicitant

Se pide:
a) Para los solicitantes a los cuales se les venden pasajes, emitir el siguiente listado:
 DNI - Apellido y Nombre - Cantidad de pasajes - Código de Vuelo

 b) Al final del proceso emitir el siguiente listado ordenado por código de vuelo
 Código de Vuelo Pasajes disponibles Pasajes no vendidos

*/

struct Vuelo
{
    int codigo;
    int pasajes, novendidos;
};

struct Compra
{
    string nombre;
    int dni, cantpasajes, codigoV;
};

void ingreso(Vuelo v[]);

int main()
{
    Vuelo vuelo[max];
    Compra compra[max];

    ingreso(vuelo);
    comprar(compra);
    burbujeo

        return 0;
}

void ingreso(Vuelo v[])
{
    for (int i = 0; i < max; i++)
    {
        cout << "código de vuelo ";
        cin >> v[i].codigo;

        cout << "pasajes disponibles ";
        cin >> v[i].pasajes;
    }
}

void comprar(Compra v[])
{
    int i = 0;
    do
    {
        cout << "nombre ";
        cin >> v[i].nombre;

        cout << "dni ";
        cin >> v[i].dni;

        cout << "código de vuelo ";
        cin >> v[i].codigoV;

        cout << "cant pasajes a comprar ";
        cin >> v[i].cantpasajes;

        i++;
    } while (v[i].codigoV != 0);
}

void procesar(Compra c[], Vuelo v[])
{
    for (int i = 0; i < max; i++)
    {
    }
}

void burbujeo(Vuelo v[], unsigned t)
{
    unsigned i = 1, j;
    Vuelo aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].codigo > v[j + 1].codigo)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

int binaria(int v[], unsigned t, int bus)
{
    int desde = 0, hasta = t - 1, medio;
    do
    {
        medio = (desde + hasta) / 2;

        if (bus < v[medio])
            hasta = medio - 1;
        else
            desde = medio + 1;

    } while (desde <= hasta && v[medio] != bus);
    if (v[medio] == bus)
        return medio;
    else
        return -1;
}