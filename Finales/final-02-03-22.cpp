#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct ArchivoBuceos
{
    int nroBuzo, edad, fecha, profundidad, tiempo, horaInicio;
    char operadora[20], país[20], sitio[20], dificultad[5];
};

struct InfoSL
{
    int nroBuzo, edad, fecha, profundidad, tiempo, horaInicio;
    char operadora[20], sitio[20], dificultad[5];
};

struct NodoSL
{
    NodoSL *sig;
    InfoSL info;
};

struct Info
{
    char país[20];
    NodoSL *lista;
};

struct Nodo
{
    Nodo *sig;
    Info info;
};

struct Vector
{
    Nodo *sig;
    char operadora[20];
};

int main()
{
    Vector *v[20];
    FILE *arch = fopen("archivo.dat", "rb");

    return 0;
}

void pto2(FILE *arch, Vector *v[])
{
    // inicializar(v);
    ArchivoBuceos datosArch;
    InfoSL infoSL;
    Info info;

    fread(&datosArch, sizeof(ArchivoBuceos), 1, arch);
    while (!feof(arch))
    {
        strcpy(v[0]->operadora, datosArch.operadora);

        //buscarInsertar(v[0], v[0]->operadora);

        strcpy(info.país, datosArch.país);
    }
}
/*
Nodo *buscarInsertar(Vector *&lista, char *operadora)
{
    Vector *p, *ant;
    p = lista;
    while (p != NULL && p->operadora == operadora)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.leg != alu.leg)
    {
        Nodo *q = new Nodo;
        q->info = alu;
        q->sig = p;
        if (p != lista)
            ant->sig = q;
        else
            lista = q;
        return q;
    }
    else
        return p;
    // p->info.nota=alu.nota;
}
*/