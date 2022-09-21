#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
Dado el archivo ‘ALUMNOS.dat’ con los datos personales de alumnos ordenado por legajo, con el siguiente diseño:
    a.1 Legajo                      a.2 Apellido y nombre ( 30 caracteres)
    a.3 Domicilio (20 caracteres)   a.4 Código postal
    a.5 Teléfono (10 caracteres)    a.6 Año de ingreso

Y otro archivo con el mismo orden que el mencionado llamado “NOVEDADES.dat”, con las actualizaciones (altas,
bajas, y modificaciones) a ser aplicadas, donde cada registro contiene además de todos los campos de Alumnos.dat un
código de operación (‘A’: Alta, ‘B’: Baja, ‘M’: Modificación).
Se pide desarrollar todos los pasos necesarios para realizar un programa que genere un archivo actualizado
“ALUMACTU.dat” con el mismo diseño
*/
struct Alumnos
{
    int leg, codPost, año;
    char domicilio[20], nombre[30], tel[10];
};

struct Novedades
{
    int leg, codPost, año;
    char domicilio[20], nombre[30], tel[10], codOperación[1];
};

int main()
{
    FILE *aAlumnos, *aNovedades;
    aAlumnos = fopen("Alumnos.dat", "rb");
    aNovedades = fopen("Novedades.dat", "rb");

    fclose(aAlumnos);
    fclose(aNovedades);

    return 0;
}

void apareo(FILE *alumnos, FILE *novedades)
{
    Alumnos alum1;
    Novedades nov;
    FILE *actAlum;
    actAlum = fopen("AlumAct.dat", "wb");

    fread(&alum1, sizeof(Alumnos), 1, alumnos);
    fread(&nov, sizeof(Novedades), 1, novedades);
    while (!feof(alumnos) && !feof(novedades))
    {
        if (alum1.leg < nov.leg)
        {
            fwrite(&alum1, sizeof(Alumnos), 1, actAlum);
            fread(&alum1, sizeof(Alumnos), 1, alumnos);
        }
        else
        {
            if (alum1.leg == nov.leg)
            {
                if (nov.codOperación == "B")
                {
                    fread(&alum1, sizeof(Alumnos), 1, alumnos);
                    fread(&nov, sizeof(Alumnos), 1, novedades);
                }
                else if (nov.codOperación == "M" || nov.codOperación == "A")
                {
                    fwrite(&nov, sizeof(Novedades), 1, actAlum);
                    fread(&alum1, sizeof(Alumnos), 1, alumnos);
                }
            }
            else
            {
                fwrite(&nov, sizeof(Novedades), 1, actAlum);
                fread(&nov, sizeof(Alumnos), 1, novedades);
            }
        }
    }
    while (!feof(alumnos))
    {
        fwrite(&alum1, sizeof(Alumnos), 1, actAlum);
        fread(&alum1, sizeof(Alumnos), 1, alumnos);
    }
    while (!feof(novedades))
    {
        fwrite(&nov, sizeof(Novedades), 1, actAlum);
        fread(&nov, sizeof(Alumnos), 1, novedades);
    }

    fclose(actAlum);
}
