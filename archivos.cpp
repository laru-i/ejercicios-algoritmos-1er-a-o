#include <iostream>
#include <stdio.h>
#include <string.h>

// AGREGAR

char nombArch[21];
cout << "Ingrese el nombre del archivo: ";
cin >> nombArch;
strcat(nombArch, ".dat");

FILE *archParcial = fopen(nombArch, "ab");
if (archParcial == NULL)
    cout << "ERROR" << endl;
else
{
    Parcial parcial;
    cout << "Legajo (cero fin) ";
    cin >> parcial.legajo;
    while (parcial.legajo != 0)
    {
        cout << "Nombre ";
        cin >> parcial.nombre;
        cout << "Nota ";
        cin >> parcial.nota;

        fwrite(&parcial, sizeof(Parcial), 1, archParcial);

        cout << "Legajo (cero fin) ";
        cin >> parcial.legajo;
    }
    fclose(archParcial);
}

// CREAR

FILE *archParciales;
char nomArch[21];
cout << "Nombre archivo (poner al final .dat)" << endl;
cin >> nomArch;
archParciales = fopen(nomArch, "wb");
// archParciales=fopen("Parcial1.dat","wb");
if (archParciales == NULL)
    cout << "ERROR" << endl;
else
{
    Parcial par;
    cout << "Ingrese legajo (0 para finalizar) ";
    cin >> par.legajo;
    while (par.legajo != 0)
    {
        cout << "Nombre: ";
        cin >> par.nombre;
        cout << "Nota: ";
        cin >> par.nota;
        fwrite(&par, sizeof(Parcial), 1, archParciales);
        cout << "Ingrese legajo (0 para finalizar) ";
        cin >> par.legajo;
    }
    fclose(archParciales);
}

// MOSTRAR

char nomArch[21];
cout << "Nombre archivo (poner al final .dat)" << endl;
cin >> nomArch;
FILE *ae = fopen(nomArch, "rb");
// FILE*ae=fopen("Parcial1.dat","rb");
if (ae == NULL)
    cout << "ERROR" << endl;
else
{
    Examen exa;
    fread(&exa, sizeof(Examen), 1, ae);
    while (!feof(ae))
    {
        cout << exa.leg << exa.nom << exa.nota << endl;
        fread(&exa, sizeof(Examen), 1, ae);
    }
    fclose(ae);
}

// MOSTRAR ORDENADO

int cargarVector(Parcial v[], FILE *a, int cme)
{
    Parcial p;
    int i = 0;
    fread(&p, sizeof(Parcial), 1, a);
    while (!feof(a) && i < cme)
    {
        v[i] = p;
        i++;
        fread(&p, sizeof(Parcial), 1, a);
    }
    return i;
}

void ordenar(Parcial v[], unsigned t)
{
    unsigned i = 1, j;
    Parcial aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].legajo > v[j + 1].legajo)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void mostrar(Parcial v[], int t)
{
    for (int i = 0; i < t; i++)
        cout << v[i].legajo << v[i].nombre << v[i].nota << endl;
}

// ORDENAR

int cargarVector(Parcial v[], FILE *a, int cme)
{
    Parcial p;
    int i = 0;
    fread(&p, sizeof(Parcial), 1, a);
    while (!feof(a) && i < cme)
    {
        v[i] = p;
        i++;
        fread(&p, sizeof(Parcial), 1, a);
    }
    return i;
}

void ordenar(Parcial v[], unsigned t)
{
    unsigned i = 1, j;
    Parcial aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].legajo > v[j + 1].legajo)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void mostrar(Parcial v[], int t)
{
    for (int i = 0; i < t; i++)
        cout << v[i].legajo << v[i].nombre << v[i].nota << endl;
}