#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
Dado un archivo binario de productos que contiene 100 registros, y cada registro corresponde a un producto que está
codificado del 1 a 100, ordenado por código de producto con el siguiente diseño:
    código de producto (1..100)           stock
y otro archivo binario de pedidos, con el siguiente diseño:
    número de pedido                   número de cliente
    código de producto (1..100)         cantidad pedida

Se pide desarrollar un algoritmo que:
a) Realice un listado con los pedidos que fueron satisfechos en su totalidad según el siguiente listado
Pedidos Satisfechos
Número de pedido Número de Cliente Código de Producto Cantidad pedida
9999 999999 999 9999
9999 999999 999 9999

b) actualizar el campo stock del archivo de producto, cada vez que acepte un pedido.

c) grabar un archivo binario con el mismo diseño que el archivo de pedidos, con aquellos pedidos que no
pueden ser satisfechos en su totalidad.
*/
struct Producto
{
    int stock, cod;
};

struct Pedido
{
    int numP, numC, cod, cant;
};

void procesarPedido(FILE *aped, FILE *aprod, FILE *apedns);
void procesarUnPedido(Pedido ped, FILE *aprod, FILE *apedns);
void mostrar(Pedido p);

int main()
{
    FILE *aProd, *aPed, *aPedNS;
    aProd = fopen("Productos.dat", "rb+");
    aPed = fopen("Pedidos.dat", "rb");
    aPedNS = fopen("PedidosNS.dat", "wb");

    procesarPedido(aPed, aProd, aPedNS);

    fclose(aProd);
    fclose(aPed);
    fclose(aPedNS);

    return 0;
}
void procesarPedido(FILE *aped, FILE *aprod, FILE *apedns)
{

    Pedido pedido;
    fread(&pedido, sizeof(Pedido), 1, aped);
    while (!feof(aped))
    {
        procesarUnPedido(pedido, aprod, apedns);
        fread(&pedido, sizeof(Pedido), 1, aped);
    }
}

void procesarUnPedido(Pedido ped, FILE *aprod, FILE *apedns)
{
    Producto prod;
    fseek(aprod, (ped.cod - 1) * sizeof(Producto), SEEK_SET);
    fread(&prod, sizeof(Producto), 1, aprod);
    if (ped.cant <= prod.stock)
    {
        prod.stock -= ped.cant;
        fseek(aprod, (ped.cod - 1) * sizeof(Producto), SEEK_SET);
        fwrite(&prod, sizeof(Producto), 1, aprod);
    }
    else {
        fwrite(&ped, sizeof(Pedido), 1, apedns);
    }
}

void mostrarTitulos()
{
  cout << "Numero de pedido       "
       << "Número de Cliente        "
       << "Código de Producto        "
       << "Cantidad pedida       " << endl;
}

void mostrar(Pedido p)
{
  cout << p.numP << "        "
       << p.numC << "        "
       << p.cod << "        "
       << p.cant << endl;
}