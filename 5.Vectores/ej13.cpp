#include <iostream>

using namespace std;
/*
Se tiene un vector de notas (cada elemento tiene nombre del alumnos y nota obtenida)
correspondientes al primer parcial y otro vector del mismo tipo del anterior con las notas
correspondientes al segundo parcial, ambos vectores están ordenados alfabéticamente por nombre.
Se pide hacer un listado ordenado por nombre con la condición obtenida por el alumno en la
materia, según lo siguiente:
- Primer y segundo parcial con nota mayor o igual a 8: PROMOCIÓN
- Primer y segundo parcial con nota mayor o igual a 6: RINDE FINAL
- Primer o segundo parcial con nota menor a 6: RECURSA

struct Alumno
{
    string nombre;
    int nota1, nota2;
};

void cargarDatos(Alumno a[], int cant);
void notafinal(Alumno a[], int cant);
void burbujeo(Alumno v[], unsigned t);

int main()
{
    int cant;

    cout << "cant de alumnos a ingresar " << endl;
    cin >> cant;

    Alumno alumno[cant];

    cargarDatos(alumno, cant);
    burbujeo(alumno, cant);
    notafinal(alumno, cant);

    return 0;
}

void cargarDatos(Alumno a[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        cout << "ingresar nombre del alumno " << endl;
        cin >> a[i].nombre;

        cout << "ingresar nota del primer parcial de " << a[i].nombre << endl;
        cin >> a[i].nota1;

        cout << "ingresar nota del segundo parcial de " << a[i].nombre << endl;
        cin >> a[i].nota2;
    }
}

void burbujeo(Alumno v[], unsigned t)
{
    unsigned i = 1, j;
    string aux;
    int auxa, auxb;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].nombre > v[j + 1].nombre)
            {
                aux = v[j].nombre;
                auxa = v[j].nota1;
                auxb = v[j].nota2;
                v[j].nombre = v[j + 1].nombre;
                v[j].nota1 = v[j + 1].nota1;
                v[j].nota2 = v[j + 1].nota2;
                v[j + 1].nombre = aux;
                v[j + 1].nota1 = auxa;
                v[j + 1].nota2 = auxb;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void notafinal(Alumno a[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        if (a[i].nota1 >= 8 && a[i].nota2 >= 8)
            cout << a[i].nombre << " PROMOCIONO" << endl;

        if (a[i].nota1 >= 6 && a[i].nota2 >= 6 && a[i].nota1 < 8 && a[i].nota2 < 8)
            cout << a[i].nombre << " RINDE FINAL" << endl;

        if (a[i].nota1 < 6 || a[i].nota2 < 6)
            cout << a[i].nombre << " RECURSA" << endl;
    }
}
*/

struct Alumno
{
    string nombre;
    int nota1, nota2;
};

void cargarDatos(Alumno a[], int cant);
void notafinal(Alumno a[], int cant);
void burbujeo(Alumno v[], unsigned t);

int main()
{
    int cant;

    cout << "cant de alumnos a ingresar " << endl;
    cin >> cant;

    Alumno alumno[cant];

    cargarDatos(alumno, cant);
    burbujeo(alumno, cant);
    notafinal(alumno, cant);

    return 0;
}

void cargarDatos(Alumno a[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        cout << "ingresar nombre del alumno " << endl;
        cin >> a[i].nombre;

        cout << "ingresar nota del primer parcial de " << a[i].nombre << endl;
        cin >> a[i].nota1;

        cout << "ingresar nota del segundo parcial de " << a[i].nombre << endl;
        cin >> a[i].nota2;
    }
}

void burbujeo(Alumno v[], unsigned t)
{
    unsigned i = 1, j;
    string aux;
    int auxa, auxb;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j].nombre > v[j + 1].nombre)
            {
                aux = v[j].nombre;
                auxa = v[j].nota1;
                auxb = v[j].nota2;
                v[j].nombre = v[j + 1].nombre;
                v[j].nota1 = v[j + 1].nota1;
                v[j].nota2 = v[j + 1].nota2;
                v[j + 1].nombre = aux;
                v[j + 1].nota1 = auxa;
                v[j + 1].nota2 = auxb;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void notafinal(Alumno a[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        if (a[i].nota1 >= 8 && a[i].nota2 >= 8)
            cout << a[i].nombre << " PROMOCIONO" << endl;

        if (a[i].nota1 >= 6 && a[i].nota2 >= 6 && a[i].nota1 < 8 && a[i].nota2 < 8)
            cout << a[i].nombre << " RINDE FINAL" << endl;

        if (a[i].nota1 < 6 || a[i].nota2 < 6)
            cout << a[i].nombre << " RECURSA" << endl;
    }
}