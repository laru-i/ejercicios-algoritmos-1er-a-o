#include <iostream>

using namespace std;

/*
Dada una pila sacar los dos elementos del tope y reemplazarlos por uno dado (agregar)
*/
void apilar(Nodo *&pila, Libro dato);
void desapilar(Nodo *&pila, Libro &dato);

struct Libro
{
    string titulo;
    string materia;
};

struct Nodo
{
    Libro info;
    Nodo *sig;
};

int main()
{
    Nodo *pilaLibros = NULL;
    Libro libro;
    for (int i = 1; i < 4; i++)
    {
        cout << "Agregar titulo del libro: ";
        cin >> libro.titulo;
        cout << "Agregar msteria del libro: ";
        cin >> libro.materia;
        apilar(pilaLibros, libro);
    }

    desapilar(pilaLibros, libro);
    desapilar(pilaLibros, libro);

    cout << "Agregar titulo del libro: ";
    cin >> libro.titulo;
    cout << "Agregar msteria del libro: ";
    cin >> libro.materia;
    apilar(pilaLibros, libro);
    return 0;
}

void apilar(Nodo *&pila, Libro dato)
{
    /*
    Nodo*p;
    p=new Nodo;
    */
    Nodo *p = new Nodo;
    p->info = dato;
    p->sig = pila;
    pila = p;
}
void desapilar(Nodo *&pila, Libro &dato)
{
    if (pila == NULL)
        cout << "ERROR, la pila esta vacia" << endl;
    else
    {
        Nodo *p;
        p = pila;
        dato = p->info; // dato=pila->info;
        pila = p->sig;
        // dato=p->info;
        delete p;
    }
}