#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*

1) Se dispone de un conjunto de inscripciones de alumnos a examen en el mes de mayo.
Cada inscripción tiene los siguientes datos: nombre y apellido, número de legajo, código de materia, día, mes y año del
examen. Los datos finalizan con un número de legajo igual a cero.
Desarrollar un programa que a partir del ingreso de las inscripciones por teclado, genere un archivo binario de
inscripción de alumnos a exámenes finales DIAFINALES.DAT, según el siguiente diseño:
a.1 Nro. de legajo a.2 Código de materia
a.3 Día del examen a.4 Mes del examen
a.5 Año del examen a.6 Nombre-Apellido

*/
struct Inscripcion
{
    int leg, cod, dia, mes, ano;
    char nombre[30];
};

int main()
{
    Inscripcion inscri;
    ingreso(inscri);
    generarArchivo(inscri);

    return 0;
}
void ingreso(Inscripcion inscri)
{
    cout << "ingrese legajo, 0 para finalizar ";
    cin >> inscri.leg;

    while (inscri.leg != 0)
    {

        cout << "ingrese nombre y apellido ";
        cin >> inscri.nombre;

        cout << "ingrese codigo de materia ";
        cin >> inscri.cod;

        cout << "ingrese dia, mes y ano ";
        cin >> inscri.dia >> inscri.mes >> inscri.ano;

        cout << "ingrese legajo, 0 para finalizar ";
        cin >> inscri.leg;
    }
}

void generarArchivo(Inscripcion inscri)
{
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
}