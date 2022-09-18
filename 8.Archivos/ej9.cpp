#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
Una empresa de canales por cable desea actualizar el archivo de series que emite por sus distintos canales, con
material nuevo. Para ello posee los siguientes archivos:
a) un archivo maestro de series, Series.dat, con un registro con los datos de las series, ordenado ascendente por
Id_Serie, con el siguiente diseño:
        a.1) Id_Serie           a.2) Título de la serie         a.3) Genero
b) otro archivo de novedades de series, NovSeries.dat, con el mismo diseño y orden que el archivo anterior, que
contiene las novedades a incorporar.
Se pide desarrollar la metodología necesaria para escribir un algoritmo que Grabe un archivo maestro de series
actualizado, ActSeries.dat, con el mismo diseño y orden que los anteriores.
*/

struct Serie
{
    int id;
    string titulo, genero;
};

int main()
{
    FILE *aSeries, *nSeries;
    aSeries = fopen("Series.dat", "rb");
    nSeries = fopen("NovSeries.dat", "rb");

    apareo(aSeries, nSeries);

    fclose(aSeries);
    fclose(nSeries);
}

void apareo(FILE *aser, FILE *anser)
{
    Serie serie1, serie2;
    FILE *actSerie;
    actSerie = fopen("ActSeries.DAT", "wb+");

    fread(&serie1, sizeof(Serie), 1, aser);
    fread(&serie2, sizeof(Serie), 1, anser);
    while (!feof(aser) && !feof(anser))
    {
        if (serie1.id < serie2.id)
        {
            fwrite(&serie1, sizeof(Serie), 1, actSerie);
            fread(&serie1, sizeof(Serie), 1, aser);
        }
        else if (serie1.id > serie2.id)
        {
            fwrite(&serie2, sizeof(Serie), 1, actSerie);
            fread(&serie2, sizeof(Serie), 1, anser);
        }
        else
        {
            fwrite(&serie1, sizeof(Serie), 1, actSerie);
            fread(&serie1, sizeof(Serie), 1, aser);
        }
    }
    while (!feof(aser))
    {
        fwrite(&serie1, sizeof(Serie), 1, actSerie);
        fread(&serie1, sizeof(Serie), 1, aser);
    }

    while (!feof(anser))
    {
        fwrite(&serie2, sizeof(Serie), 1, actSerie);
        fread(&serie2, sizeof(Serie), 1, anser);
    }

    fclose(actSerie);
    // mostrarArchactSerieActu(actSerie);
}
