#include <iostream>

using namespace std;
/*
Dada la lista definida en el ejercicio 1 conteniendo productos repetidos, hacer una función que
deje en la lista un solo nodo por producto con el stock sumado.
*/
struct Producto
{
    int cod, importe, stock;
};

struct Nodo
{
    Nodo *sig;
    Producto info;
};

void insertar(Nodo *&lista, Producto prod);
bool eliminar(Nodo *&lista, int cod);
void cc2(Nodo *lista);
void listar(Nodo *lista);

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

        // cout << "importe" << endl;
        // cin >> prod.importe;

        insertar(lista, prod);

        cout << "codigo (0 fin)" << endl;
        cin >> prod.cod;
    }
    listar(lista);
    cout << " ---------------- " << endl;
    cc2(lista);

    return 0;
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

// CREANDO NUEVA LISTA

void cc2(Nodo *lista) // versión con 2 punteros
{
    Nodo *nuevaLista = NULL;

    Nodo *p, *q;
    p = q = lista;
    while (p != NULL)
    {
        // q=p;
        int suma = 0;
        do
        {
            suma += q->info.stock;
            q = q->sig;
        } while (q != NULL && q->info.cod == p->info.cod);
        p->info.stock = suma;
        insertar(nuevaLista, p->info);
        p = q;
    }
    listar(nuevaLista);
}

// void cc2(Nodo *&lista) // versión con 2 punteros
// {
//     int suma;
//     Nodo *p, *q;
//     p = q = lista;
//     while (p != NULL)
//     {
//         // q=p;
//         suma = 0;
//         do
//         {
//             suma += q->info.stock;
//             q = q->sig;
//             if (q->info.cod == p->info.cod)
//             {
//                 eliminar(lista, p->info.cod);
//                 lista = q;
//                 p = q;
//             }
//         } while (q != NULL && q->info.cod == p->info.cod);
//         p = q;
//     }
//     listar(lista);
// }

bool eliminar(Nodo *&lista, int cod)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.cod != cod)
    {
        ant = p;
        p = p->sig;
    }

    if (p != NULL)
    {
        if (p == lista)
            lista = p->sig;
        else
            ant->sig = p->sig;
        delete p;
        return true;
    }
    else
        return false;
    // cout<<"no existe";
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        cout << p->info.cod << " --- " << p->info.stock << endl;
        p = p->sig;
    }
}
