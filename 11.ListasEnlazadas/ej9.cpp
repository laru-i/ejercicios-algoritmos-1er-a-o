#include <iostream>

using namespace std;
/*
Hacer una función que dada una lista circular devuelva la cantidad de nodos que tiene
*/

struct Nodo
{
    Nodo *sig;
    int dato;
};

int ejercicio(Nodo *lista);
void agregar(Nodo *&listaC, int nro);

int main()
{
    Nodo *listaCircular = NULL;
    int num;

    cout << "ingrese dato " << endl;
    cin >> num;

    while (num != 0)
    {
        agregar(listaCircular, num);
        cout << "ingrese dato " << endl;
        cin >> num;
    }

    cout << "nodos en la lista: " << ejercicio(listaCircular);

    return 0;
}

int ejercicio(Nodo *lista)
{
    int i = 0;
    Nodo *p = lista->sig;
    do
    {
        i++;
        p = p->sig;
    } while (p != lista->sig);

    return i;
}

void agregar(Nodo *&listaC, int nro)
{
    // agrega un nodo a la lista circular sin orden
    Nodo *n = new Nodo;
    n->dato = nro;
    if (listaC != NULL)
    {
        n->sig = listaC->sig;
        listaC->sig = n;
    }
    else
    {
        n->sig = n;
        listaC = n;
    }
}