#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
Desarrollar una función que dada una cola de personas (de cada persona se tiene dni y nombre)
y un dni, si esta persona está en la cola, la mueva al último lugar de la misma.
*/

struct Persona
{
    int dni;
    string nombre;
};
struct NodoCola
{
    NodoCola *sig;
    Persona info;
};

void encolar(NodoCola *&pri, NodoCola *&ult, Persona dato);
Persona desencolar(NodoCola *&pri, NodoCola *&ult);
void ej5(NodoCola *pri, NodoCola *ult, int dni);

int main()
{
    NodoCola *pricola = NULL;
    NodoCola *ultcola = NULL;
    Persona pers;

    for (int i = 0; i < 5; i++)
    {
        cout << "dni" << endl;
        cin >> pers.dni;
        cout << "nom" << endl;
        cin >> pers.nombre;
        encolar(pricola, ultcola, pers);
    };

    int dniIngresado;
    cout << "ingrese DNI" << endl;
    cin >> dniIngresado;

    ej5(pricola, ultcola, dniIngresado);
    return 0;
}

void ej5(NodoCola *pri, NodoCola *ult, int dni)
{
    Persona personaPMover, persona;
    Persona priNodo = desencolar(pri, ult);
    encolar(pri, ult, priNodo);

    if (priNodo.dni != dni)
    {
        while (pri->info.dni != priNodo.dni)
        {
            if (pri->info.dni != dni)
            {
                persona = desencolar(pri, ult);
                encolar(pri, ult, persona);
            }
            else
            {
                personaPMover = pri->info;
                desencolar(pri, ult);
            }
        }
        encolar(pri, ult, personaPMover);
    }

    // Para ver el ejercicio resuelto
    while (pri != NULL)
    {
        cout << pri->info.dni << " ";
        desencolar(pri, ult);
    }
}

void encolar(NodoCola *&pri, NodoCola *&ult, Persona dato)
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

Persona desencolar(NodoCola *&pri, NodoCola *&ult)
{
    Persona dato;
    NodoCola *p = pri;
    pri = p->sig;
    dato = p->info;
    delete p;
    if (pri == NULL)
        ult = NULL;
    return dato;
}

/*
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
    NodoCola *pri = new NodoCola;
    NodoCola *ult = new NodoCola;
    int dni;

    for (int i = 0; i < 5; i++)
    {
        cin >> dni;
        encolar(pri, ult, dni);
    };

    nose(pri, ult, dni);
    return 0;
}

void nose(NodoCola *&pri, NodoCola *&ult, int dni)
{
    int dniCola;
    int i = 0;

    do
    {
        dniCola = desencolar(pri, ult);
        if (dniCola != dni)
        {
            encolar(pri, ult, dniCola);
            i++;
        }
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
*/