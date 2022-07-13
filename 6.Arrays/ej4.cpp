#include <iostream>
#define cf 12
#define cc 9

using namespace std;

/*
Se desea desarrollar un sistema de reservas de entradas para un cine.
La sala consta de 12 filas numeradas de la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central,
con las butacas impares a la derecha y las pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9
Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando con la letra D
las disponibles y con la letra R las reservadas.
Por cada reserva se debe solicitar la fila y número de butaca a reservar. Cada vez que se realice una reserva se deberá
actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba ocupada se debe informar al usuario
para que seleccione otra.
El proceso de reserva finaliza con una fila con un número negativo.
Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los números de filas que quedaron vacías.
c. la o las filas con mayor cantidad de espectadores.
*/

void mostrarmatriz(char m[][9]);
void inicializar(char m[][9]);
void ingresarbutacas(char m[][9]);
int cantidad(char m[][9], int c[]);
void mayor(int v[]);
int nrobutaca(int num);
void inicializarvector(int m[]);
void filasvacias(int v[]);

int main()
{
    char matriz[12][9];
    int cant[12];
    inicializar(matriz);
    inicializarvector(cant);
    mostrarmatriz(matriz);
    ingresarbutacas(matriz);
    mostrarmatriz(matriz);
    cantidad(matriz, cant);
    mayor(cant);
    filasvacias(cant);

    return 0;
}

void inicializar(char m[][9])
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
            m[i][j] = 'D';
    }
}

void mostrarmatriz(char m[][9])
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

void ingresarbutacas(char m[][9])
{
    int fila, butaca;
    cout << "ingrese numero de fila (1 al 12) ";
    cin >> fila;
    while (fila > 0)
    {
        cout << "ingrese numero de butaca: 8 6 4 2 1 3 5 7 9" << endl;
        cin >> butaca;

        if (m[fila - 1][nrobutaca(butaca)] == 'R')
        {
            cout << "butaca no disponible, vuelva a ingresarla " << endl;
            cin >> butaca;
        }

        m[fila - 1][nrobutaca(butaca)] = 'R';

        cout << "ingrese numero de fila (1 al 12) ";
        cin >> fila;
    }
}

int cantidad(char m[][9], int c[])
{
    int butTotal = 0;
    for (int i = 0; i < cf; i++)
    {
        int butReservadas = 0;
        for (int j = 0; j < cc; j++)
        {
            if (m[i][j] == 'R')
                butReservadas++;
        }
        c[i] = butReservadas;
    }
    for (int i = 0; i < cf; i++)
        butTotal += c[i];

    cout << "las butacas reservadas son: " << butTotal << endl;
    cout << "las butacas disponibles son: " << (cf * cc) - butTotal << endl;
}

void mayor(int v[])
{
    int mayorV = 0, pos = 0;
    cout << "la fila con más butacas reservadas es ";
    for (int i = 0; i < cf; i++)
    {
        if (v[i] > mayorV)
        {
            mayorV = v[i];
            pos = i;
            cout << pos + 1;
        }
        else if (v[i] == mayorV)
        {
            cout << " y " << i + 1;
        }
    }
    cout << " con " << mayorV << " butacas" << endl;
}

void inicializarvector(int m[])
{
    for (int j = 0; j < cc; j++)
        m[j] = 0;
}

void filasvacias(int v[])
{
    cout << "la fila vacia es ";
    for (int i = 0; i < cf; i++)
    {
        if (v[i] == 0)
            cout << i + 1 << " ";
    }
}

int nrobutaca(int num)
{
    switch (num)
    {
    case 8:
        num = 0;
        break;

    case 6:
        num = 1;
        break;

    case 4:
        num = 2;
        break;

    case 2:
        num = 3;
        break;

    case 1:
        num = 4;
        break;

    case 3:
        num = 5;
        break;

    case 5:
        num = 6;
        break;

    case 7:
        num = 7;
        break;

    case 9:
        num = 8;
        break;
    }
    return num;
}