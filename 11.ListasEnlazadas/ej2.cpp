#include <iostream>

using namespace std;
/*
Se tiene lista enlazada donde cada nodo contiene nombre y número de documento de las
personas inscriptas en un curso, ordenada por número de documento. Hacer funciones para:
a. agregar un inscripto al curso, considerar que puede estar la lista vacía o ya contener
información.
b. dar de baja una persona que no concurrirá al curso.
c. imprimir la lista completa.
d. Imprimir la lista en orden inverso (ordenada por documento de mayor a menor)
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
void puntoA(Nodo *&lista, Personas persona);
void puntoB(Nodo *&lista, Personas persona);
void puntoC(Nodo *lista);
void puntoD(Nodo *lista, Personas persona);
void insertar(Nodo *&lista, Personas persona);
bool eliminar(Nodo *&lista, int dni);
void apilar(Nodo *&pila, Personas dato);
void desapilar(Nodo *&pila, Personas &persona);

int main()
{
    Nodo *lista = NULL;
    Personas persona;

    puntoA(lista, persona);
    puntoB(lista, persona);
    puntoC(lista);
    puntoD(lista, persona);

    return 0;
}

void puntoA(Nodo *&lista, Personas persona)
{
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
}

void puntoB(Nodo *&lista, Personas persona)
{
    cout << "ingrese dni a dar de baja" << endl;
    cin >> persona.dni;

    eliminar(lista, persona.dni);
}

void puntoC(Nodo *lista) // listar
{
    Nodo *p;
    p = lista;
    cout << "LISTA DE INSCRIPTOS " << endl;
    while (p != NULL) // p
    {
        cout << p->info.nombre << " " << p->info.dni << endl;
        p = p->sig;
    }
}

void puntoD(Nodo *lista, Personas persona)
{
    Nodo *pila;
    Nodo *p;

    p = lista;
    cout << "LISTA DE INSCRIPTOS EN ORDEN INVERSO " << endl;

    while (p != NULL) // p
    {
        persona = p->info;
        apilar(pila, persona);
        p = p->sig;
    }

    while (pila != NULL)
    {
        desapilar(pila, persona);
        cout << "DNI: " << persona.dni << endl;
    }
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

bool eliminar(Nodo *&lista, int dni)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.dni != dni)
    {
        ant = p;
        p = p->sig;
    }

    if (p != NULL)
    {
        if (p == lista)
            lista = p->sig;
        else
            ant->sig = p->sig;
        delete p;
        return true;
    }
    else
        return false;
    // cout<<"no existe";
}

void apilar(Nodo *&pila, Personas dato)
{

    Nodo *p = new Nodo;
    p->info = dato;
    p->sig = pila;
    pila = p;
}

void desapilar(Nodo *&pila, Personas &persona)
{
    if (pila == NULL)
        cout << "ERROR, la pila esta vacia" << endl;
    else
    {
        Nodo *p;
        p = pila;
        persona = p->info;
        pila = p->sig;
        delete p;
    }
}