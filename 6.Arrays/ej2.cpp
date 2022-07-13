#include <iostream>
#define cf 2
#define cc 5

using namespace std;

/*
Un negocio de ropa, vende sus artículos en distintos talles. Para realizar la facturación se ingresan los precios de cada
artículo y talle que vende:
código de articulo (1..100)
talle (1..5)
precio
También se dispone de un conjunto de ventas a facturar, que se ingresan por teclado con los siguientes
datos:
código de artículo (1..100)
talle (1..5)
unidades vendidas
Las ventas finalizan con un código de artículo negativo.
Desarrollar un algoritmo que:
a) informe el precio de la venta, considerando un descuento del 10% si las unidades vendidas son superiores a
tres más el 21% del IVA.
b) al final del proceso emita el siguiente listado, ordenado por artículo y talle ascendente:
Código de Artículo 999
 Talle Unidades Vendidas
 9 99
 9 99
 Total unidades vendidas artículo 9999999
………………………………………..
Total general de unidades vendidas 999999
*/
void cargarStock(int m[][5], int c, int f);
void mostrarPorFila(int ma[][5], int f, int c);
void ingresarPedido(int m[][5], int c, int f);
void inicializar(int m[][5], int f, int c);
void mostrarPrecio(int p[][5], int u[][5]);

int main()
{
    int mPrecios[cf][cc], mUnidades[cf][cc];

    cargarStock(mPrecios, cc, cf);
    mostrarPorFila(mPrecios, cf, cc);
    inicializar(mUnidades, cf, cc);
    ingresarPedido(mUnidades, cc, cf);
    mostrarPorFila(mUnidades, cf, cc);
    mostrarPrecio(mPrecios, mUnidades);

    return 0;
}

void cargarStock(int m[][5], int c, int f)
{
    int art;
    for (int i = 0; i < cf; i++)
    {
        cout << "ingrese codigo de articulo ";
        cin >> art;
        for (int j = 0; j < cc; j++)
        {
            cout << "ingrese precio del talle " << j + 1 << " del art " << art << " " << endl;
            cin >> m[i][j];
        }
    }
}

void ingresarPedido(int m[][5], int c, int f)
{
    int art, pos;

    do
    {
        cout << "ingrese codigo de articulo del cual desea comprar (numero negativo para finalizar)";
        cin >> art;
        cout << "ingrese talle del art " << art << " " << endl;
        cin >> pos;

        cout << "ingrese cantidad de prendas del talle seleccionado ";
        cin >> m[art - 1][pos - 1];

    } while (art > 0);
}

void mostrarPrecio(int p[][5], int u[][5])
{
    int mult = 0, precio = 0;
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            if (p[i][j] > 0)
            {
                mult = u[i][j] * p[i][j];
            }
            precio += mult;
            
        }
    }
    cout << "el precio total de la venta es " << precio;
}

void listado()
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            cout << "codigo: " << 
        }
    }
}

void mostrarPorFila(int ma[][5], int f, int c)
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
            cout << ma[i][j] << "   ";
        cout << endl;
    }
}

void inicializar(int m[][5], int f, int c)
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
            m[i][j] = 0;
    }
}