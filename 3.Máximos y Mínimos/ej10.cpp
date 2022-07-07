
#include <iostream>

using namespace std;

/*
Una compañía aérea desea emitir un listado con los movimientos mensuales de sus M vuelos al
exterior.
Para ello cuenta con la siguiente información:
De cada vuelo realizado el número de vuelo, destino, y cantidad de asientos.
De cada pasajero el número de pasaporte y el importe que abonó por el pasaje en dólares.
La información de los pasajeros de cada vuelo finaliza con un número de pasaporte igual a cero.
Se pide emitir el siguiente listado:
Nro. de Vuelo ………. Destino: ………..
Nro. de Pasaporte Importe en u$s
…………. ………….
 …………. ………….
 Total recaudado del vuelo: ………
Cantidad de asientos libres: ………
Número de vuelo que más recaudó: …….

FALTA ARREGLAR

*/
int main()
{
    int vuelo, asientos, i = 0, pasaporte, importe, vueloMens, j = 0, total = 0, pas = 0;
    string destino;

    cout << "cantidad de vuelos mensuales ";
    cin >> vueloMens;

    while (j < vueloMens)
    {
        cout << "numero de vuelo ";
        cin >> vuelo;

        cout << "destino ";
        cin >> destino;

        cout << "cant de asientos ";
        cin >> asientos;

        cout << "numero de pasaporte ";
        cin >> pasaporte;

        while (pasaporte != 0)
        {
            cout << "importe en dolares ";
            cin >> importe;
            total += importe;

            cout << "numero de pasaporte ";
            cin >> pasaporte;
            pas++;
        }
        j++;
    }

    cout << "nro de vuelo " << vuelo << endl;
    cout << "destino " << destino << endl;
    cout << "nro de pasaporte " << pasaporte << endl;
    cout << "Total recaudado del vuelo " << total << endl;
    cout << "importe en dolares " << importe << endl;
    cout << "Cantidad de asientos libres " << asientos - pas << endl;
    cout << "vuelo que mas recaudo " << asientos - pas << endl;

    return 0;
}