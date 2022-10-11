#include <iostream>

using namespace std;
/*
Dada la lista del ejercicio 1, hacer una función que devuelva dos listas una con los productos
cuyo stock sea inferior a 50 unidades y otra con los restantes.
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

// ej 1
void insertar(Nodo *&lista, Producto pro);

// ej 4
void devolverListas(Nodo *lista);
void listar(Nodo *lista);

int main()
{
    // ej 1
    Producto prod;
    Nodo *productos = NULL;

    cout << "codigo (0 fin)" << endl;
    cin >> prod.cod;

    while (prod.cod != 0)
    {
        cout << "importe" << endl;
        cin >> prod.importe;
        cout << "stock" << endl;
        cin >> prod.stock;

        insertar(productos, prod);
        cout << "codigo (0 fin)" << endl;
        cin >> prod.cod;
    }

    // ej 4
    devolverListas(productos);

    return 0;
}

void devolverListas(Nodo *lista)
{
    Nodo *listaCinco = NULL;
    Nodo *listaRestantes = NULL;

    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        if (p->info.stock < 5)
            insertar(listaCinco, p->info);
        else
            insertar(listaRestantes, p->info);

        p = p->sig;
    }

    cout << "lista menor a 5" << endl;
    listar(listaCinco);
    cout << "restantes" << endl;
    listar(listaRestantes);
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        cout << p->info.stock << " --- " << p->info.cod << endl;
        p = p->sig;
    }
}

// ej 1

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