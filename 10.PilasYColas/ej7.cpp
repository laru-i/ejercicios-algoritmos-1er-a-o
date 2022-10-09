#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
En una oficina de Aeroparque una secretaria atiende las colas de espera para Montevideo,
Punta del Este y Mar del Plata. Tiene una cola de espera para cada localidad, y en ella registra
nombre y apellido del pasajero y número de documento.
A. Desarrolle una función que, dados los datos del pasajero y el lugar de destino, lo incluya
en la cola de espera correspondiente.
B. Desarrolle una función que, dado el destino y la cantidad de asientos libres de un avión,
retire de la cola de espera a aquellas personas que ahora pueden viajar, e informe los
datos.
*/

struct Pasajero
{
    string nombre;
    int dni;
};
struct NodoCola
{
    NodoCola *sig;
    Pasajero info;
};
void puntoA(NodoCola *priMont, NodoCola *ultMont, NodoCola *priPdE, NodoCola *ultPdE, NodoCola *priMDQ, NodoCola *ultMDQ);
void puntoB(NodoCola *priMont, NodoCola *ultMont, NodoCola *priPdE, NodoCola *ultPdE, NodoCola *priMDQ, NodoCola *ultMDQ);
void encolar(NodoCola *&pri, NodoCola *&ult, Pasajero dato);
Pasajero desencolar(NodoCola *&pri, NodoCola *&ult);

int main()
{
    NodoCola *priMontevideo = NULL, *ultMontevideo = NULL;
    NodoCola *priPDelEste = NULL, *ultPDelEste = NULL;
    NodoCola *priMDQ = NULL, *ultMDQ = NULL;

    /* PARA ARMAR LA COLA DE PASAJEROS (OPCIONAL) */
    Pasajero psj;
    string lugarDeDestino;

    for (int i = 0; i < 4; i++)
    {
        cout << "Ingrese DNI del pasajero: ";
        cin >> psj.dni;
        cout << "Agregar nombre y apellido del pasajero: ";
        cin >> psj.nombre;
        cout << "Ingrese el lugar de destino (MDQ , PDE o MV): ";
        cin >> lugarDeDestino;

        if (lugarDeDestino == "MDQ")
        {
            encolar(priMDQ, ultMDQ, psj);
            cout << "PASAJERO A MDQ PUESTO EN LA COLA DE ESPERA" << endl;
        }
        else if (lugarDeDestino == "PDE")
        {
            encolar(priPDelEste, ultPDelEste, psj);
            cout << "PASAJERO A PDE PUESTO EN LA COLA DE ESPERA" << endl;
        }
        else if (lugarDeDestino == "MV")
        {
            encolar(priMontevideo, ultMontevideo, psj);
            cout << "PASAJERO A MV PUESTO EN LA COLA DE ESPERA" << endl;
        }
    }
    /* ###### */

    puntoA(priMontevideo, ultMontevideo, priPDelEste, ultPDelEste, priMDQ, ultMDQ);
    puntoB(priMontevideo, ultMontevideo, priPDelEste, ultPDelEste, priMDQ, ultMDQ);

    return 0;
}

void puntoA(NodoCola *priMont, NodoCola *ultMont, NodoCola *priPdE, NodoCola *ultPdE, NodoCola *priMDQ, NodoCola *ultMDQ)
{
    Pasajero pas;
    string destino;

    cout << "ingrese nombre: " << endl;
    cin >> pas.nombre;
    cout << "ingrese dni" << endl;
    cin >> pas.dni;
    cout << "ingrese destino (MV, PDE, MDQ)" << endl;
    cin >> destino;

    if (destino == "MV")
    {
        encolar(priMont, ultMont, pas);
        cout << "Pasajero: " << pas.dni << " agregado a la cola de MV" << endl;
    }

    if (destino == "PDE")
    {
        encolar(priPdE, ultPdE, pas);
        cout << "Pasajero: " << pas.dni << " agregado a la cola de PDE" << endl;
    }

    if (destino == "MDQ")
    {
        encolar(priMDQ, ultMDQ, pas);
        cout << "Pasajero: " << pas.dni << " agregado a la cola de MDQ" << endl;
    }
}

void puntoB(NodoCola *priMont, NodoCola *ultMont, NodoCola *priPdE, NodoCola *ultPdE, NodoCola *priMDQ, NodoCola *ultMDQ)
{
    int asientos = 20;
    Pasajero pasajero;

    cout << "PASAJEROS A VOLAR" << endl;
    while (priPdE != NULL)
    {
        int i = 0;
        if (i < asientos)
        {
            pasajero = desencolar(priPdE, ultPdE);
            i++;
            cout << "Pasajero: " << pasajero.dni << " ingresa a vuelo a Pta del Este" << endl;
        }
    }

    while (priMont != NULL)
    {
        int i = 0;
        if (i < asientos)
        {
            pasajero = desencolar(priMont, ultMont);
            i++;
            cout << "Pasajero: " << pasajero.dni << " ingresa a vuelo a Montevideo" << endl;
        }
    }

    while (priMDQ != NULL)
    {
        int i = 0;
        if (i < asientos)
        {
            pasajero = desencolar(priMDQ, ultMDQ);
            i++;
            cout << "Pasajero: " << pasajero.dni << " ingresa a vuelo a MDQ" << endl;
        }
    }
}

void encolar(NodoCola *&pri, NodoCola *&ult, Pasajero dato)
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

Pasajero desencolar(NodoCola *&pri, NodoCola *&ult)
{
    Pasajero dato;
    NodoCola *p = pri;
    pri = p->sig;
    dato = p->info;
    delete p;
    if (pri == NULL)
        ult = NULL;
    return dato;
}