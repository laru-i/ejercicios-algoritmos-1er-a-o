#include <iostream>

using namespace std;
/*
Dada una lista doblemente encadenada de números eliminar los últimos n nodos.
*/

struct Nodo
{
    Nodo *sig, *ant;
    int dato;
};
void mostrarAsc(Nodo *l);
bool eliminar(Nodo *&lista1, Nodo *&lista2);
void insertar(Nodo *&lis1, Nodo *&lis2, int nro);

int main()
{
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    int num;

    cout << "ingrese dato " << endl;
    cin >> num;

    while (num != 0)
    {
        insertar(lista1, lista2, num);
        cout << "ingrese dato " << endl;
        cin >> num;
    }
    mostrarAsc(lista1);
    eliminar(lista1, lista2);
    cout << " ---------------------- " << endl;
    mostrarAsc(lista1);
    return 0;
}

bool eliminar(Nodo *&lista1, Nodo *&lista2)
{
    int num, i = 0;
    cout << "ingrese cant de nodos a eliminar " << endl;
    cin >> num;

    Nodo *p;

    for (int i = 1; i <= num; i++)
    {
        p = lista2->ant;
        p->sig = lista2->sig;
        delete lista2;
        lista2 = p;
    }
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

void insertar(Nodo *&lis1, Nodo *&lis2, int nro)
{
    Nodo *n = new Nodo;
    n->dato = nro;
    if (lis1 == NULL && lis2 == NULL)
    {
        n->sig = NULL;
        n->ant = NULL;
        lis1 = n;
        lis2 = n;
    }
    else
    {
        Nodo *p = lis1;
        while (p != NULL && p->dato < nro)
            p = p->sig;
        if (p == lis1) // p->ant==NULL
        {
            n->sig = p; // n->sig=lis1;
            n->ant = NULL;
            lis1->ant = n;
            lis1 = n;
        }
        else
        {
            if (p == NULL)
            {
                n->sig = NULL; // n->sig=p;
                n->ant = lis2;
                lis2->sig = n;
                lis2 = n;
            }
            else
            {
                /*
                Nodo*ante;
                ante=p->ant;
                n->sig=p;
                n->ant=ante;
                ante->sig=n;
                p->ant=n;
                */
                n->sig = p;
                n->ant = p->ant;
                p->ant->sig = n;
                p->ant = n;
            }
        }
    }
}