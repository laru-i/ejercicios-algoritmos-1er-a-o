#include <iostream>
#include <stdio.h>
#include <string.h>

#define niveles 8
#define idiomas 6

using namespace std;

struct Clase
{
    int codigo, cupos, dniProfe, nivel;
    char nombre[25];
};

void inicializarMatriz(Clase m[niveles][idiomas]);
void ingresoDatosCurso(Clase m[niveles][idiomas]);
int numeroDeIdioma(char i[]);
string idiomaString(int i);
void burbujeo(Clase v[niveles][idiomas]);
void mostrarMatriz(Clase m[niveles][idiomas]);
void copiarMatriz(Clase[niveles][idiomas], Clase[niveles][idiomas]);
void punto1(Clase matClase[niveles][idiomas]);
void punto2(Clase matClase[niveles][idiomas]);
void punto3(Clase matClase[niveles][idiomas]);
void punto4(Clase matClase[niveles][idiomas]);

int main()
{
    Clase matClases[niveles][idiomas];
    inicializarMatriz(matClases);
    ingresoDatosCurso(matClases);
    punto1(matClases);
    punto2(matClases);
    punto3(matClases);
    punto4(matClases);
}

void inicializarMatriz(Clase m[niveles][idiomas])
{
    for (int i = 0; i < niveles; i++)
        for (int j = 0; j < idiomas; j++)
            m[i][j].codigo = 0;
}

void mostrarMatriz(Clase m[niveles][idiomas])
{
    for (int i = 0; i < niveles; i++)
    {
        for (int j = 0; j < idiomas; j++)
        {
            cout << m[i][j].codigo << " ";
        }
        cout << endl;
    }
}

void ingresoDatosCurso(Clase m[niveles][idiomas])
{
    int codigo, numIdioma, nivel;
    char idioma[20];

    cout << "Ingresar codigo del curso (finaliza con 0): ";
    cin >> codigo;

    while (codigo != 0)
    {
        do
        {
            cout << "Ingresar idioma: ";
            cin >> idioma;
            numIdioma = numeroDeIdioma(idioma);
            while (numIdioma == -1)
            {
                cout << "Ingrese un idioma valido: ";
                cin >> idioma;
                numIdioma = numeroDeIdioma(idioma);
            }

            cout << "Ingresar nivel (de 1 a 8) : ";
            cin >> nivel;
            while (nivel < 1 || nivel > 8)
            {
                cout << "El nivel ingresado no es valido, ingrese otro ";
                cin >> nivel;
            }

            if (m[nivel - 1][numIdioma].codigo != 0)
                cout << "Ya existe un curso" << endl;

        } while (m[nivel - 1][numIdioma].codigo != 0);

        m[nivel - 1][numIdioma].codigo = codigo;
        m[nivel - 1][numIdioma].nivel = nivel;

        cout << "Ingresar cantidad de cupos disponibles: ";
        cin >> m[nivel - 1][numIdioma].cupos;
        while (m[nivel - 1][numIdioma].cupos < 0)
        {
            cout << "La cantidad de cupos ingresados no es valida, debe ser mayor a 0, ingrese otra ";
            cin >> m[nivel - 1][numIdioma].cupos;
        }

        cout << "Ingresar DNI del profesor: ";
        cin >> m[nivel - 1][numIdioma].dniProfe;
        while (m[nivel - 1][numIdioma].dniProfe < 0)
        {
            cout << "Debe ingresar un DNI mayor a 0, ingrese otro ";
            cin >> m[nivel - 1][numIdioma].dniProfe;
        }

        cout << "Ingresar nombre del profesor: ";
        cin >> m[nivel - 1][numIdioma].nombre;

        cout << "Ingresar codigo del curso (finaliza con 0): ";
        cin >> codigo;
    }
}

void punto1(Clase matClase[niveles][idiomas])
{
    char idioma[20];
    Clase oMatClase[niveles][idiomas];
    copiarMatriz(oMatClase, matClase);
    burbujeo(oMatClase);
    mostrarMatriz(matClase);
    for (int k = 0; k < idiomas; k++)
    {
        switch (k)
        {
        case 0:
            strcpy(idioma, "Ingles.dat");
            break;
        case 1:
            strcpy(idioma, "Frances.dat");
            break;
        case 2:
            strcpy(idioma, "Portugues.dat");
            break;
        case 3:
            strcpy(idioma, "Italiano.dat");
            break;
        case 4:
            strcpy(idioma, "Aleman.dat");
            break;
        case 5:
            strcpy(idioma, "Chino.dat");
            break;
        }

        FILE *archCurso = fopen(idioma, "wb");
        if (archCurso == NULL)
            cout << "ERROR" << endl;
        else
        {
            for (int i = 0; i < niveles; i++)
                if (oMatClase[i][k].codigo != 0)
                    fwrite(&oMatClase[i][k], sizeof(Clase), 1, archCurso);
        }
        fclose(archCurso);
    }
    cout << endl;
}

void punto2(Clase matClase[niveles][idiomas])
{
    for (int i = 0; i < idiomas; i++)
    {
        int cantCursos = 0;
        for (int j = 0; j < niveles; j++)
        {
            if (matClase[j][i].codigo != 0)
                cantCursos++;
        }
        cout << "La cantidad de cursos que se dictaran del idioma " << idiomaString(i) << " es: " << cantCursos << endl;
    }
    cout << endl;
}

void punto3(Clase matClase[niveles][idiomas])
{
    for (int i = 0; i < idiomas; i++)
    {
        int j = 0;
        for (j; j < niveles; j++)
        {
            if (matClase[j][i].codigo == 0)
                j = niveles;
        }
        if (j == niveles)
            cout << "El idioma " << idiomaString(i) << " tiene cursos en los ocho niveles" << endl;
    }
    cout << endl;
}

void punto4(Clase matClase[niveles][idiomas])
{
    bool v = false;
    for (int i = 0; i < niveles; i++)
    {
        v = true;
        for (int j = 0; j < idiomas; j++)
        {
            if (matClase[i][j].codigo != 0)
            {
                v = false;
                break;
            }
        }
        if (v)
            cout << "En el nivel " << i + 1 << " No se dictaran clases" << endl;
    }
}

int numeroDeIdioma(char i[])
{
    if (strcmpi(i, "ingles") == 0)
        return 0;
    else if (strcmpi(i, "frances") == 0)
        return 1;
    else if (strcmpi(i, "portugues") == 0)
        return 2;
    else if (strcmpi(i, "italiano") == 0)
        return 3;
    else if (strcmpi(i, "aleman") == 0)
        return 4;
    else if (strcmpi(i, "chino") == 0)
        return 5;
    else
        return -1;
}

string idiomaString(int i)
{
    string idioma;
    switch (i)
    {
    case 0:
        idioma = "Ingles";
        break;
    case 1:
        idioma = "Frances";
        break;
    case 2:
        idioma = "Portugues";
        break;
    case 3:
        idioma = "Italiano";
        break;
    case 4:
        idioma = "Aleman";
        break;
    case 5:
        idioma = "Chino";
        break;
    }
    return idioma;
}

void burbujeo(Clase v[niveles][idiomas])
{
    Clase aux;
    bool cambio;
    for (int k = 0; k < idiomas; k++)
    {
        unsigned i = 1;
        do
        {
            cambio = false;
            for (int j = 0; j < niveles - i; j++)
            {
                if (v[j][k].codigo > v[j + 1][k].codigo)
                {
                    aux = v[j][k];
                    v[j][k] = v[j + 1][k];
                    v[j + 1][k] = aux;
                    cambio = true;
                }
            }
            i++;
        } while (i < niveles && cambio);
    }
}

void copiarMatriz(Clase oMatClase[niveles][idiomas], Clase matClase[niveles][idiomas])
{
    for (int i = 0; i < niveles; i++)
        for (int j = 0; j < idiomas; j++)
            oMatClase[i][j] = matClase[i][j];
}

// Queda probar si se llena bien el archivo trayendo los datos