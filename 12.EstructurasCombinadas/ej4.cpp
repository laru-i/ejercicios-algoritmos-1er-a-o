#include <iostream>
#include <stdio.h>

using namespace std;

/*
En un club deportivo barrial se quiere hacer un programa para obtener datos
estadísticos de los atletas que compitieron en el año 2019 en las 15 actividades
deportivas que se practican en el mismo.
Se tiene el archivo “Competidores.dat”, con cada una de las participaciones de los
atletas competencias, sin orden, donde cada registro tiene el siguiente formato:
Código de actividad (1..15)
Número de socio del atleta
Fecha de la competencia (struct dia, mes, anio)
Resultado (int)
Se pide:
a) Informar por cada actividad, por cada mes, cada uno de los atletas que
compitieron y el resultado obtenido, ordenado por código de actividad, por
mes y por número de socio.
b) Informar por cada mes del año el total de atletas que compitieron en cada
actividad.
c) Informar en qué actividad deportiva hubo más de un primer puesto.
*/
struct Fecha
{
    int dia, mes, ano;
};

struct ArchCompetidores
{
    int codAct, nroSocio, resultado;
    Fecha fecha;
};

struct ListaComp
{
    int resultado, nroSocio;
};

struct Nodo
{
    Nodo *sig;
    ListaComp info;
};

void generarArchivo(FILE *arch);
void ptoA(FILE *arch, Nodo *m[15][12]);
void listar(Nodo *m[][12]);
void insertar(Nodo *&lista, ListaComp info);
void inicializarMatriz(Nodo *m[][12]);
void mostrarArchivo(FILE *archivo);
void ptoB(Nodo *m[15][12]);
void ptoC(Nodo *m[15][12]);

int main()
{
    Nodo *m[15][12];
    FILE *archCompetidores;

    // generarArchivo(archCompetidores);
    mostrarArchivo(archCompetidores);
    ptoA(archCompetidores, m);
    ptoB(m);
    ptoC(m);
    return 0;
}

/*
void generarArchivo(FILE *arch)
{
    arch = fopen("Competidores.dat", "wb");

    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        ArchCompetidores comp;

        cout << "cod actividad (0 para finalizar) ";
        cin >> comp.codAct;

        while (comp.codAct != 0)
        {
            cout << "nro socio: ";
            cin >> comp.nroSocio;
            cout << "mes: ";
            cin >> comp.fecha.mes;
            cout << "resultado: ";
            cin >> comp.resultado;
            fwrite(&comp, sizeof(ArchCompetidores), 1, arch);

            cout << "cod actividad (0 para finalizar) ";
            cin >> comp.codAct;
        }
        fclose(arch);
    }
}*/

void ptoA(FILE *arch, Nodo *m[15][12])
{
    arch = fopen("Competidores.dat", "rb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        ArchCompetidores comp;
        ListaComp datosLista;
        inicializarMatriz(m);

        fread(&comp, sizeof(ArchCompetidores), 1, arch);

        while (!feof(arch))
        {
            // Nodo *listaCorresp = m[comp.codAct - 1][comp.fecha.mes - 1];

            datosLista.nroSocio = comp.nroSocio;
            datosLista.resultado = comp.resultado;
            insertar(m[comp.codAct - 1][comp.fecha.mes - 1], datosLista);
            // insertar(listaCorresp, datosLista);
            // m[comp.codAct - 1][comp.fecha.mes - 1] = listaCorresp;

            fread(&comp, sizeof(ArchCompetidores), 1, arch);
        }
        fclose(arch);
        listar(m);
    }
}

void ptoB(Nodo *m[15][12])
{
    cout << "------------------- PUNTO B --------------------" << endl;
    for (int c = 0; c < 12; c++)
    {
        for (int f = 0; f < 15; f++)
        {
            if (m[f][c] != NULL)
            {
                Nodo *p = m[f][c];
                int cont = 0;
                while (p)
                {
                    cont++;
                    p = p->sig;
                }
                cout << "mes"
                     << " actividad "
                     << " atletas en total" << endl;
                cout << c + 1 << "       " << f + 1 << "           " << cont << endl;
            }
        }
    }
}

void ptoC(Nodo *m[15][12])
{
    cout << "------------------- PUNTO C --------------------" << endl;
    for (int f = 0; f < 15; f++)
    {
        for (int c = 0; c < 12; c++)
        {
            if (m[f][c] != NULL)
            {
                Nodo *p = m[f][c];
                int cont = 0;
                while (p)
                {
                    if (p->info.resultado == 1)
                        cont++;
                    p = p->sig;
                }
                if (cont >= 1)
                {
                    cout << " actividad "
                         << " atletas en primer puesto" << endl;
                    cout << "    " << f + 1 << "           " << cont << endl;
                }
            }
        }
    }
}

void listar(Nodo *m[][12])
{
    cout << "------------------- PUNTO A --------------------" << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << "ACTIVIDAD: " << i + 1 << endl;
        for (int j = 0; j < 12; j++)
        {
            cout << "MES: " << j + 1 << endl;
            Nodo *p = m[i][j];

            while (p)
            {
                cout << "nro socio: " << p->info.nroSocio << " ---- resultado: " << p->info.resultado << endl;
                p = p->sig;
            }
        }
    }
}

void mostrarArchivo(FILE *archivo)
{
    archivo = fopen("Competidores.dat", "rb");
    if (archivo == NULL)
        cout << "ERROR" << endl;
    else
    {
        cout << "------------------- ARCHIVO --------------------" << endl;

        ArchCompetidores arch;

        fread(&arch, sizeof(ArchCompetidores), 1, archivo);
        while (!feof(archivo))
        {
            cout << "socio: " << arch.nroSocio << endl;
            cout << "act: " << arch.codAct << endl;
            cout << "mes : " << arch.fecha.mes << endl;
            cout << "res : " << arch.resultado << endl;

            cout << "-------" << endl;
            fread(&arch, sizeof(ArchCompetidores), 1, archivo);
        }
        fclose(archivo);
    }
}

void insertar(Nodo *&lista, ListaComp info)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = info;
    p = lista;
    while (p != NULL && p->info.nroSocio < info.nroSocio)
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

void inicializarMatriz(Nodo *m[][12])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            m[i][j] = NULL;
        }
    }
}