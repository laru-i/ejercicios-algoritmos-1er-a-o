#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
Se tiene el archivo “Escuelas.dat” con un registro con las escuelas de gestión estatal de un municipio de la provincia.
Cada registro tiene número de escuela, dirección y cantidad total de alumnos. El archivo está ordenado por número de
escuela. Hacer un programa que informe los datos de las escuelas que están entre dos números de escuela ingresados
por teclado. Informar también la cantidad de total de alumnos de las escuelas informadas.
*/

struct Escuelas
{
    int nroE, cant;
    char dire[30];
};

int main()
{
    FILE *aEsc;
    aEsc = fopen("Escuelas.dat", "rb");

    escuelas(aEsc);

    fclose(aEsc);

    return 0;
}

void escuelas(FILE *aesc)
{
    int nro1, nro2;
    Escuelas escuela;

    if (aesc == NULL)
    {
        cout << "error" << endl;
    }
    else
    {
        int nro1, nro2;

        cout << "ingrese dos numeros de esc ";
        cin >> nro1 >> nro2;

        do
        {
            fread(&escuelas, sizeof(Escuelas), 1, aesc);
        } while (escuela.nroE != nro1);

        do
        {
            cout << "Numero de escuela: " << escuela.nroE << endl;
            cout << "Cantidad de Alumnos: " << escuela.cant << endl;
            cout << "Direccion: " << escuela.dire << endl;
            fread(&escuelas, sizeof(Escuelas), 1, aesc);
        } while (escuela.nroE != nro2);
    }
}