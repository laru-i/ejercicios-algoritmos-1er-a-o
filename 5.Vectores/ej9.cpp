#include <iostream>

using namespace std;

/*
Dado un vector de notas y un vector de números de documentos paralelo al vector de notas,
informar el dni de los alumnos que tienen la mayor nota y el dni de los alumnos que tienen la menor
nota
*/
int cargarDatos(int notas[], int dni[], int n);
void burbujeo(int v[], int s[], unsigned t);
void repetir(int notas[], int dni[], int n);

int main()
{
    int alum;

    cout << "alumnos a ingresar " << endl;
    cin >> alum;

    int notas[alum], dni[alum];
    cargarDatos(notas, dni, alum);
    burbujeo(notas, dni, alum);

    repetir(notas, dni, alum);
    return 0;
}

int cargarDatos(int notas[], int dni[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ingresar nota " << endl;
        cin >> notas[i];

        cout << "ingresar dni de alumno " << endl;
        cin >> dni[i];
    }
}

void burbujeo(int v[], int s[], unsigned t)
{
    unsigned i = 1, j;
    int aux, auxa;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                auxa = s[j];
                v[j] = v[j + 1];
                s[j] = s[j + 1];
                v[j + 1] = aux;
                s[j + 1] = auxa;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}
void repetir(int notas[], int dni[], int n)
{
    cout << "los dni de la nota menor " << notas[0] << " son: ";
    for (int i = 0; i < n; i++)
    {
        if (notas[0] == notas[i])
            cout << dni[i] << " ";
    }
    cout << "los dni de la nota mayor " << notas[n - 1] << " son: ";
    for (int i = n - 1; i >= 0; i--)
    {
        if (notas[n - 1] == notas[i])
            cout << dni[i] << " ";
    }
}