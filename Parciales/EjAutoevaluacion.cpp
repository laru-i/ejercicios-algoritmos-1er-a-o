#include <iostream>

using namespace std;

struct Curso
{
    int cod;
    string nombre;
    int cupo;
};
// prototipi de funciones
void inicializar(int[][6], int, int); // inicializa la matriz en cero
void sumaFilas(int m[][6], int cf, int cc, int vs[]);
void ordenar(int vt[], Curso vc[], int t); // ordena vt de > a < arrastrando vc
void ingresarCursos(Curso v[], int c);
void ingresarInscripciones(Curso vc[], int m[][6], int cc);
int buscar(Curso v[], int t, int unCod);
void punto1(int m[][6], int cf, int cc, Curso v[]);
void punto2(int vt[], int c, Curso vc[]);

int main()
{
    // declarar variables
    Curso vcursos[15];
    int matInsc[15][6], totCurso[15];

    inicializar(matInsc, 15, 6);
    ingresarCursos(vcursos, 15);                 // agregar argumentos
    ingresarInscripciones(vcursos, matInsc, 15); // agregar argumentos
    punto1(matInsc, 15, 6, vcursos);             // agregar argumentos
    sumaFilas(matInsc, 15, 6, totCurso);
    ordenar(totCurso, vcursos, 15);
    punto2(totCurso, 15, vcursos); // agregar argumentos

    return 0;
}
// funciones
void ingresarCursos(Curso v[], int c)
{
    for (int i = 0; i < c; i++)
    {
        do
            cin >> v[i].cod;
        while (v[i].cod == 0);
        cin >> v[i].nombre;
        cin >> v[i].cupo;
    }
}
void ingresarInscripciones(Curso vc[], int m[][6], int cc)
{
    int curso, mes, pos;
    cin >> curso;
    while (curso != 0)
    {
        pos = buscar(vc, cc, curso);
        if (pos != -1)
        {
            do
                cin >> mes;
            while (mes < 7 || mes > 12);
            if (m[pos][mes - 7] < vc[pos].cupo)
                m[pos][mes - 7]++;
            else
                cout << "inscripci�n rechazada por falta de cupo" << endl;
        }
        cin >> curso;
    }
}
int buscar(Curso v[], int t, int unCod)
{
    int i = 0;
    while (i < t && v[i].cod != unCod)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}
void punto1(int m[][6], int cf, int cc, Curso v[])
{
    for (int i = 0; i < cf; i++)
    {
        cout << "Curso " << v[i].cod << v[i].nombre << endl;
        for (int j = 0; j < cc; j++)
        {
            cout << "Mes " << j + 7 << " inscriptos " << m[i][j] << endl;
        }
    }
}
void sumaFilas(int m[][6], int cf, int cc, int vs[])
{
    for (int i = 0; i < cf; i++)
    {
        vs[i] = 0;
        for (int j = 0; j < cc; j++)
            vs[i] += m[i][j];
    }
}
void punto2(int vt[], int c, Curso vc[])
{
    for (int i = 0; i < c; i++)
        cout << vc[i].cod << vt[i] << endl;
}
