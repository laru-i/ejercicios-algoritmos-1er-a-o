#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
Desarrollar una función que dada una pila y dos valores x e y,
reemplace cada valor igual a y que se encuentre en la pila
por el valor x, retornando la pila modificada
*/
struct Nodo
{
    Nodo *sig;
    int dato;
};

void apilar(Nodo *&pila, int num);
void desapilar(Nodo *&pila, int &num);

int main()
{
    int x, y;
    Nodo *pila = NULL;

    reemplazar(pila, x, y);
    return 0;
}

void reemplazar(Nodo *&pila, int x, int y)
{
    Nodo *pilaNueva = NULL;
    int nro;

    while (pila != NULL)
    {
        desapilar(pila, nro);
        if (nro == y)
            apilar(pilaNueva, x);
        else
            apilar(pilaNueva, nro);
    }
    while (pilaNueva != NULL)
    {
        desapilar(pilaNueva, nro);
        apilar(pila, nro);
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