#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
Se tiene el archivo “Medicamentos.dat” con un registro por cada medicamento existente en una farmacia. Cada
registro tiene código, nombre, stock y precio unitario. Hacer un programa que informe los medicamentos con stock
menor a 5 y el stock valorizado.
*/

struct Medicamentos
{
    int cod, stock, precio;
    string nombre;
};

int main()
{

    FILE *aMedic;
    aMedic = fopen("Medicamentos.dat", "rb");

    medicamentos(aMedic);

    fclose(aMedic);

    return 0;
}

void medicamentos(FILE *amed)
{
    Medicamentos medicamento;
    fread(&medicamento, sizeof(Medicamentos), 1, amed);

    while (!feof(amed))
    {
        if (medicamento.stock < 5)
        {
            cout << medicamento.nombre << " tiene stock menor a 5" << endl;
            cout << medicamento.precio << " valor del medicamento" << endl;
        }
        fread(&medicamento, sizeof(Medicamentos), 1, amed);
    }
}