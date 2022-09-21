#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
El dueño de un local de venta de juegos para distintas consolas necesita desarrollar un algoritmo que grabe un archivo,
JuegosPorConsola.dat, ordenado por consola, con un solo registro por consola según el siguiente diseño:
        a) Consola (10 caracteres)      b) Cantidad de juegos
Para obtener la información solicitada se cuenta con el archivo Juegos.dat, ordenado por consola, con un registro por
cada juego que se encuentra en el local, con el siguiente diseño:
        1) Código del juego       2) Titulo del Juego (30 caracteres)
        3) Stock en el local      4) Consola (10 caracteres)
*/

struct Juegos
{
    int cod, stock;
    char titulo[30], consola[10];
};
int main()
{
    FILE *aJuegos;
    aJuegos = fopen("Juegos.dat", "rb");

    fclose(aJuegos);

    return 0;
}

void corteControl(FILE *a)
{
    Juegos juego;

    char consola[10];

    FILE *aJuegosConsola;
    aJuegosConsola = fopen("JuegosPorConsola.dat", "wb");

    fread(&juego, sizeof(Juegos), 1, a);
    while (!feof(a))
    {
        strcpy(consola, juego.consola);
        int cont = 0;
        do
        {
            if (juego.consola == consola)
            {
                cont++;
                fwrite(&juego.consola, sizeof(Juegos), 1, aJuegosConsola);
            }
            fread(&juego, sizeof(Juegos), 1, a);
        } while (!feof(a) && juego.consola == consola);
    }
}
