#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*

2) Dado el archivo binario generado en el ejercicio 1, desarrolle un programa que solicitando por teclado un código de
materia permita seleccionar todos los registros de alumnos que se anotaron para rendirla y los grabe en otro archivo
(MATFINALES.DAT), con el mismo diseño.

*/

struct Inscripcion
{
    int leg, cod, dia, mes, ano;
    char nombre[20], apellido[20];
};

int main()
{

    int codMateria;

    cout << "ingrese codigo de materia, 0 para finalizar " << endl;
    cin >> codMateria;

    FILE *arcMat = fopen("MATFINALES.DAT", "wb");
    if (arcMat == NULL)
        cout << "ERROR" << endl;
    FILE *arcDias = fopen("DIAFINALES.dat", "rb");
    if (arcDias == NULL)
        cout << "ERROR" << endl;
    else
    {
        Inscripcion inscri;
        fread(&inscri, sizeof(Inscripcion), 1, arcDias);
        while (!feof(arcDias))
        {
            if (inscri.cod == codMateria)
                fwrite(&inscri, sizeof(Inscripcion), 1, arcMat);

            fread(&inscri, sizeof(Inscripcion), 1, arcDias);
        }
    }
    fclose(arcDias);
    fclose(arcMat);

    return 0;
}
