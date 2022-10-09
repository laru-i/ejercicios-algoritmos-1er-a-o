#include <iostream>

using namespace std;

/*
Desarrollar una función que dada una pila y un valor, inserte ese valor como tercer elemento de
la pila.
*/

struct Nodo
{
    int dato;
    Nodo *sig;
};

void apilar(Nodo *&pila, int num);
void desapilar(Nodo *&pila, int &num);
void insertarValor(Nodo *&pila, int valor, int cant);

int main()
{
    Nodo *pilaLibros = NULL;
    int num, i, nuevoValor = 10;

    for (i = 1; i < 5; i++)
    {
        cout << "Agregar numero: ";
        cin >> num;
        apilar(pilaLibros, num);
    }

    insertarValor(pilaLibros, num, i);

    return 0;
}

void insertarValor(Nodo *&pila, int valor, int cant)
{
    Nodo *nuevaPila = NULL;
    int i = 1;

    for (int i = cant; i <= 3; i--)
    {
        desapilar(pila, valor);
        apilar(nuevaPila, valor);
    }

    apilar(pila, valor);

    while (nuevaPila != NULL)
    {
        desapilar(nuevaPila, valor);
        apilar(pila, valor);
    }
}

void apilar(Nodo *&pila, int num)
{

    Nodo *p = new Nodo;
    p->dato = num;
    p->sig = pila;
    pila = p;
}

void desapilar(Nodo *&pila, int &num)
{
    if (pila == NULL)
        cout << "ERROR, la pila esta vacia" << endl;
    else
    {
        Nodo *p;
        p = pila;
        num = p->dato;
        pila = p->sig;
        delete p;
    }
}