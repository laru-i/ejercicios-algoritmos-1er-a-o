#include <iostream>

using namespace std;

/*
consigna del 9:
Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota

REPETIR EL 9 CON STRUCT
*/
struct Alumnos
{
    int notas, dni;
};

int cargarDatos(Alumnos a[], int n);
void repetir(Alumnos a[], int n);
void burbujeo(Alumnos a[], unsigned t);

int main()
{
    int alum;

    cout << "alumnos a ingresar " << endl;
    cin >> alum;

    Alumnos alumnos[alum];

    cargarDatos(alumnos, alum);
    burbujeo(alumnos, alum);
    repetir(alumnos, alum);
    
    return 0;
}

int cargarDatos(Alumnos a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ingresar nota " << endl;
        cin >> a[i].notas;

        cout << "ingresar dni de alumno " << endl;
        cin >> a[i].dni;
    }
}

void burbujeo(Alumnos a[], unsigned t)
{
    unsigned i = 1, j;
    int aux, auxa;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (a[j].notas > a[j + 1].notas)
            {
                aux = a[j].dni;
                auxa = a[j].notas;
                a[j].dni = a[j + 1].dni;
                a[j].notas = a[j + 1].notas;
                a[j + 1].dni = aux;
                a[j + 1].notas = auxa;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}
void repetir(Alumnos a[], int n)
{
    cout << "los dni de la nota menor " << a[0].notas << " son: ";
    for (int i = 0; i < n; i++)
    {
        if (a[0].notas == a[i].notas)
            cout << a[i].dni << " ";
    }
    cout << "los dni de la nota mayor " << a[n - 1].notas << " son: ";
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[n - 1].notas == a[i].notas)
            cout << a[i].dni << " ";
    }
}