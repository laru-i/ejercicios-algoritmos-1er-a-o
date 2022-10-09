#include <iostream>

using namespace std;
/*
Se tiene ordenada por código de producto una lista simplemente enlazada donde cada nodo
contiene: código, descripción, importe y stock.
Hacer funciones para:
a. dado un entero K, imprimir el k-ésimo elemento.
b. incrementar en un 10% el importe de un producto dado su código.
c. devolver el stock de un producto dado ó cero si no se lo encuentra.
*/
struct Producto
{
    int cod, importe, stock;
    string desc;
};

struct Nodo
{
    Nodo *sig;
    Producto info;
};
void insertar(Nodo *&lista, Producto pro);
void puntoA(Nodo *lista);
void puntoB(Nodo *lista);
int puntoC(Nodo *lista);

int main()
{
    Producto prod;
    Nodo *productos = NULL;
    cin >> prod.cod;
    while (prod.cod != 0)
    {
        cin >> prod.importe;
        cin >> prod.stock;
        insertar(productos, prod);
        cin >> prod.cod;
    }

    puntoA(productos);
    puntoB(productos);
    cout << puntoC(productos);
    return 0;
}

void puntoA(Nodo *lista)
{
    Nodo *p;
    p = lista;
    int num, i = 1;

    cout << "ingrese un valor entero: " << endl;
    cin >> num;

    while (p)
    {
        if (num == i)
            cout << "producto en posición de nro ingresado: " << p->info.cod << endl;
        i++;
        p = p->sig;
    }
}

void puntoB(Nodo *lista)
{
    Nodo *p;
    p = lista;
    int cod, i = 0;
    float agregado, nuevoImporte;

    cout << "ingrese codigo de producto: " << endl;
    cin >> cod;

    while (p)
    {
        if (p->info.cod == cod)
        {
            agregado = p->info.importe * 10 / 100;
            nuevoImporte = p->info.importe + agregado;
            p->info.importe = nuevoImporte;
            cout << "cod: " << p->info.cod << " precio actualizado: " << nuevoImporte << " " << p->info.importe << endl;
        }
        p = p->sig;
    }
}

int puntoC(Nodo *lista)
{
    Nodo *p;
    p = lista;
    int cod, i = 0;

    cout << "ingrese codigo de producto: " << endl;
    cin >> cod;

    while (p)
    {
        if (p->info.cod == cod)
        {
            return p->info.stock;
        }
        else
        {
            return 0;
        }
        p = p->sig;
    }
}

void insertar(Nodo *&lista, Producto pro)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = pro;
    p = lista;
    while (p != NULL && p->info.cod < pro.cod)
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
