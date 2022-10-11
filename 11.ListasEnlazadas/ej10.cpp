#include <iostream>
#include <stdio.h>

using namespace std;
/*
Dada una lista simple de alumnos (n° de documento y nombre) ordenada por documento. De
cada alumno depende una sublista de exámenes rendidos (fecha, código y nota). Hacer una
función que dada la estructura informe número de documento, nombre y promedio de cada
alumno
*/
struct Alumno
{
    int dni;
    string nombre;
    NodoSL *listaExa;
};

struct Examen
{
    int fecha, cod, nota;
};

struct NodoL
{
    NodoL *sig;
    Alumno info;
};

struct NodoSL
{
    NodoL *sig;
    Examen info;
};

void generar(NodoL *&lista);

int main()
{
    NodoSL *listaAlumnos = NULL;

    return 0;
}

void generar(NodoL *&lista)
{
    Alumno alu;
    Examen exa;

    int dniAl, fechaEx, codMateria, notaOb;
    string nomAl;

    NodoL *p;
    cout << "DNI alumno: ";
    cin >> dniAl;
    while (dniAl != 0) // ingresa datos del examen
    {
        cout << "Nombre alumno: ";
        cin >> nomAl;
        cout << "Fecha examen: ";
        cin >> fechaEx;
        cout << "Materia rendida: ";
        cin >> codMateria;
        cout << "Nota: ";
        cin >> notaOb;

        alu.dni = dniAl;
        alu.nombre = nomAl;
        alu.listaExa = NULL;
        p = buscarInsertar(lista, alu);

        exa.fecha = fechaEx;
        exa.cod = codMateria;
        exa.nota = notaOb;
        insertar(p->info.listaExa, exa);

        cout << "DNI alumno: ";
        cin >> dniAl;
    }
}

void insertar(NodoSL *&lista, Examen ex) // ordenado por fecha
{
    NodoSL *n, *p, *ant;
    n = new NodoSL;
    n->info = ex;
    p = lista;
    while (p != NULL && p->info.fecha < ex.fecha)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista)
        ant->sig = n;
    else
        lista = n;
}

NodoL *buscarInsertar(NodoL *&lista, Alumno al)
{
    NodoL *ant, *p = lista;
    while (p != NULL && p->info.dni < al.dni)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && al.dni == p->info.dni)
        return p;
    else
    {
        NodoL *n = new NodoL;
        n->info = al;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}
