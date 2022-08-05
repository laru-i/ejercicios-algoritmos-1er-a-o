#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*

Dado el archivo binario generado en el ejercicio 1, que contiene todas las inscripciones del día, y otro con el mismo 
diseño que contiene las inscripciones anteriores (FINALES.DAT), desarrolle un programa que agregue al archivo de 
inscripciones anteriores el contenido del archivo del día.

*/
void generarArchivo(Inscripcion inscri);

struct Inscripcion
{
    int leg, cod, dia, mes, ano;
    char nombre[20], apellido[20];
};

int main()
{
    Inscripcion inscri;
    generarArchivo(inscri);

    FILE *ae = fopen("DIAFINALES.dat", "rb");
    if (ae == NULL)
        cout << "ERROR" << endl;
    else
    {
        fread(&inscri, sizeof(Inscripcion), 1, ae);
        while (!feof(ae))
        {
            cout << inscri.leg << " " << inscri.cod << " " << inscri.dia << "/" << inscri.mes << "/" << inscri.ano << " " << inscri.nombre << " " << inscri.apellido << endl;
            fread(&inscri, sizeof(Inscripcion), 1, ae);
        }
        fclose(ae);
    }

    return 0;
}

void generarArchivo()
{
    FILE *archParciales;
    archParciales = fopen("DIAFINALES.dat", "wb");
    if (archParciales == NULL)
        cout << "ERROR" << endl;
    else
    {
        Inscripcion inscri;
        cout << "Ingrese legajo (0 para finalizar) ";
        cin >> inscri.leg;
        while (inscri.leg != 0)
        {
            cout << "ingrese nombre y apellido ";
            cin >> inscri.nombre >> inscri.apellido;
            // strcat(inscri.nombre, inscri.apellido);

            cout << "ingrese codigo de materia ";
            cin >> inscri.cod;

            cout << "ingrese dia (numericamente) ";
            cin >> inscri.dia;
            if (inscri.dia < 1 || inscri.dia > 31)
            {
                cout << "error, ingrese dia nuevamente ";
                cin >> inscri.dia;
            }

            cout << "ingrese mes (numericamente) ";
            cin >> inscri.mes;
            if (inscri.mes < 1 || inscri.mes > 12)
            {
                cout << "error, ingrese mes nuevamente ";
                cin >> inscri.mes;
            }

            cout << "ingrese ano (numericamente) ";
            cin >> inscri.ano;

            fwrite(&inscri, sizeof(Inscripcion), 1, archParciales);

            cout << "Ingrese legajo (0 para finalizar) ";
            cin >> inscri.leg;
        }
        fclose(archParciales);
    }
}

void ingreso()
{
    int codMateria;

    cout << "ingrese codigo de materia, 0 para finalizar " << endl;
    cin >> codMateria;

    while (codMateria != 0)
    {
        cout << "ingrese codigo de materia, 0 para finalizar " << endl;
        cin >> codMateria;
    }

    for (int i = 0; i < ; i++)
    {
        if (codMateria == inscri.cod)
        {
            
        }
        
    }
    
    
}