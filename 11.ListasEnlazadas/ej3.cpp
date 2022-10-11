#include <iostream>

using namespace std;
/*
Hacer una función que devuelva la lista del ejercicio 2 ordenada alfabéticamente
CORTA EL PROGRAMA
*/
struct Personas
{
    string nombre;
    int dni;
};

struct Nodo
{
    Nodo *sig;
    Personas info;
};
void insertar(Nodo *&lista, Personas persona);
void insertarLog(Nodo *&lista, Nodo *n);
void ordenar2(Nodo *&lista);
void listar(Nodo *lista);

int main()
{
    Personas persona;
    Nodo *lista = NULL;

    cout << "ingrese dni (0 fin) p/ agregar inscripto" << endl;
    cin >> persona.dni;

    while (persona.dni != 0)
    {
        cout << "ingrese nombre " << endl;
        cin >> persona.nombre;

        insertar(lista, persona);

        cout << "ingrese dni (0 fin)  p/ agregar inscripto" << endl;
        cin >> persona.dni;
    }

    ordenar2(lista);
    listar(lista);

    return 0;
}

void insertarLog(Nodo *&lista, Nodo *n)
{
    Nodo *r, *ant;

    r = lista;
    while (r != NULL && r->info.nombre < n->info.nombre)
    {
        ant = r;
        r = r->sig;
    }
    n->sig = r;
    if (r != lista)
        ant->sig = n;
    else
        lista = n;
}

void ordenar2(Nodo *&lista)
{
    Nodo *listaOrd = NULL;
    Nodo *r;
    while (lista != NULL)
    {
        r = lista;
        lista = lista->sig;
        insertarLog(listaOrd, r);
    }
    lista = listaOrd;
}

void insertar(Nodo *&lista, Personas persona)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = persona;
    p = lista;
    while (p != NULL && p->info.dni < persona.dni)
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

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        cout << p->info.nombre << " --- " << p->info.dni << endl;
        p = p->sig;
    }
}
