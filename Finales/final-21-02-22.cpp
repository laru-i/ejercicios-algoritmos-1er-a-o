#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct ArcHisopados
{
    int dni, fechaNac, cantDosis, fechaCont;
    char nombre[10], domicilio[10], tipoTest[10], obraSocial[10], res[2];
};

struct Lista
{
    char obraSocial[10];
    
};

struct NodoL{
    Lista info;
    NodoL *sig;
}

int main()
{

    return 0;
}