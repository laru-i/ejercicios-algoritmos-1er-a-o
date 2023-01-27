#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
Desarrolle los siguientes Subprogramas:
a-	Una función que retorne una lista sin orden a partir de la Unión de una pila y una lista.
b-	Un procedimiento que genere una lista ordenada a partir de la INTERSECCION de 2 listas.

Defina usted las estructuras de los nodos de la manera que considere más conveniente y detallar.
-------------------------------
c- SSe tiene un vector de Reservas de los hoteles de la costa “HotelAr” para el verano 2021, que contiene la disponibilidad
de un hotel con los siguientes campos:

-	Código del Hotel
-	Cantidad de Habitaciones
-	Cantidad de días disponibles en la temporada

Además, se cuenta con una lista ordenada que contiene las últimas reservas realizadas, cada nodo de la lista contiene:

-	Código de Hotel
-	Cantidad de días.

Se pide, actualizar el vector Reservas con la información que hay en la lista. Ej: Si en la lista el hotel 1023
tiene 2 días reservados, esos 2 días se deben restar en el campo de Cantidad de días del Vector. Se sabe que cómo
Máximo hay 100 Hoteles.
*/

struct NodoPila
{
    NodoPila *sig;
    int nro;
};

struct NodoL
{
    NodoL *sig;
    int nro;
};

struct vectorHotel
{
    int cod, cantHab, cantDias;
};

struct Hotel
{
    int cod, cantDias;
};

struct Nodo
{
    Nodo *sig;
    Hotel info;
};

int main()
{
    NodoL *lista1 = NULL;
    NodoL *lista2 = NULL;
    NodoL *listaNueva = NULL;
    NodoPila *pila = NULL;
    vectorHotel v[100];
    Nodo *lista = NULL;

    return 0;
}

void ptoA(NodoL *lista, NodoL *&listaNueva, NodoPila *&pila)
{
    int nro;
    while (pila != NULL)
    {
        desapilar(pila, nro);
        insertar(listaNueva, nro);
    }

    NodoL *p = lista;
    while (p)
    {
        insertar(listaNueva, p->nro);
        p = p->sig;
    }
}

void ptoB(NodoL *lista1, NodoL *&listaNueva, NodoL *lista2)
{
    NodoL *p = lista1;
    NodoL *q = lista2;

    NodoL *pos;

    while (p)
    {
        pos = buscar(q, p->nro);
        if (pos != NULL)
        {
            insertar(listaNueva, p->nro);
        }
        p = p->sig;
    }
}

void ptoC(vectorHotel v[100], Nodo *lista)
{
    Nodo *p = lista;
    int pos;

    while (p)
    {
        pos = secuencial(v, p->info.cod);
        if (pos != -1)
        {
            v[pos].cantDias -= p->info.cantDias;
        }
        p = p->sig;
    }
}

NodoL *buscar(NodoL *lista, int unLeg)
{
    NodoL *p;
    p = lista;
    while (p != NULL && p->nro < unLeg)
        p = p->sig;
    if (p == NULL || p->nro != unLeg)
        return NULL;
    else
        return p;
}

void insertar(NodoL *&lista, int nro)
{
    NodoL *q, *p, *ant;
    q = new NodoL;
    q->nro = nro;
    p = lista;
    while (p != NULL && p->nro < nro)
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

void desapilar(NodoPila *&pila, int &num)
{
    if (pila == NULL)
        cout << "ERROR, la pila esta vacia" << endl;
    else
    {
        NodoPila *p;
        p = pila;
        num = p->nro;
        pila = p->sig;
        delete p;
    }
}