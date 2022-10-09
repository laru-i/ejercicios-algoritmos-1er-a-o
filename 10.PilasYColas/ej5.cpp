#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
Desarrollar una función que dada una cola elimine 4 nodos de la misma, y devuelva un valor
true si ello fue posible, de lo contrario un valor falso.
*/
struct NodoCola
{
    NodoCola *sig;
    int info;
};

void encolar(NodoCola *&pri, NodoCola *&ult, int dato);
int desencolar(NodoCola *&pri, NodoCola *&ult);

int main()
{
    NodoCola *cola = NULL;

    return 0;
}

bool eliminar(NodoCola *pri, NodoCola *ult)
{
    int i = 0;
    while (pri != NULL && i < 4)
    {
        desencolar(pri, ult);
        i++;
    }

    return i == 4;
}

void encolar(NodoCola *&pri, NodoCola *&ult, int dato)
{
    NodoCola *p = new NodoCola;
    p->info = dato;
    p->sig = NULL;
    if (ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult = p;
}

int desencolar(NodoCola *&pri, NodoCola *&ult)
{
    int dato;
    NodoCola *p = pri;
    pri = p->sig;
    dato = p->info;
    delete p;
    if (pri == NULL)
        ult = NULL;
    return dato;
}