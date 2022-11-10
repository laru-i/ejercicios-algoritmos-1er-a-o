#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*En una empresa se quiere hacer una reestructuración de sus departamentos
administrativos, ofreciendo la posibilidad de cambios voluntarios de
departamentos a sus empleados
Para ello cuenta con los siguientes archivos:
“Empleados.dat”, con un registro por cada empleado de la empresa, ordenado por
número de legajo, según el siguiente diseño:
Número de legajo (int)
Apellido y nombre
Dni
Código de departamento actual
“Vacantes.dat”, con un registro por cada departamento en el que hay vacantes a
ofrecer a los empleados, sin orden, según el siguiente diseño:
Código de departamento (1 a 50)
Cantidad de vacantes
“Postulantes.dat”, con un registro por cada postulación realizada, cada empleado
solo se pudo postular a una vacante, ordenado según se han postulado, con el
siguiente diseño:
Número de legajo
Código de departamento
Se pide desarrollar la metodología necesaria para realizar un algoritmo que
permita:
a) Hacer un listado, ordenado por código de departamento, con todos los
empleados postulados al mismo por orden de llegada (número de legajo,
dni y apellido y nombre).
b) Asignar los postulantes a los departamentos según el orden de llegada y la
cantidad de vacantes requeridas, actualizando el archivo “Empleados.dat”*/

struct ArcVacantes
{
    int vacant, codDep;
};

struct ArcEmpleados
{
    int leg, dni, codDep;
    char nombre[30];
};

struct ArcPostulantes
{
    int leg, codDep;
};

struct NodoCola
{
    NodoCola *sig;
    int leg;
};

struct Datos
{
    int cantVac;
    NodoCola *pri;
    NodoCola *ult;
};

void inicializar(Datos v[]);
void cargarPostulantes(FILE *arch, Datos v[]);
void llenarVector(FILE *arch, Datos v[]);
void ptoAB(FILE *archivo, Datos v[]);
int busquedaBinariaArch(FILE *arch, int bus, ArcEmpleados &par);
void encolar(NodoCola *&pri, NodoCola *&ult, int dato);
int desencolar(NodoCola *&pri, NodoCola *&ult);
void generarArchivoEmpleados();
void generarArchivoPostulantes();
void generarArchivoVacantes();

int main()
{
    cout << "ARCHIVO EMPLEADOS";
    generarArchivoEmpleados();
    // cout << "ARCHIVO VACANTES";
    // generarArchivoVacantes();
    // cout << "ARCHIVO POSTULANTES";
    // generarArchivoPostulantes();

    Datos v[50];
    FILE *archVacantes = fopen("Vacantes.dat", "rb");
    FILE *archPost = fopen("Postulantes.dat", "rb");
    FILE *archEmple = fopen("Empleados.dat", "rb+");

    inicializar(v);
    cargarPostulantes(archPost, v);
    fclose(archPost);
    llenarVector(archVacantes, v);
    fclose(archVacantes);
    ptoAB(archEmple, v);

    fclose(archEmple);

    return 0;
}

void inicializar(Datos v[])
{
    for (int i = 0; i < 50; i++)
    {
        v[i].pri = NULL;
        v[i].ult = NULL;
        v[i].cantVac = 0;
    }
}

void cargarPostulantes(FILE *arch, Datos v[])
{
    ArcPostulantes post;

    fread(&post, sizeof(ArcPostulantes), 1, arch);
    while (!feof(arch))
    {
        encolar(v[post.codDep - 1].pri, v[post.codDep - 1].ult, post.leg);
        fread(&post, sizeof(ArcPostulantes), 1, arch);
    }
}

void llenarVector(FILE *arch, Datos v[])
{
    ArcVacantes vac;

    fread(&vac, sizeof(ArcVacantes), 1, arch);
    while (!feof(arch))
    {
        v[vac.codDep - 1].cantVac = vac.vacant;
        fread(&vac, sizeof(ArcVacantes), 1, arch);
    }
}

void ptoAB(FILE *archivo, Datos v[])
{
    ArcEmpleados emple;
    int legDes, pos;
    for (int i = 0; i < 50; i++)
    {
        cout << "DEP " << i + 1 << endl;
        while (v[i].pri != NULL)
        {
            legDes = desencolar(v[i].pri, v[i].ult);
            pos = busquedaBinariaArch(archivo, legDes, emple);
            if (pos != -1)
            {
                cout << emple.leg << emple.dni << emple.nombre << endl;
                if (v[i].cantVac > 0)
                {
                    emple.codDep = i++;
                    fseek(archivo, pos * sizeof(ArcEmpleados), SEEK_SET);
                    fwrite(&emple, sizeof(ArcEmpleados), 1, archivo);
                    v[i].cantVac--;
                }
            }
            else
                cout << "no hay postulantes" << endl;
        }
    }
}

int busquedaBinariaArch(FILE *arch, int bus, ArcEmpleados &par)
{
    unsigned desde, hasta, medio, cantRegistros;
    int pos = -1;
    desde = 0;
    fseek(arch, 0, SEEK_END);
    cantRegistros = ftell(arch) / sizeof(ArcEmpleados);
    hasta = cantRegistros - 1;
    while (pos == -1 && desde <= hasta)
    {
        medio = (desde + hasta) / 2;
        fseek(arch, medio * sizeof(ArcEmpleados), SEEK_SET);
        fread(&par, sizeof(ArcEmpleados), 1, arch);
        if (par.leg == bus)
            pos = medio;
        else
        {
            if (bus < par.leg)
                hasta = medio - 1;
            else
                desde = medio + 1;
        }
    }
    return pos;
}

void encolar(NodoCola *&pri, NodoCola *&ult, int dato)
{
    NodoCola *p = new NodoCola;
    p->leg = dato;
    p->sig = NULL;
    if (ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult = p;
}

int desencolar(NodoCola *&pri, NodoCola *&ult)
{
    int dato;
    NodoCola *p = pri;
    pri = p->sig;
    dato = p->leg;
    delete p;
    if (pri == NULL)
        ult = NULL;
    return dato;
}

// Archivos
void generarArchivoEmpleados()
{
    FILE *archEmple = fopen("Empleados.dat", "wb");
    if (archEmple == NULL)
        cout << "ERROR" << endl;
    else
    {
        ArcEmpleados emple;

        cout << "ARMANDO ARCHIVO DE EMPLEADOS" << endl;
        cout << "Ingrese el codigo de depto (0 para finalizar): ";
        cin >> emple.codDep;
        while (emple.codDep != 0)
        {
            cout << "Ingrese el dni del empleado: ";
            cin >> emple.dni;
            cout << "Ingrese el numero de legajo del empleado: ";
            cin >> emple.leg;
            cout << "Ingrese nombre y apellido del empleado: ";
            fflush(stdin);
            cin.getline(emple.nombre, 36);

            fwrite(&emple, sizeof(archEmple), 1, archEmple);

            cout << "Ingrese el codigo de depto (0 para finalizar): ";
            cin >> emple.codDep;
        }
        fclose(archEmple);
    }
}

void generarArchivoPostulantes()
{
    FILE *archPost = fopen("Postulantes.dat", "wb");
    if (archPost == NULL)
        cout << "ERROR" << endl;
    else
    {
        ArcPostulantes post;

        cout << "ARMANDO ARCHIVO DE POSTULANTES" << endl;
        cout << "Ingrese el codigo de depto (0 para finalizar): ";
        cin >> post.codDep;
        while (post.codDep != 0)
        {
            cout << "Ingrese el numero de legajo del empleado: ";
            cin >> post.leg;

            fwrite(&post, sizeof(ArcPostulantes), 1, archPost);

            cout << "Ingrese el codigo de depto (0 para finalizar): ";
            cin >> post.codDep;
        }
        fclose(archPost);
    }
}

void generarArchivoVacantes()
{
    FILE *archVacantes = fopen("Vacantes.dat", "wb");
    if (archVacantes == NULL)
        cout << "ERROR" << endl;
    else
    {
        ArcVacantes vac;

        cout << "ARMANDO ARCHIVO DE VACANTES" << endl;
        cout << "Ingrese el codigo de depto (0 para finalizar): ";
        cin >> vac.codDep;
        while (vac.codDep != 0)
        {
            cout << "Ingrese la cantidad de vacantes: ";
            cin >> vac.vacant;

            fwrite(&vac, sizeof(ArcVacantes), 1, archVacantes);

            cout << "Ingrese el codigo de depto (0 para finalizar): ";
            cin >> vac.codDep;
        }
        fclose(archVacantes);
    }
}
