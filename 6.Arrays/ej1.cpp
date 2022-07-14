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

 Nota: Se le vende al solicitante si la cantidad de pasajes que solicita está disponible, en caso contrario se computa como
pasajes no vendidos.

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
void burbujeo(Vuelo v[], unsigned t);
void mostrar(Compra c);
void comprar(Compra v, Vuelo vu[]);
int binaria(Vuelo v[], unsigned t, int bus);

int main()
{
    Vuelo vuelo[max];
    Compra compra;

    ingreso(vuelo);
    burbujeo(vuelo, max);
    comprar(compra, vuelo);
    mostrar(compra);

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

void comprar(Compra v, Vuelo vu[])
{
    int i = 0, pos;
    cout << "código de vuelo a comprar";
    cin >> v.codigoV;

    pos = binaria(vu, max, v.codigoV);
    if (pos == -1)
    {
        cout << "codigo de vuelo no encontrado, vuelva a ingresarlo ";
        cin >> v.codigoV;
    }

    while (v.codigoV != 0)
    {
        cout << "cant pasajes a comprar ";
        cin >> v.cantpasajes;

        if (vu[pos].pasajes < v.cantpasajes)
        {
            cout << "no hay pasajes suficientes" << endl;
            vu[pos].novendidos += v.cantpasajes;
        }
        else
        {
            vu[pos].pasajes -= v.cantpasajes;
            cout << "nombre ";
            cin >> v.nombre;

            cout << "dni ";
            cin >> v.dni;
        }
        i++;

        cout << "código de vuelo ";
        cin >> v.codigoV;
    }
}

void mostrar(Compra c)
{
    for (int i = 0; i < max; i++)
    {
        cout << "DNI  "
             << " nombre "
             << " pasajes "
             << " codigo " << endl;
        cout << c.dni << " " << c.nombre << " " << c.cantpasajes << " " << c.codigoV;
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

int binaria(Vuelo v[], unsigned t, int bus)
{
    int desde = 0, hasta = t - 1, medio;
    do
    {
        medio = (desde + hasta) / 2;

        if (bus < v[medio].codigo)
            hasta = medio - 1;
        else
            desde = medio + 1;

    } while (desde <= hasta && v[medio].codigo != bus);
    if (v[medio].codigo == bus)
        return medio;
    else
        return -1;
}