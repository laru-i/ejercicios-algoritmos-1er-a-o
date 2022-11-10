#include <iostream>
#include <stdio.h>

using namespace std;

/*
Dado el archivo VENTAS.DAT, ordenado por número de factura, con la siguiente
estructura de registro:
Número de factura (int)
Código de vendedor (int) (10 vendedores)
Importe (float)
a) Imprima un listado ordenado por código de vendedor (1 - 10), con código de vendedor
y el detalle de cada venta, ordenadas de mayor a menor por importe.
b) Genere el archivo “VentasVendedor.dat” ordenado por código de vendedor,
con código de vendedor y el importe total de ventas.

Idem 2) En el comercio hay 10 vendedores cuyo código de vendedor es un número
del 1 al 10
*/
struct Ventas
{
    int nroFact, codVend;
    float importe;
};

struct Nodo
{
    Nodo *sig;
    Ventas info;
};

struct VendTotal
{
    int codVend;
    float importeTotal;
};

void listar(Nodo *lista[]);
void generarArchivo(FILE *archV);
void ptoA(Nodo *v[], FILE *arch);
void insertar(Nodo *&lista, Ventas info);
void mostrarArchivo(FILE *archivo);
void ptoB(Nodo *v[], FILE *arch);

int main()
{
    FILE *arch;
    FILE *ventasVendedor;
    Nodo *v[10];

    // generarArchivo(arch);
    ptoA(v, arch);
    ptoB(v, ventasVendedor);
    return 0;
}

/*void generarArchivo(FILE *archV)
{
    archV = fopen("VENTAS.dat", "wb");

    if (archV == NULL)
        cout << "ERROR" << endl;
    else
    {
        Ventas venta;

        cout << "nro factura (0 para finalizar) ";
        cin >> venta.nroFact;

        while (venta.nroFact != 0)
        {
            cout << "cod vendedor: ";
            cin >> venta.codVend;
            cout << "importe: ";
            cin >> venta.importe;
            fwrite(&venta, sizeof(Ventas), 1, archV);

            cout << "nro factura (0 para finalizar) ";
            cin >> venta.nroFact;
        }
        fclose(archV);
    }
}*/

void ptoA(Nodo *v[], FILE *arch)
{
    arch = fopen("VENTAS.dat", "rb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        Ventas ventas;
        // inicializo vector
        for (int i = 0; i < 10; i++)
            v[i] = NULL;

        fread(&ventas, sizeof(Ventas), 1, arch);

        while (!feof(arch))
        {
            insertar(v[ventas.codVend - 1], ventas);

            fread(&ventas, sizeof(Ventas), 1, arch);
        }
        listar(v);
        fclose(arch);
    }
}

void insertar(Nodo *&lista, Ventas info)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = info;
    p = lista;
    while (p != NULL && p->info.importe > info.importe)
    {
        ant = p;
        p = p->sig;
    }
    q->sig = p;
    if (p != lista)
        ant->sig = q;
    else
        lista = q;
}

void listar(Nodo *lista[])
{
    cout << "------------------- PUNTO A --------------------" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (lista[i] != NULL)
        {
            Nodo *p = lista[i];

            while (p)
            {
                cout << "CODIGO: " << p->info.codVend << endl;
                cout << "importe: " << p->info.importe << endl;
                p = p->sig;
                cout << "-------" << endl;
            }
        }
    }
}

void ptoB(Nodo *v[], FILE *arch)
{
    arch = fopen("VentasVendedor.dat", "wb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        VendTotal total;
        for (int i = 0; i < 10; i++)
        {
            if (v[i] != NULL)
            {
                Nodo *p = v[i];
                total.importeTotal = 0;

                while (p)
                {
                    total.codVend = p->info.codVend;
                    total.importeTotal += p->info.importe;
                    p = p->sig;
                }
                fwrite(&total, sizeof(VendTotal), 1, arch);
            }
        }
        fclose(arch);
        mostrarArchivo(arch);
    }
}
void mostrarArchivo(FILE *archivo)
{
    archivo = fopen("VentasVendedor.dat", "rb");
    if (archivo == NULL)
        cout << "ERROR" << endl;
    else
    {
        cout << "------------------- PUNTO B --------------------" << endl;

        VendTotal arch;
        cout << "ARCHIVO" << endl;

        fread(&arch, sizeof(VendTotal), 1, archivo);
        while (!feof(archivo))
        {
            cout << "codigo: " << arch.codVend << endl;
            cout << "importe Total: " << arch.importeTotal << endl;

            cout << "-------" << endl;
            fread(&arch, sizeof(VendTotal), 1, archivo);
        }
        fclose(archivo);
    }
}
