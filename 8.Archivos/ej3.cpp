#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*

Dado el archivo binario generado en el ejercicio 1, que contiene todas las inscripciones del día, y otro con el mismo
diseño que contiene las inscripciones anteriores (FINALES.DAT), desarrolle un programa que agregue al archivo de
inscripciones anteriores el contenido del archivo del día.

*/
struct Inscripcion
{
    int leg, cod, dia, mes, ano;
    char nombre[20], apellido[20];
};

int main()
{
    Inscripcion inscri;
    FILE *archFin = fopen("FINALES.dat", "ab");
    if (archFin == NULL)
        cout << "ERROR" << endl;
    else
    {
        FILE *archDias = fopen("DIAFINALES.dat", "rb");
        if (archDias == NULL)
            cout << "ERROR" << endl;
        else
        {
            fread(&inscri, sizeof(Inscripcion), 1, archDias);
            while (!feof(archDias))
            {
                fwrite(&inscri, sizeof(Inscripcion), 1, archFin);

                fread(&inscri, sizeof(Inscripcion), 1, archDias);
            }
        }
    }
    fclose(archFin);

    return 0;
}
