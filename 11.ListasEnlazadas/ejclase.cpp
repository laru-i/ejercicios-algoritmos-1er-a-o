#include <iostream>

using namespace std;
struct Alumno
{
    string nombre;
    int nota, leg;
};

struct Nodo
{
    Nodo *sig;
    Alumno info;
};

int main()
{

    return 0;
}

void aprobados(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        if (p->info.nota > 6)
            cout << p->info.nombre << " aprobo con nota " << p->info.nota << endl;
        p = p->sig;
    }
}

int promedio(Nodo *lista)
{
    Nodo *p;
    p = lista;
    int suma = 0, i = 0, promedio;
    while (p != NULL) // p
    {
        suma += p->info.nota;
        i++;
        p = p->sig;
    }
    if (i > 0)
        return promedio = suma / i;
    else
        return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        cout << p->info.leg << p->info.nombre << p->info.nota << endl;
        p = p->sig;
    }
}