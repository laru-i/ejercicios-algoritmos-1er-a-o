#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/* Una aplicación para descargas de Series por la red posee la información en un 
archivo binario, Episodios.dat, con un registro por cada episodio, ordenado 
ascendente por IdSerie y Número de temporada, con el siguiente diseño:
    1) IdSerie               2) Título del episodio (20 caracteres)
    3) Número de temporada   4) Número de episodio
    5) Cantidad de descargas 6) Fecha de última descarga (aaaammdd)
Se pide desarrollar la metodología necesaria para escribir un algoritmo emita el 
siguiente listado:
Listado de Descargas de Series
 Serie: 999999999
 Temporada: 99
 N. de Episodio - Título del Episodio - Cant. descargas - Fecha de última descarga
 999               xxxxxxxxxxxxxx           9999999            dd/mm/aaaa
 999               xxxxxxxxxxxxxx           9999999            dd/mm/aaaa
 ………………………………………………………………………….
 *Cant. Total de Episodios de la Temporada: 99999
 *Total descargas de la temporada:999999999

 Serie: 999999999
 Temporada: 99
 N. de Episodio - Título del Episodio - Cant. descargas - Fecha de última descarga
 999               xxxxxxxxxxxxxx           9999999            dd/mm/aaaa
 999               xxxxxxxxxxxxxx           9999999            dd/mm/aaaa
 ………………………………………………………………………….
 *Cant. Total de Episodios de la temporada: 99999
 *Total descargas de la temporada: 999999999
 **Cant. Total de Episodios de la Serie: 99999
 **Total descargas de la Serie: 999999999
……………………………………………………………………………………………………..
***Total General de series: 9999
*/

struct Serie
{
    int id, tempor, episod, descarg, fecUltDesc;
    char titulo[20];
};
int main()
{

    return 0;
}

void corteControl(FILE *a)
{
    Serie serie;
    int s, c, idS;
    fread(&serie, sizeof(Serie), 1, a);
    while (!feof(a))
    {
        idS = serie.id;
        s = c = 0;
        do
        {
            s += serie.id;
            c++;
            fread(&serie, sizeof(serie), 1, a);
        } while (!feof(a) && serie.id == idS);
        cout << idS << " promedio: " << s / c << endl;
    }
}