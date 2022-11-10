#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
/*
Una biblioteca necesita un programa que efectúe las altas en el archivo maestro de
libros. Para ello cuenta con:
a) LIBROS.dat, archivo maestro de libros ordenado por código de libro,
con un registro por cada libro, con el siguiente diseño:
    Código de libro (int)
    Título del libro (30 caracteres)
    Apellido del autor (15 caracteres)
    Nacionalidad (int)
    Cantidad de ejemplares
b) NOVEDADES.dat, archivo con los libros a dar de alta sin ningún
orden, con el mismo diseño del archivo maestro.
Se pide realizar la metodología necesaria para que el programa:

1) Genere un nuevo archivo LIBROSACT.dat, con el mismo diseño y orden que el
maestro y con las altas incorporadas.

2) Emitir el siguiente listado, agrupado por nacionalidad y ordenado ascendente
por cantidad total de autores:
Nacionalidad..................... Cantidad Total de autores: 999
Apellido del Autor .............. Cantidad total de títulos: 99
*/

struct Archivos
{
    int codigo, cant;
    char titulo[30], apellido[15];
    int nacionalidad;
};

struct Nodo
{
    Nodo *sig;
    Archivos info;
};

struct DatosSL
{
    int cantTitulos;
    char apellido[15];
};

struct NodoSL
{
    NodoSL *sig;
    DatosSL info;
};

struct DatosL
{
    NodoSL *sublista;
    int nacionalidad, cantAutores;
};

struct NodoL
{
    NodoL *sig;
    DatosL info;
};

void pto1(FILE *arch, Nodo *&lista);
void insertar(Nodo *&lista, Archivos nov);
void apareo(FILE *a1, Nodo *lista, FILE *nuevoArc);
void pto2(FILE *arch, NodoL *&lista);
void insertarLog(NodoL *&lista, NodoL *n);
void ordenar(NodoL *&lista);
void insertarB(NodoSL *&lista, DatosSL datos, NodoL *&listaL);
NodoL *buscarInsertar(NodoL *&lista, DatosL datos);
void listar(NodoL *listaL);
void generarArchivoNovedades();
void generarArchivoLibros();
void mostrarArchivo(FILE *archivo);

int main()
{
    // generarArchivoLibros();
    // generarArchivoNovedades();
    FILE *libros = fopen("LIBROS.DAT", "rb"), *novedades, *actualizados;
    Nodo *lista = NULL;
    NodoL *lista2 = NULL;
    // NodoSL *sublista = NULL;

    pto1(novedades, lista);
    apareo(libros, lista, actualizados);
    mostrarArchivo(actualizados);
    pto2(actualizados, lista2);
    listar(lista2);
    fclose(libros);

    return 0;
}

void pto1(FILE *arch, Nodo *&lista)
{
    arch = fopen("NOVEDADES.dat", "rb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        Archivos nov;

        fread(&nov, sizeof(Archivos), 1, arch);
        while (!feof(arch))
        {
            insertar(lista, nov);
            fread(&nov, sizeof(Archivos), 1, arch);
        }
    }
    fclose(arch);
}

void insertar(Nodo *&lista, Archivos nov)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = nov;
    p = lista;
    while (p != NULL && p->info.codigo < nov.codigo)
    {
        ant = p;
        p = p->sig;
    }
    q->sig = p;
    if (p != lista)
        ant->sig = q;
    else
        lista = q;
}

void apareo(FILE *a1, Nodo *lista, FILE *nuevoArc)
{
    nuevoArc = fopen("LIBROSACT.dat", "wb");
    if (nuevoArc == NULL)
        cout << "ERROR" << endl;
    else
    {
        Nodo *nov = lista;
        Archivos arc;
        fread(&arc, sizeof(Archivos), 1, a1);
        while (!feof(a1) && nov)
        {
            if (arc.codigo < nov->info.codigo)
            {
                fwrite(&arc, sizeof(Archivos), 1, nuevoArc);
                fread(&arc, sizeof(Archivos), 1, a1);
            }
            else
            {
                if (arc.codigo == nov->info.codigo)
                {
                    nov->info.cant += arc.cant;
                    fwrite(&nov->info, sizeof(Archivos), 1, nuevoArc);
                    nov = nov->sig;
                    fread(&arc, sizeof(Archivos), 1, a1);
                }
                else
                {
                    fwrite(&nov->info, sizeof(Archivos), 1, nuevoArc);
                    nov = nov->sig;
                }
            }
        }
        while (!feof(a1))
        {
            fwrite(&arc, sizeof(Archivos), 1, nuevoArc);
            fread(&arc, sizeof(Archivos), 1, a1);
        }
        while (nov)
        {
            fwrite(&nov->info, sizeof(Archivos), 1, nuevoArc);
            nov = nov->sig;
        }
    }
    fclose(nuevoArc);
}

void mostrarArchivo(FILE *archivo)
{
    archivo = fopen("LIBROSACT.dat", "rb");
    if (archivo == NULL)
        cout << "ERROR" << endl;
    else
    {
        cout << "------------------- ARCHIVO --------------------" << endl;

        Archivos arch;

        fread(&arch, sizeof(Archivos), 1, archivo);
        while (!feof(archivo))
        {
            cout << "codigo: " << arch.codigo << endl;
            cout << "nacionalidad: " << arch.nacionalidad << endl;
            cout << "autor: " << arch.apellido << endl;
            cout << "ejemplares: " << arch.cant << endl;

            cout << "-----------------" << endl;
            fread(&arch, sizeof(Archivos), 1, archivo);
        }
        fclose(archivo);
    }
}

void pto2(FILE *arch, NodoL *&lista)
{
    arch = fopen("LIBROSACT.dat", "rb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        Archivos nov;
        DatosL datL;
        DatosSL datSL;
        datSL.cantTitulos = 1;
        datL.cantAutores = 0;
        NodoL *p;

        fread(&nov, sizeof(Archivos), 1, arch);
        while (!feof(arch))
        {
            datL.nacionalidad = nov.nacionalidad;
            datL.sublista = NULL;
            p = buscarInsertar(lista, datL);

            strcpy(datSL.apellido, nov.apellido);
            insertarB(p->info.sublista, datSL, p);

            fread(&nov, sizeof(Archivos), 1, arch);
        }
    }

    fclose(arch);
    ordenar(lista);
}

void insertarLog(NodoL *&lista, NodoL *n)
{
    NodoL *p, *ant;

    p = lista;
    while (p && p->info.cantAutores > n->info.cantAutores)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista)
        ant->sig = n;
    else
        lista = n;
}

void ordenar(NodoL *&lista)
{
    NodoL *listaOrd = NULL;
    NodoL *r;
    while (lista != NULL)
    {
        r = lista;
        lista = lista->sig;
        insertarLog(listaOrd, r);
    }
    lista = listaOrd;
}

void insertarB(NodoSL *&lista, DatosSL datos, NodoL *&listaL)
{
    NodoSL *p, *ant;
    NodoL *w = listaL;
    p = lista;
    while (p != NULL && strcmpi(p->info.apellido, datos.apellido) != 0)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL)
    {
        NodoSL *q = new NodoSL;
        w->info.cantAutores++;
        q->info = datos;
        q->sig = p;
        if (p != lista)
            ant->sig = q;
        else
            lista = q;
    }
    else
        p->info.cantTitulos++;
}

NodoL *buscarInsertar(NodoL *&lista, DatosL datos)
{
    NodoL *p, *ant;
    p = lista;
    while (p != NULL && p->info.nacionalidad > datos.nacionalidad)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.nacionalidad != datos.nacionalidad)
    {
        NodoL *q = new NodoL;
        q->info = datos;
        q->sig = p;
        if (p != lista)
            ant->sig = q;
        else
            lista = q;
        return q;
    }
    else
        return p;
}

void listar(NodoL *listaL)
{
    NodoL *p;
    p = listaL;

    NodoSL *q;
    cout << "--------------------------------------" << endl;
    while (p) // p
    {
        cout << "NACIONALIDAD: " << p->info.nacionalidad << endl;
        cout << "cant total de autores: " << p->info.cantAutores << endl;
        q = p->info.sublista;
        while (q)
        {
            cout << "AUTOR: " << q->info.apellido << endl;
            cout << "cant total de titulos: " << q->info.cantTitulos << endl;
            q = q->sig;
        }
        p = p->sig;
        cout << "-------" << endl;
    }
}
/*
void generarArchivoLibros()
{
    FILE *archLib = fopen("LIBROS.dat", "wb");
    if (archLib == NULL)
        cout << "ERROR" << endl;
    else
    {
        Archivos lib;
        lib.nacionalidad = 0;

        cout << "ARMANDO ARCHIVO LIBROS" << endl;
        cout << "Ingrese el codigo de libro (0 para finalizar): ";
        cin >> lib.codigo;
        while (lib.codigo != 0)
        {
            cout << "Ingrese el titulo del libro (30 caracteres max): ";
            fflush(stdin);
            cin.getline(lib.titulo, 30);

            cout << "Ingrese el apellido del autor (15 caracteres max): ";
            fflush(stdin);
            cin.getline(lib.apellido, 15);

            cout << "Ingrese la cantidad de ejemplares: ";
            cin >> lib.cant;

            cout << "Ingrese la nacionalidad: ";
            cin >> lib.nacionalidad;

            fwrite(&lib, sizeof(Archivos), 1, archLib);

            cout << "Ingrese el codigo de libro (0 para finalizar): ";
            cin >> lib.codigo;
        }
        fclose(archLib);
    }
}

void generarArchivoNovedades()
{
    FILE *archNov = fopen("NOVEDADES.dat", "ab");
    if (archNov == NULL)
        cout << "ERROR" << endl;
    else
    {
        Archivos lib;
        lib.nacionalidad = 0;

        cout << "ARMANDO ARCHIVO NOVEDADES" << endl;
        cout << "Ingrese el codigo de libro (0 para finalizar): ";
        cin >> lib.codigo;
        while (lib.codigo != 0)
        {
            cout << "Ingrese el titulo del libro (30 caracteres max): ";
            fflush(stdin);
            cin.getline(lib.titulo, 30);

            cout << "Ingrese el apellido del autor (15 caracteres max): ";
            fflush(stdin);
            cin.getline(lib.apellido, 15);

            cout << "Ingrese la cantidad de ejemplares: ";
            cin >> lib.cant;

            cout << "Ingrese la nacionalidad: ";
            cin >> lib.nacionalidad;

            fwrite(&lib, sizeof(Archivos), 1, archNov);

            cout << "Ingrese el codigo de libro (0 para finalizar): ";
            cin >> lib.codigo;
        }
        fclose(archNov);
    }
}*/