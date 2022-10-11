#include <iostream>

using namespace std;
/*
Dada una lista doblemente encadenada de números enganchada solo por el puntero al siguiente
y con todos los punteros al anterior en NULL, se pide hacer una rutina que la recorra y
complete los punteros convenientemente incluyendo el puntero externo para recorrerla de atrás
hacia adelante.
*/

struct Nodo
{
    Nodo *sig, *ant;
    int dato;
};

void insertar(Nodo *&lista, int num);
void ejercicio(Nodo *&lista1, Nodo *&lista2);
void mostrarAsc(Nodo *l);
void mostrarDesc(Nodo *l);
void listar(Nodo *lista);

int main()
{
    int num;
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;

    cout << "num (0 fin)" << endl;
    cin >> num;

    while (num != 0)
    {
        insertar(lista1, num);

        cout << "num (0 fin)" << endl;
        cin >> num;
    }
    listar(lista1);
    ejercicio(lista1, lista2);
    // cout << " --------- ASCENDENTE ------------- " << endl;
    // mostrarAsc(lista1);
    cout << " --------- DESCENDENTE ------------- " << endl;
    mostrarDesc(lista2);

    return 0;
}

void ejercicio(Nodo *&lista1, Nodo *&lista2)
{
    Nodo *p, *ant;
    p = lista1;
    p->ant = NULL;

    while (p->sig != NULL)
    {
        ant = p;
        p = p->sig;
        p->ant = ant;
    }
    lista2 = p;
}

void insertar(Nodo *&lista, int num)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->dato = num;
    p = lista;
    while (p != NULL && p->dato < num)
    {
        ant = p;
        p = p->sig;
    }
    q->sig = p;
    q->ant = NULL;
    if (p != lista)
        ant->sig = q;
    else
        lista = q;
}

void mostrarAsc(Nodo *l)
{
    Nodo *p = l;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->sig;
    }
}

void mostrarDesc(Nodo *l)
{
    Nodo *p = l;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->ant;
    }
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        cout << p->dato << endl;
        p = p->sig;
    }
}
