#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el depósito, para realizar las
compras del mes.
Para ello cuenta con dos archivos:
a) StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se encuentra en el local,
con el siguiente diseño:
    a.1) Código de libro            a.2) Título del libro (30 caracteres)
    a.3) Autor (20 caracteres)      a.4) Editorial (20 caracteres)
    a.6) Stock en el local          a.7) Genero ( 10 caracteres

b) StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se encuentra en el
depósito, con el siguiente diseño:
        b.1) Código de libro        b.2) Stock en depósito

Se pcode desarrollar la metodología necesaria para escribir un algoritmo que emita un listado ordenado por código de
libro, con un renglón por cada libro que tenga faltante en stock sea en depósito, local o en ambos lugares, con el siguiente
formato
    Libros faltantes
 Código     Observación
 9999       Falta en depósito
 9999       Falta en local
 9999       Falta en local y en depósito
 Total de libros en falta: 999

*/
void apareo(FILE *stLocal, FILE *stDep);
void generarArchivos();
void mostrarArchivo(FILE *archivo1, FILE *archivo2);
void mostrarArchFinalesActu(FILE *archActu);

struct Stock
{
    int cod, stock;
    char autor[20], editorial[20], titulo[30], genero[10];
};

int main()
{
    // generarArchivos();

    FILE *stockLocal, *stockDep;
    stockLocal = fopen("StockEnLocal.dat", "rb");
    stockDep = fopen("StockEnDeposito.dat", "rb");
    // mostrarArchivo(stockLocal, stockDep);
    apareo(stockLocal, stockDep);

    fclose(stockLocal);
    fclose(stockDep);
}

void apareo(FILE *stLocal, FILE *stDep)
{
    int stockLocal, stockDeposito;
    Stock Stock1, Stock2;
    FILE *actStock;
    actStock = fopen("ActStocks.dat", "wb+");

    fread(&Stock1, sizeof(Stock), 1, stLocal);
    fread(&Stock2, sizeof(Stock), 1, stDep);
    while (!feof(stLocal) && !feof(stDep))
    {
        if (Stock1.cod < Stock2.cod && Stock1.stock == 0)
        {
            fwrite(&Stock1, sizeof(Stock), 1, actStock);
            stockLocal++;
            cout << "Codigo: " << Stock1.cod << "Falta en Local" << endl;
            fread(&Stock1, sizeof(Stock), 1, stLocal);
        }
        else if (Stock1.cod > Stock2.cod && Stock2.stock == 0)
        {
            fwrite(&Stock2, sizeof(Stock), 1, actStock);
            stockDeposito++;
            cout << "Codigo: " << Stock2.cod << "Falta en Deposito" << endl;
            fread(&Stock2, sizeof(Stock), 1, stDep);
        }
        else
        {
            if (Stock1.stock == 0)
            {
                fwrite(&Stock1, sizeof(Stock), 1, actStock);
                stockLocal++;
                fread(&Stock1, sizeof(Stock), 1, stLocal);
            }
            else if (Stock2.stock == 0)
            {
                fwrite(&Stock2, sizeof(Stock), 1, actStock);
                stockDeposito++;
                fread(&Stock2, sizeof(Stock), 1, stDep);
            }
        }
        fread(&Stock1, sizeof(Stock), 1, stLocal);
        fread(&Stock2, sizeof(Stock), 1, stDep);
    }
    while (!feof(stLocal))
    {
        fread(&Stock1, sizeof(Stock), 1, stLocal);
        if (Stock1.stock == 0)
        {
            fwrite(&Stock1, sizeof(Stock), 1, actStock);
            stockLocal++;
            cout << "Codigo: " << Stock1.cod << "Falta en Local" << endl;
        }
    }

    while (!feof(stDep))
    {
        fread(&Stock2, sizeof(Stock), 1, stDep);
        if (Stock2.stock == 0)
        {
            fwrite(&Stock2, sizeof(Stock), 1, actStock);
            stockDeposito++;
            cout << "Codigo: " << Stock2.cod << "Falta en Deposito" << endl;
        }
    }
    cout << "Total en falta: " << stockDeposito + stockLocal << endl;

    fclose(actStock);
    mostrarArchFinalesActu(actStock);
}

void generarArchivos()
{
    FILE *archStockLocal, *archStockDeposito;
    archStockLocal = fopen("StockEnLocal.dat", "wb");
    archStockDeposito = fopen("StockEnDeposito.dat", "wb");
    if (archStockLocal == NULL || archStockDeposito == NULL)
        cout << "ERROR" << endl;
    else
    {
        Stock stock1, stock2;

        cout << "CREANDO ARCHIVO StockEnLocal.DAT" << endl;

        cout << "Ingrese codigo de libro (0 para finalizar) ";
        cin >> stock1.cod;

        while (stock1.cod != 0)
        {
            // cout << "Nombre y Apellido: ";
            // fflush(stdin);
            // cin.getline(stock1.nombreYApellido, 36);
            cout << "Stock del Libro: ";
            cin >> stock1.stock;
            fwrite(&stock1, sizeof(Stock), 1, archStockLocal);
            cout << "Ingrese legajo (0 para finalizar) ";
            cin >> stock1.cod;
        }
        fclose(archStockLocal);

        cout << "CREANDO ARCHIVO StockEnDeposito.DAT" << endl;

        cout << "Ingrese codigo de libro (0 para finalizar) ";
        cin >> stock2.cod;

        while (stock2.cod != 0)
        {
            // cout << "Nombre y Apellido: ";
            // fflush(stdin);
            // cin.getline(stock2.nombreYApellido, 36);
            cout << "Stock del Libro: ";
            cin >> stock2.stock;
            fwrite(&stock2, sizeof(Stock), 1, archStockDeposito);
            cout << "Ingrese legajo (0 para finalizar) ";
            cin >> stock2.cod;
        }
        fclose(archStockDeposito);

        mostrarArchivo(archStockLocal, archStockDeposito);
    }
}

void mostrarArchivo(FILE *archivo1, FILE *archivo2)
{
    archivo1 = fopen("StockEnLocal.dat", "rb");
    archivo2 = fopen("StockEnDeposito.dat", "rb");
    if (archivo1 == NULL || archivo2 == NULL)
        cout << "ERROR" << endl;
    else
    {
        Stock stock1, stock2;

        cout << "ARCHIVO StockEnLocal.DAT" << endl;

        fread(&stock1, sizeof(Stock), 1, archivo1);
        while (!feof(archivo1))
        {
            cout << endl;
            cout << "codigo: " << stock1.cod << "    "
                 << "stock: " << stock1.stock << endl;
            // cout << "a.3 " << stock1.nombreYApellido << endl;
            fread(&stock1, sizeof(Stock), 1, archivo1);
        }
        fclose(archivo1);

        cout << "ARCHIVO StockEnDeposito.DAT" << endl;

        fread(&stock2, sizeof(Stock), 1, archivo2);
        while (!feof(archivo2))
        {
            cout << endl;
            cout << "codigo: " << stock2.cod << "    "
                 << "stock: " << stock2.stock << endl;
            // cout << "a.3 " << stock2.nombreYApellido << endl;
            fread(&stock2, sizeof(Stock), 1, archivo2);
        }
        fclose(archivo2);
    }
}

void mostrarArchFinalesActu(FILE *archActu)
{
    archActu = fopen("ActStocks.dat", "rb");
    if (archActu == NULL)
        cout << "ERROR" << endl;
    else
    {
        Stock stock;

        cout << "ARCHIVO FINALESACT.DAT" << endl;
        fread(&stock, sizeof(Stock), 1, archActu);
        while (!feof(archActu))
        {
            cout << endl;
            cout << "codigo " << stock.cod << "    "
                 << "stock " << stock.stock << endl;
            // cout << "a.3 " << stock.nombreYApellido << endl;
            fread(&stock, sizeof(Stock), 1, archActu);
        }
        fclose(archActu);
    }
}