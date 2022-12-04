#include <iostream>

using namespace std;

/*
En la facultad se dictarán 15 cursos extraprogramáticos en el segundo semestre. Todos los cursos duran
un mes y se dictará una edición por mes, esto quiere decir que se repite todos los meses.
Primero se ingresarán los cursos, por cada curso se sabe:
código de curso
nombre del curso
cupo para cada edición.
A continuación se ingresan las inscripciones. Por cada inscripción se ingresa:
código de curso
mes en el que quiere realizar el curso (7 a 12)
El ingreso de datos finaliza con código de curso cero.
Si no hay cupo para ese curso en ese mes emitir el mensaje "inscripción rechazada por falta de cupo".
Una vez finalizada la inscripción, el programa debe:
1. Informar la cantidad de inscriptos por cada curso y por cada mes.
2. Informar código de curso y cantidad total de inscriptos, ordenado de mayor a menor por
cantidad total de inscriptos por curso (sin tener en cuenta los meses)
*/

struct Cursos
{
    int cod, cupo, totalIns;
    string nombre;
};

int main()
{
    int m[6][15];
    Cursos v[15];

    return 0;
}

void pto1(int m[][15])
{
    int fila = 15, columna = 6;
    for (int i = 0; i < fila; i++)
    {
        int totalXCurso = 0;
        cout << i + 1 << "nro curso";
        for (int j = 0; j < columna; j++)
            totalXCurso += m[i][j];
        cout << totalXCurso << "total curso";
    }

    for (int j = 0; j < columna; j++)
    {
        int totalXMes = 0;
        cout << j + 7 << "mes";
        for (int i = 0; i < fila; i++)
            totalXMes += m[i][j];
        cout << totalXMes << "total";
    }
}

void pto2(int m[][15], Cursos v[])
{
    int fila = 15, columna = 6, totalInscriptos = 0, pos;
    for (int i = 0; i < fila; i++)
    {
        cout << i + 1 << "nro curso";
        v[i].totalIns = 0;
        for (int j = 0; j < columna; j++)
        {
            pos = buscar(v, 15, i + 1);
            v[pos].totalIns += m[i][j];
        }
    }
    burbujeo(v, 15);
}

void burbujeo(Cursos v[], unsigned t)
{
    unsigned i = 1, j;
    int aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].totalIns < v[j + 1].totalIns)
            {
                aux = v[j].totalIns;
                v[j].totalIns = v[j + 1].totalIns;
                v[j + 1].totalIns = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void ingresoCursos(Cursos v[])
{
    for (int i = 0; i < 15; i++)
    {
        cin >> v[i].cod;

        while (v[i].cod != 0)
        {
            cin >> v[i].cupo;
            cin >> v[i].nombre;
            cin >> v[i].cod;
        }
    }
}

void ingresoInscripciones(Cursos v[], int m[][15])
{
    int cod, mes, pos;
    cin >> cod;

    while (cod != 0)
    {
        pos = buscar(v, 15, cod);

        while (pos == -1)
        {
            cout << "no existe el curso";
            cin >> cod;
            pos = buscar(v, 15, cod);
        }

        cin >> mes;

        if (m[mes - 7][cod] < v[pos].cupo)
            m[mes - 7][cod]++;
        else
            cout << "no hay cupos";
    }

    cin >> mes;
}

int buscar(Cursos v[], int t, int unCod)
{
    int i = 0;
    while (i < t && v[i].cod != unCod)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}