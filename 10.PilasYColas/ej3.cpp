#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define cantMaxCaract 10
/*
Desarrollar una función que dada una palabra devuelva true si es capicúa y falso en caso
contrario. (usar una pila)
*/
struct Nodo
{
    Nodo *sig;
    char letra;
};

bool capicua(char valor[], int cantTotal);
void apilar(Nodo *&pila, char caracter);
void desapilar(Nodo *&pila, char &caracter);

int main()
{
    char palabra[cantMaxCaract];

    cout << "ingrese palabra (max 10): " << endl;
    cin >> palabra;

    int cantCaract = strlen(palabra);

    if (capicua(palabra, cantCaract))
        cout << "es capicua";
    else
        cout << "no es capicua";

    return 0;
}

bool capicua(char valor[cantMaxCaract], int cantTotal)
{
    Nodo *pila = NULL;
    int i = 0, mitadDeLaPalabra;
    bool cap = false;

    mitadDeLaPalabra = cantTotal / 2;

    for (int i = 0; i < mitadDeLaPalabra; i++)
        apilar(pila, valor[i]);

    int cantIgual = 0, j;

    if (cantTotal % 2 == 0)
        j = mitadDeLaPalabra;
    else
        j = mitadDeLaPalabra + 1;

    while (pila != NULL && pila->letra == valor[j])
    {
        cantIgual++;
        desapilar(pila, valor[j]);
        j++;
    }

    if (mitadDeLaPalabra == cantIgual)
        cap = true;

    return cap;
}

void apilar(Nodo *&pila, char caracter)
{

    Nodo *p = new Nodo;
    p->letra = caracter;
    p->sig = pila;
    pila = p;
}

void desapilar(Nodo *&pila, char &caracter)
{
    if (pila == NULL)
        cout << "ERROR, la pila esta vacia" << endl;
    else
    {
        Nodo *p;
        p = pila;
        caracter = p->letra;
        pila = p->sig;
        delete p;
    }
}