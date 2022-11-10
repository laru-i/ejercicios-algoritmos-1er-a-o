#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
/*
Un restaurant desea manejar en forma computarizada las adiciones de sus mesas.
Para ello dispone de los siguientes datos:
a) Un archivo de platos y bebidas, ordenado por código de plato con el siguiente
diseño:
    Código de plato (1 a 200)
    Descripción del plato (40 caracteres)
    Precio unitario (float)
b) Número de factura inicial y fecha del día.
c) Por cada producto servido se ingresan por teclado la siguiente información:
    Número de mesa (1..48)
    Código de operación (‘A’, ‘B’, ‘F’)
    Código de plato (1..200)
    Unidades pedidas

    Operación A: significa plato servido
    Operación B: significa devolución del plato
    Operación F: fin del pedido, emitir la adición y el campo de código de plato
contiene el número del mozo (1..10) que atendió esa mesa.

Cuando se ingrese nro de mesa igual a 0 indica fin del día. En caso de que queden
adiciones pendientes, informar una leyenda.

Se pide realizar un programa que:
1. Imprima la factura de cada mesa que fue ocupada:
Restaurant           Fecha :..........           Factura:.......................
Cant          Descripción       Precio      Importe
.......     ................ ............ ............
Mozo: ....      Total:........................

Los platos deben estar ordenados por código de plato y acumuladas las unidades en
caso de repetición.

2. Grabar un archivo de facturación con los siguientes datos: fecha, número
de factura, mesa, mozo, e importe

3. Al final del día emitir un listado con el total a cobrar por cada mozo,
ordenado por número de mozo (cobran el 1% sobre cada adición
*/

struct Archivo
{
    int codPlato;
    float precio;
    char desc[40];
};

struct ArchivoFactura
{
    int fecha, nroFact, mesa, mozo;
    float importe;
};

struct Factura
{
    int codPlato, unidades, nroMozo;
    float precio, total;
    char desc[40];
};

struct Mesas
{
    char codOp[2];
    int codPlato, unidades, nroMozo;
};

struct Nodo
{
    Nodo *sig;
    Mesas info;
};

int main()
{
    Nodo *v[48];
    FILE *archivo = fopen("PlatosyBebidas.dat", "rb");

    inicializar(v);
    pto1(v, archivo);

    return 0;
}

void inicializar(Nodo *v[])
{
    for (int i = 0; i < 48; i++)
        v[i] = NULL;
}

void pto1(Nodo *v[], FILE *arch)
{
    Mesas datosMesa;
    int nroMesa, codPlato, unidades, nroMozo;
    char codOp[2];

    cout << "ingrese nro de mesa: " << endl;
    cin >> nroMesa;

    while (nroMesa != 0)
    {
        cout << "ingrese cod de operacion: " << endl;
        cin >> codOp;

        cout << "ingrese cod de plato: " << endl;
        cin >> codPlato;

        cout << "ingrese unidades pedidas: " << endl;
        cin >> unidades;

        if (strcmpi(codOp, "A"))
        {
            datosMesa.codPlato = codPlato;
            datosMesa.unidades = unidades;
            buscarInsertar(v[nroMesa - 1], datosMesa);
            cout << "plato agregado a la lista ";
        }

        if (strcmpi(codOp, "B"))
        {
            buscarPlato(v[nroMesa - 1], datosMesa);
            cout << "plato dado de baja ";
        }

        if (strcmpi(codOp, "F"))
        {
            cout << "ingrese nro de mozo: " << endl;
            cin >> nroMozo;
            datosMesa.nroMozo = nroMozo;
            // agregarMozo();
            imprimirFactura(v, arch);
        }

        cout << "ingrese nro de mesa: " << endl;
        cin >> nroMesa;
    }
}

void buscarPlato(Nodo *&lista, Mesas mesa)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.codPlato == mesa.codPlato)
        p->info.unidades--;
}

// void agregarMozo()
// {
// }

void imprimirFactura(Nodo *v[], FILE *arch, FILE *archFact)
{
    Archivo infoArchivo;
    ArchivoFactura infoArchivoFct;
    Factura fact;
    int nroFact = 1;

    for (int i = 0; i < 48; i++)
    {
        cout << "MESA " << i++;
        Nodo *p = v[i];
        cout << "FACTURA NRO " << nroFact << endl;
        while (p)
        {
            fseek(arch, v[i]->info.codPlato - 1 * sizeof(Archivo), SEEK_SET);
            fact.codPlato = v[i]->info.codPlato;
            strcpy(fact.desc, infoArchivo.desc);
            fact.unidades = v[i]->info.unidades;
            fact.precio = infoArchivo.precio;
            fact.total += (infoArchivo.precio * v[i]->info.unidades);
            // fact.nroMozo = v[i]->info.nroMozo;

            cout << "codigo de plato: " << fact.codPlato;
            cout << "cantidad: " << fact.unidades;
            cout << "precio unitario: " << fact.precio;
            p = p->sig;
        }
        cout << "importe total: " << fact.total;
        // cout << "mozo: " << fact.nroMozo;
        nroFact++;
        v[i] = NULL;

        infoArchivoFct.nroFact = nroFact;
        infoArchivoFct.mesa = i++;
        // falta mozo
        infoArchivoFct.importe = fact.total;
        fwrite(&infoArchivoFct, sizeof(ArchivoFactura), 1, archFact);
    }
}

void *buscarInsertar(Nodo *&lista, Mesas mesa)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.codPlato < mesa.codPlato)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.codPlato != mesa.codPlato)
    {
        Nodo *q = new Nodo;
        q->info = mesa;
        q->sig = p;
        if (p != lista)
            ant->sig = q;
        else
            lista = q;
        p->info.unidades++;
    }
}

void pto3()
{
}