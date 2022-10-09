// Desarrollar una función que dada una cola de personas
// (de cada persona se tiene dni y nombre) y un dni, si esta persona está en la cola, la mueva al último lugar de la misma.
#include <iostream>
#include <stdio.h>

using namespace std;

struct NodoCola
{
    int dni;
    NodoCola *sig;
};

void encolar(NodoCola *&pri, NodoCola *&ult, int dato);
int desencolar(NodoCola *&pri, NodoCola *&ult);
void nose(NodoCola *&pri, NodoCola *&ult, int dni);

void encolar(NodoCola *&pri, NodoCola *&ult, int dato)
{
    NodoCola *p = new NodoCola;
    p->dni = dato;
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
    dato = p->dni;
    delete p;
    if (pri == NULL)
        ult = NULL;
    return dato;
}

int main()
{
    NodoCola *pri = NULL;
    NodoCola *ult = NULL;
    int dni;
    for (int i = 0; i < 5; i++)
    {
        cin >> dni;
        encolar(pri, ult, dni);
    };
    cout << "q dni queres" << endl;
    cin >> dni;
    nose(pri, ult, dni);
    return 0;
}

void nose(NodoCola *&pri, NodoCola *&ult, int dni)
{
    int dniCola = 0;
    int i = 0;

    do
    {
        dniCola = pri->dni;
        desencolar(pri, ult);
        if (dniCola != dni)
        {
            encolar(pri, ult, dniCola);
        }
        i++;
    } while (dniCola != dni);

    for (int j = i; j < 5; j++)
    {
        dniCola = desencolar(pri, ult);
        encolar(pri, ult, dniCola);
    }

    encolar(pri, ult, dni);

    for (int k = 0; k < 5; k++)
    {
        cout << desencolar(pri, ult) << endl;
    }
}