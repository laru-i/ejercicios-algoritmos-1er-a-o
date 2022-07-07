#include <iostream>

using namespace std;
/*
Se tiene un vector de productos (cada elemento tiene código, descripción y stock) y otro vector con
los productos recibidos de los proveedores (código, cantidad recibida), ambos ordenados por código
de producto. Se pide actualizar el stock del vector de productos
*/
struct Productos
{
    int cod, codRecibido, stock, cant;
    string desc;
};
struct ProdRecibidos
{
    int cant, cod;
};
int main()
{
    int c, cR;

    cout << "cant de productos a ingresar " << endl;
    cin >> c;
    cout << "cant de productos recibidos " << endl;
    cin >> cR;

    Productos prod[c];
    ProdRecibidos prodRecibidos[cR];

    return 0;
}

void cargarProd()
{
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}