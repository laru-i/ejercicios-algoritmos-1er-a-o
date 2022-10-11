#include <iostream>

using namespace std;
/*
Se tiene ordenada por código de producto una lista simplemente enlazada donde cada nodo
contiene: código, descripción, importe y stock.
Hacer funciones para:
a. dado un entero K, imprimir el k-ésimo elemento.
b. incrementar en un 10% el importe de un producto dado su código.
c. devolver el stock de un producto dado ó cero si no se lo encuentra.
*/
struct Producto
{
    int cod, importe, stock;
    string desc;
};

struct Nodo
{
    Nodo *sig;
    Producto info;
};

void puntoA(Nodo *lista);
void puntoB(Nodo *lista);
int puntoC(Nodo *lista);
Nodo *buscar(Nodo *lista, int cod);
void insertar(Nodo *&lista, Producto prod);

int main()
{
    Producto prod;
    Nodo *lista = NULL;

    cout << "codigo (0 fin)" << endl;
    cin >> prod.cod;

    while (prod.cod != 0)
    {
        cout << "stock" << endl;
        cin >> prod.stock;

        cout << "importe" << endl;
        cin >> prod.importe;

        insertar(lista, prod);

        cout << "codigo (0 fin)" << endl;
        cin >> prod.cod;
    }

    puntoA(lista);
    puntoB(lista);
    cout << puntoC(lista);

    return 0;
}

void puntoA(Nodo *lista)
{
    int valor, i = 1;
    Nodo *p;
    p = lista;

    cout << "ingrese un entero" << endl;
    cin >> valor;

    while (p != NULL)
    {
        if (valor == i)
            cout << "nodo en posición " << valor << ": " << p->info.cod << endl;
        i++;
        p = p->sig;
    }
}

void puntoB(Nodo *lista)
{
    int cod;

    cout << "ingrese codigo a incrementar importe " << endl;
    cin >> cod;

    Nodo *p = buscar(lista, cod);
    if (p == NULL)
        cout << "no se encontro codigo";
    else
        p->info.importe = p->info.importe + (p->info.importe / 10);

    cout << "cod: " << p->info.cod << " precio actualizado: " << p->info.importe << endl;
}

int puntoC(Nodo *lista)
{
    int cod;

    cout << "ingrese codigo p/ver stock " << endl;
    cin >> cod;

    Nodo *p = buscar(lista, cod);
    if (p == NULL)
        return 0;
    else
        return p->info.stock;
}

Nodo *buscar(Nodo *lista, int cod)
{
    Nodo *p;
    p = lista;
    while (p != NULL && p->info.cod < cod)
        p = p->sig;
    if (p == NULL || p->info.cod != cod)
        return NULL;
    else
        return p;
}

void insertar(Nodo *&lista, Producto prod)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = prod;
    p = lista;
    while (p != NULL && p->info.cod < prod.cod)
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
