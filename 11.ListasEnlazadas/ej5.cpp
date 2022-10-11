#include <iostream>

using namespace std;
/*
Dadas dos listas definidas como en el ejercicio 1, conteniendo la información de productos
diferentes manufacturados en dos fábricas, se pide hacer una función que devuelva otra lista
ordenada por código de producto conteniendo la totalidad de la información
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

void apareo(Nodo *lista1, Nodo *lista2);
void listar(Nodo *lista);
void insertar(Nodo *&lista, Producto prod);

int main()
{
    Nodo *lista1 = NULL, *lista2 = NULL;
    Producto prod;

    // LISTA 1
    cout << "CARGANDO LISTA 1" << endl;
    cout << "codigo (0 fin)" << endl;
    cin >> prod.cod;

    while (prod.cod != 0)
    {
        cout << "stock" << endl;
        cin >> prod.stock;

        cout << "importe" << endl;
        cin >> prod.importe;

        insertar(lista1, prod);

        cout << "codigo (0 fin)" << endl;
        cin >> prod.cod;
    }

    // LISTA 2
    cout << "CARGANDO LISTA 2" << endl;
    cout << "codigo (0 fin)" << endl;
    cin >> prod.cod;

    while (prod.cod != 0)
    {
        cout << "stock" << endl;
        cin >> prod.stock;

        cout << "importe" << endl;
        cin >> prod.importe;

        insertar(lista2, prod);

        cout << "codigo (0 fin)" << endl;
        cin >> prod.cod;
    }

    apareo(lista1, lista2);
    return 0;
}

void apareo(Nodo *lista1, Nodo *lista2)
{
    Nodo *p1, *p2, *listaNueva;
    p1 = lista1;
    p2 = lista2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->info.cod < p2->info.cod)
        {
            insertar(listaNueva, p1->info);
            p1 = p1->sig;
        }
        else
        {
            if (p1->info.cod == p2->info.cod)
            {
                p1->info.stock += p2->info.stock;
                insertar(listaNueva, p1->info);
                p1 = p1->sig;
                p2 = p2->sig;
            }
            else
            {
                insertar(listaNueva, p2->info);
                p2 = p2->sig;
            }
        }
    }
    while (p1 != NULL)
    {
        insertar(listaNueva, p1->info);
        p1 = p1->sig;
    }
    while (p2 != NULL)
    {
        insertar(listaNueva, p2->info);
        p2 = p2->sig;
    }
    listar(listaNueva);
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        cout << p->info.cod << "  " << p->info.importe << "  " << p->info.stock << endl;
        p = p->sig;
    }
}

void insertar(Nodo *&lista, Producto prod)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = prod;
    p = lista;
    while (p != NULL && p->info.cod < prod.cod)
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
