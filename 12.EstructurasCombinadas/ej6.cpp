#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
La ciudad de Buenos Aires requiere un estudio estadístico de infracciones
realizadas por los vehículos en sus calles. Para ello cuenta con un archivo de
infracciones “Infracciones.dat”, ordenado por fecha de la infracción creciente, con
el siguiente diseño:
Patente (7 caracteres)
Fecha de Infracción (int, aammdd)
Código de infracción (int, 1 a 100)
Se desea obtener un listado ordenado por código de infracción decreciente con las
patentes que cometieron más de una vez la misma infracción.
*/

struct arcInfraccion
{
    char patente[7];
    int fecha, codInf;
};

struct Datos
{
    char patente[7];
    int fecha, cont;
};

struct Nodo
{
    Nodo *sig;
    Datos info;
};

void generarArchivo(FILE *arch);
void *buscarInsertar(Nodo *&lista, Datos datos);
void inicializar(Nodo *v[100]);
void ejercicio(FILE *arch, Nodo *v[100]);
void listar(Nodo *v[100]);

int main()
{
    FILE *archInfrac;
    Nodo *v[100];

    // generarArchivo(archInfrac);
    ejercicio(archInfrac, v);

    return 0;
}

void ejercicio(FILE *arch, Nodo *v[100])
{
    arch = fopen("infranzas.dat", "rb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        Datos datos;
        arcInfraccion infra;
        inicializar(v);

        fread(&infra, sizeof(arcInfraccion), 1, arch);
        while (!feof(arch))
        {
            datos.fecha = infra.fecha;
            strcpy(datos.patente, infra.patente);
            buscarInsertar(v[infra.codInf - 1], datos);
            fread(&infra, sizeof(arcInfraccion), 1, arch);
        }
    }
    fclose(arch);
    listar(v);
}

void listar(Nodo *v[100])
{
    Nodo *p;
    for (int i = 99; i >= 0; i--)
    {
        p = v[i];
        while (p != NULL) // p
        {
            cout << "hola";
            if (p->info.cont > 1)
                cout << "la patente " << p->info.patente << " cometio la infraccion, veces:  " << p->info.cont << endl;
            p = p->sig;
        }
    }
}

void *buscarInsertar(Nodo *&lista, Datos datos)
{
    Nodo *p, *ant;
    p = lista;
    int cont = 0;
    while (p != NULL && p->info.patente != datos.patente)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.patente != datos.patente)
    {
        Nodo *q = new Nodo;
        q->info = datos;
        q->sig = p;
        if (p != lista)
            ant->sig = q;
        else
            lista = q;
    }
    else
        p->info.cont++;
}

void inicializar(Nodo *v[100])
{
    for (int i = 0; i < 12; i++)
        v[i] = NULL;
}

/*
void generarArchivo(FILE *arch)
{
    arch = fopen("infranzas.dat", "wb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        arcInfraccion infr;

        cout << "cod inf (0 para finalizar) ";
        cin >> infr.codInf;

        while (infr.codInf != 0)
        {
            cout << "fecha: " << endl;
            cin >> infr.fecha;

            fwrite(&infr, sizeof(arcInfraccion), 1, arch);

            cout << "patente (0 para finalizar) ";
            cin >> infr.patente;

            cout << "cod infraccion (0 para finalizar) ";
            cin >> infr.codInf;
        }
        fclose(arch);
    }
}
*/
