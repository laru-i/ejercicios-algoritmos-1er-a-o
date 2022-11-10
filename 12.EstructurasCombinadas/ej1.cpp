#include <iostream>
#include <stdio.h>

using namespace std;
/*
En una empresa de construcción se quiere almacenar en un archivo los importes y
fechas de los materiales comprados para cada una de las obras que está
construcción. Para ello se ingresa por teclado, por cada compra de materiales
realizada: el código de la obra, la fecha y el importe de la compra. Los datos son
ingresados sin orden. Para cada obra se puede haber comprado materiales varias
veces. Se pide generar un archivo secuencial con código de obra, fecha e importe,
ordenado por código de obra y por fecha, con los datos ingresados por teclado
*/

struct Info
{
    int fecha, importe;
};

struct NodoSL
{
    NodoSL *sig;
    Info dato;
};

struct Materiales
{
    int cod;
    NodoSL *listaInfo;
};

struct NodoL
{
    Materiales info;
    NodoL *sig;
};

struct Total
{
    int cod, fecha, importe;
};

void generar(NodoL *&lista);
void insertar(NodoSL *&lista, Info info);
void mostrarArchivo(FILE *archivo1);
NodoL *buscarInsertar(NodoL *&lista, Materiales mat);
void cargarArchivo(NodoL *listaL, NodoSL *listaSL, FILE *a);
void listar(NodoL *lista);

int main()
{
    FILE *aMateriales;
    NodoL *listaL = NULL;
    NodoSL *listaSL = NULL;

    generar(listaL);
    cargarArchivo(listaL, listaSL, aMateriales);

    return 0;
}

void generar(NodoL *&lista) // genero la lista
{
    Materiales material;
    Info info;
    NodoL *p;

    cout << "codigo de obra (cero para finalizar): " << endl;
    cin >> material.cod;

    while (material.cod != 0)
    {
        cout << "fecha de obra: " << endl;
        cin >> info.fecha;
        cout << "importe: " << endl;
        cin >> info.importe;

        material.listaInfo = NULL;
        p = buscarInsertar(lista, material);

        insertar(p->info.listaInfo, info);

        cout << "codigo de obra (cero para finalizar): " << endl;
        cin >> material.cod;
    }
    listar(lista);
}

NodoL *buscarInsertar(NodoL *&lista, Materiales mat)
{
    NodoL *ant, *p = lista;
    while (p != NULL && p->info.cod < mat.cod)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && mat.cod == p->info.cod)
        return p;
    else
    {
        NodoL *n = new NodoL;
        n->info = mat;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}

void mostrarArchivo(FILE *archivo1)
{
    archivo1 = fopen("materiales.dat", "rb");
    if (archivo1 == NULL)
        cout << "ERROR" << endl;
    else
    {
        Total total;
        cout << "ARCHIVO" << endl;

        fread(&total, sizeof(Total), 1, archivo1);
        while (!feof(archivo1))
        {
            cout << endl;
            cout << "codigo: " << total.cod << "    "
                 << "importe: " << total.importe << "    "
                 << "fecha: " << total.fecha << endl;
            fread(&total, sizeof(Total), 1, archivo1);
        }
        fclose(archivo1);
    }
}

void cargarArchivo(NodoL *listaL, NodoSL *listaSL, FILE *a)
{
    NodoL *p = listaL;
    NodoSL *q;

    Total total;

    a = fopen("materiales.dat", "wb");
    if (a == NULL)
        cout << "ERROR" << endl;
    else
    {
        while (p)
        {
            total.cod = p->info.cod;
            q = p->info.listaInfo;

            while (q)
            {
                total.fecha = q->dato.fecha;
                total.importe = q->dato.importe;
                fwrite(&total, sizeof(Total), 1, a);
                q = q->sig;
            }
            p = p->sig;
        }
    }
    fclose(a);

    mostrarArchivo(a);
}

void insertar(NodoSL *&lista, Info info)
{
    NodoSL *q, *p, *ant;
    q = new NodoSL;
    q->dato = info;
    p = lista;
    while (p != NULL && p->dato.fecha < info.fecha)
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

void listar(NodoL *lista)
{
    NodoL *p;
    p = lista;
    NodoSL *q;

    while (p != NULL) // p
    {
        cout << "codigo " << p->info.cod << endl;
        q = p->info.listaInfo;
        while (q)
        {
            cout << "fecha " << q->dato.fecha << endl;
            q = q->sig;
        }
        p = p->sig;
    }
}