#include <iostream>
#include <stdio.h>

using namespace std;

/*
Dado el archivo VENTAS.DAT, ordenado por número de factura, con la siguiente
estructura de registro:
Número de factura (int)
Código de vendedor (int)
Importe (float)
a) Imprima un listado ordenado por código de vendedor, con código de vendedor
y el detalle de cada venta, ordenadas de mayor a menor por importe.
b) Genere el archivo “VentasVendedor.dat” ordenado por código de vendedor,
con código de vendedor y el importe total de ventas.
*/

struct Ventas
{
    int nroFact;
    float importe;
};

struct NodoSL
{
    Ventas dato;
    NodoSL *sig;
};

struct Vendedor
{
    int codVend;
    NodoSL *listaVentas;
};

struct NodoL
{
    Vendedor dato;
    NodoL *sig;
};

struct Archivo
{
    int nroFact, codVend;
    float importe;
};

struct VendedorTotal
{
    int codVend;
    float importeTotal;
};

// void generarArchivo(FILE *archV);
void pasarALista(FILE *a, NodoL *&listaL, NodoSL *&listaSL);
void insertar(NodoSL *&lista, Ventas info);
NodoL *buscarInsertar(NodoL *&lista, Vendedor vend);
void listar(NodoL *listaL, NodoSL *listaSL);
void mostrarArchivo(FILE *archivo1);
void ptoB(FILE *arch, NodoL *listaL);

int main()
{
    FILE *arch;
    FILE *ventasVendedor;
    NodoL *listaL = NULL;
    NodoSL *listaSL = NULL;

    // generarArchivo(arch);
    pasarALista(arch, listaL, listaSL);
    ptoB(ventasVendedor, listaL);

    return 0;
}
/*
void generarArchivo(FILE *archV)
{
    archV = fopen("VENTAS.dat", "wb");

    if (archV == NULL)
        cout << "ERROR" << endl;
    else
    {
        Archivo venta;

        cout << "nro factura (0 para finalizar) ";
        cin >> venta.nroFact;

        while (venta.nroFact != 0)
        {
            cout << "cod vendedor: ";
            cin >> venta.codVend;
            cout << "importe: ";
            cin >> venta.importe;
            fwrite(&venta, sizeof(Archivo), 1, archV);

            cout << "nro factura (0 para finalizar) ";
            cin >> venta.nroFact;
        }
        fclose(archV);
    }
}*/

void mostrarArchivo(FILE *archivo1)
{
    archivo1 = fopen("VentasVendedor.dat", "rb");
    if (archivo1 == NULL)
        cout << "ERROR" << endl;
    else
    {
        cout << "------------------- PUNTO B --------------------" << endl;
        VendedorTotal arch;
        cout << "ARCHIVO" << endl;

        fread(&arch, sizeof(VendedorTotal), 1, archivo1);
        while (!feof(archivo1))
        {
            cout << "codigo: " << arch.codVend << endl;
            cout << "importe Total: " << arch.importeTotal << endl;

            cout << "-------" << endl;
            fread(&arch, sizeof(VendedorTotal), 1, archivo1);
        }
    }
    fclose(archivo1);
}

void pasarALista(FILE *a, NodoL *&listaL, NodoSL *&listaSL)
{
    a = fopen("VENTAS.dat", "rb");
    if (a == NULL)
        cout
            << "ERROR" << endl;
    else
    {
        NodoL *p;

        Vendedor vendedor;
        Ventas venta;
        Archivo arch;

        fread(&arch, sizeof(Archivo), 1, a);

        while (!feof(a))
        {
            vendedor.listaVentas = NULL;
            vendedor.codVend = arch.codVend;
            p = buscarInsertar(listaL, vendedor);

            venta.nroFact = arch.nroFact;
            venta.importe = arch.importe;
            insertar(p->dato.listaVentas, venta);

            fread(&arch, sizeof(Archivo), 1, a);
        }
        fclose(a);
    }
    listar(listaL, listaSL);
}

void insertar(NodoSL *&lista, Ventas info)
{
    NodoSL *q, *p, *ant;
    q = new NodoSL;
    q->dato = info;
    p = lista;
    while (p != NULL && p->dato.importe > info.importe)
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

NodoL *buscarInsertar(NodoL *&lista, Vendedor vend)
{
    NodoL *ant, *p = lista;
    while (p != NULL && p->dato.codVend < vend.codVend)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && vend.codVend == p->dato.codVend)
        return p;
    else
    {
        NodoL *n = new NodoL;
        n->dato = vend;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}

void listar(NodoL *listaL, NodoSL *listaSL)
{
    NodoL *p;
    p = listaL;

    NodoSL *q;
    cout << "------------------- PUNTO A --------------------" << endl;
    while (p) // p
    {
        cout << "CODIGO: " << p->dato.codVend << endl;
        q = p->dato.listaVentas;
        while (q)
        {
            cout << "importe: " << q->dato.importe << endl;
            q = q->sig;
        }
        p = p->sig;
        cout << "-------" << endl;
    }
}

void ptoB(FILE *arch, NodoL *listaL)
{
    arch = fopen("VentasVendedor.dat", "wb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        VendedorTotal vend;
        NodoL *p = listaL;
        NodoSL *q;

        while (p)
        {
            vend.importeTotal = 0;
            vend.codVend = p->dato.codVend;
            q = p->dato.listaVentas;

            while (q)
            {
                vend.importeTotal += q->dato.importe;
                q = q->sig;
            }
            fwrite(&vend, sizeof(VendedorTotal), 1, arch);
            p = p->sig;
        }
        fclose(arch);
        mostrarArchivo(arch);
    }
}