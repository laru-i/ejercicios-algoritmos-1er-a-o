#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
Se dispone un archivo binario de inscripción de alumnos a exámenes finales MAESTROFINALES.DAT y otro con las
inscripciones del día de hoy DIAFINALES.DAT, ambos ordenados ascendente por número de legajo y código materia
y con el siguiente diseño:
        a.1Nro de legajo         a.2 Código de materia       a.3 ApellidoNombre
Se pide desarrollar un programa que genere un nuevo archivo de inscripciones a finales FINALESACT.DAT
resultante del apareo de los dos archivos anteriores, con el mismo orden y diseño.
*/
void apareo(FILE *aiv, FILE *ain);
void generarArchivos();
void mostrarArchivo(FILE *archivo1, FILE *archivo2);
void mostrarArchFinalesActu(FILE *archActu);

struct Inscripcion
{
    int nroLeg, codMat;
    string nomApe;
};

int main()
{
    // generarArchivos();

    FILE *inscVieja, *inscNueva;
    inscVieja = fopen("MAESTROFINALES.dat", "rb");
    inscNueva = fopen("DIAFINALES.dat", "rb");

    apareo(inscVieja, inscNueva);

    fclose(inscVieja);
    fclose(inscNueva);

    return 0;
}

void apareo(FILE *aiv, FILE *ain)
{
    Inscripcion insc1, insc2;
    FILE *finales;
    finales = fopen("FINALESACT.DAT", "wb+");

    fread(&insc1, sizeof(Inscripcion), 1, aiv);
    fread(&insc2, sizeof(Inscripcion), 1, ain);
    while (!feof(aiv) && !feof(ain))
    {
        if (insc1.nroLeg < insc2.nroLeg)
        {
            fwrite(&insc1, sizeof(Inscripcion), 1, finales);
            fread(&insc1, sizeof(Inscripcion), 1, aiv);
        }
        else if (insc1.nroLeg > insc2.nroLeg)
        {
            fwrite(&insc2, sizeof(Inscripcion), 1, finales);
            fread(&insc2, sizeof(Inscripcion), 1, ain);
        }
        else
        {
            if (insc1.codMat < insc2.codMat)
            {
                fwrite(&insc1, sizeof(Inscripcion), 1, finales);
                fread(&insc1, sizeof(Inscripcion), 1, aiv);
            }
            else
            {
                fwrite(&insc2, sizeof(Inscripcion), 1, finales);
                fread(&insc2, sizeof(Inscripcion), 1, ain);
            }
        }
    }
    while (!feof(aiv))
    {
        fwrite(&insc1, sizeof(Inscripcion), 1, finales);
        fread(&insc1, sizeof(Inscripcion), 1, aiv);
    }

    while (!feof(ain))
    {
        fwrite(&insc2, sizeof(Inscripcion), 1, finales);
        fread(&insc2, sizeof(Inscripcion), 1, ain);
    }

    fclose(finales);
    mostrarArchFinalesActu(finales);
}

void generarArchivos()
{
    FILE *archMFinales, *archDFinales;
    archMFinales = fopen("MAESTROFINALES.dat", "wb");
    archDFinales = fopen("DIAFINALES.dat", "wb");
    if (archMFinales == NULL || archDFinales == NULL)
        cout << "ERROR" << endl;
    else
    {
        Inscripcion inscpM, inscpD;

        cout << "CREANDO ARCHIVO MAESTROFINALES.DAT" << endl;

        cout << "Ingrese legajo (0 para finalizar) ";
        cin >> inscpM.nroLeg;

        while (inscpM.nroLeg != 0)
        {
            // cout << "Nombre y Apellido: ";
            // fflush(stdin);
            // cin.getline(inscpM.nombreYApellido, 36);
            cout << "Codigo de la materia: ";
            cin >> inscpM.codMat;
            fwrite(&inscpM, sizeof(Inscripcion), 1, archMFinales);
            cout << "Ingrese legajo (0 para finalizar) ";
            cin >> inscpM.nroLeg;
        }
        fclose(archMFinales);

        cout << "CREANDO ARCHIVO DIAFINALES.DAT" << endl;

        cout << "Ingrese legajo (0 para finalizar) ";
        cin >> inscpD.nroLeg;
        while (inscpD.nroLeg != 0)
        {
            // cout << "Nombre y Apellido: ";
            // fflush(stdin);
            // cin.getline(inscpD.nombreYApellido, 36);
            cout << "Codigo de la materia: ";
            cin >> inscpD.codMat;
            fwrite(&inscpD, sizeof(Inscripcion), 1, archDFinales);
            cout << "Ingrese legajo (0 para finalizar) ";
            cin >> inscpD.nroLeg;
        }
        fclose(archDFinales);

        mostrarArchivo(archMFinales, archDFinales);
    }
}

void mostrarArchivo(FILE *archivo1, FILE *archivo2)
{
    archivo1 = fopen("MAESTROFINALES.dat", "rb");
    archivo2 = fopen("DIAFINALES.dat", "rb");
    if (archivo1 == NULL || archivo2 == NULL)
        cout << "ERROR" << endl;
    else
    {
        Inscripcion inscpM, inscpD;

        cout << "ARCHIVO MAESTROFINALES.DAT" << endl;

        fread(&inscpM, sizeof(Inscripcion), 1, archivo1);
        while (!feof(archivo1))
        {
            cout << endl;
            cout << "a.1 " << inscpM.nroLeg << "    "
                 << "a.2 " << inscpM.codMat << endl;
            // cout << "a.3 " << inscpM.nombreYApellido << endl;
            fread(&inscpM, sizeof(Inscripcion), 1, archivo1);
        }
        fclose(archivo1);

        cout << "ARCHIVO DIAFINALES.DAT" << endl;

        fread(&inscpD, sizeof(Inscripcion), 1, archivo2);
        while (!feof(archivo2))
        {
            cout << endl;
            cout << "a.1 " << inscpD.nroLeg << "    "
                 << "a.2 " << inscpD.codMat << endl;
            // cout << "a.3 " << inscpD.nombreYApellido << endl;
            fread(&inscpD, sizeof(Inscripcion), 1, archivo2);
        }
        fclose(archivo2);
    }
}

void mostrarArchFinalesActu(FILE *archActu)
{
    archActu = fopen("FINALESACT.dat", "rb");
    if (archActu == NULL)
        cout << "ERROR" << endl;
    else
    {
        Inscripcion inscp;

        cout << "ARCHIVO FINALESACT.DAT" << endl;
        fread(&inscp, sizeof(Inscripcion), 1, archActu);
        while (!feof(archActu))
        {
            cout << endl;
            cout << "a.1 " << inscp.nroLeg << "    "
                 << "a.2 " << inscp.codMat << endl;
            // cout << "a.3 " << inscp.nombreYApellido << endl;
            fread(&inscp, sizeof(Inscripcion), 1, archActu);
        }
        fclose(archActu);
    }
}