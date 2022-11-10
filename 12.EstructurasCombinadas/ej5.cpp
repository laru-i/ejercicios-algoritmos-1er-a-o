#include <iostream>
#include <stdio.h>

using namespace std;

/*
Una cobrañía que ofrece préstamos a sus clientes a pagar en 12 meses, desea
obtener un listado con los códigos de clientes y los números de las cuotas
adeudadas de aquellos clientes que adeuden cuotas, ordenado por código de cliente.
Para ello cuenta con un archivo de cobranzas, sin ningún orden, con el
siguiente diseño:
Código de cliente (int)
Número de cuota (1 a 12)
*/

struct ArchivoCobranzas
{
    int codCliente, nroCuota;
};

struct Info
{
    int cod;
    bool v[12];
};

struct Nodo
{
    Nodo *sig;
    Info info;
};

void generarArchivo(FILE *arch);
void ejercicio(Nodo *&lista, FILE *arch);
void insertar(Nodo *&lista, Info info);
void inicializarVector(Info info);
void listar(Nodo *lista);
void mostrarArchivo(FILE *archivo);

int main()
{
    FILE *archCobranzas;
    Nodo *lista = NULL;

    // generarArchivo(archCobranzas);
    ejercicio(lista, archCobranzas);
    listar(lista);
    // mostrarArchivo(archCobranzas);

    return 0;
}

void ejercicio(Nodo *&lista, FILE *arch)
{
    arch = fopen("Cobranzas.dat", "rb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        Info info;
        ArchivoCobranzas cobr;

        fread(&cobr, sizeof(ArchivoCobranzas), 1, arch);
        while (!feof(arch))
        {
            info.cod = cobr.codCliente;

            for (int i = 0; i < 12; i++)
                info.v[i] = false;
                
            info.v[cobr.nroCuota - 1] = true;

            insertar(lista, info);
            fread(&cobr, sizeof(ArchivoCobranzas), 1, arch);
        }
    }
}

void listar(Nodo *lista)
{
    Nodo *p = lista;
    cout << "--------------------------" << endl;

    while (p)
    {
        cout << "nro cliente " << p->info.cod << endl;
        for (int i = 0; i < 12; i++)
        {
            if (p->info.v[i] == true)
                cout << "cuota nro " << i + 1 << " abonada" << endl;
        }
        p = p->sig;
    }
}

void insertar(Nodo *&lista, Info info)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = info;
    p = lista;
    while (p != NULL && p->info.cod < info.cod)
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

/*
void mostrarArchivo(FILE *archivo)
{
    archivo = fopen("Cobranzas.dat", "rb");
    if (archivo == NULL)
        cout << "ERROR" << endl;
    else
    {
        cout << "------------------- ARCHIVO --------------------" << endl;

        ArchivoCobranzas arch;

        fread(&arch, sizeof(ArchivoCobranzas), 1, archivo);
        while (!feof(archivo))
        {
            cout << "socio: " << arch.codCliente << endl;
            cout << "nro cuota: " << arch.nroCuota << endl;

            cout << "-------" << endl;
            fread(&arch, sizeof(ArchivoCobranzas), 1, archivo);
        }
        fclose(archivo);
    }
}
*/
/*void generarArchivo(FILE *arch)
{
    arch = fopen("Cobranzas.dat", "wb");
    if (arch == NULL)
        cout << "ERROR" << endl;
    else
    {
        ArchivoCobranzas cobr;

        cout << "cod cliente (0 para finalizar) ";
        cin >> cobr.codCliente;

        while (cobr.codCliente != 0)
        {
            cout << "cuota abonada: " << endl;
            cin >> cobr.nroCuota;

            fwrite(&cobr, sizeof(ArchivoCobranzas), 1, arch);

            cout << "cod cliente (0 para finalizar) ";
            cin >> cobr.codCliente;
        }
        fclose(arch);
    }
}*/
