#include <iostream>

using namespace std;

/*
Una empresa de medicina prepaga desea realizar un programa para tener una estadística de las consultas realizadas
por sus médicos. Se atienden 20 especialidades médicas diferentes, codificadas del 1 al 20. Todos los médicos
atienenden una única especialidad.
Primero se debe ingresar por cada uno de los 175 médicos, el número de matrícula, el nombre y el código de la
especialidad que atiende.
A continuación se ingresan las consultas del mes de junio.
De cada consulta se ingresa: número de historia clínica del paciente, número de matrícula del médico y día de la
consulta (de 1 a 30). El ingreso de datos finaliza con número de historia clínica cero.
Se pide que el programa, una vez finalizado el ingreso de datos, informe:
1) La cantidad de consultas realizadas en cada especialidad y por cada día del mes, con el siguiente diseño:
Especialidad 1:
Día 1 X consultas
Día 2 X consultas
…
2) El día del mes en el que hubo la menor cantidad de consultas en total.
3) Por cada médico, número de matrícula, nombre y cantidad total de consultas realizadas en el mes.
*/

struct Medicos
{
    int nroMat, codEsp, consultas;
    string nombre;
};

struct Consultas
{
    int histClinica, mat;
};

int main()
{
    int m[30][20];
    Medicos v[175];

    return 0;
}

// INICIALIZAR

void pto1(int m[][20])
{
    for (int i = 0; i < 20; i++)
    {
        cout << "especialidad" << i + 1;
        for (int j = 0; j < 30; j++)
        {
            cout << "dia" << j + 1;
            cout << m[j][i];
        }
    }
}

void pto2(int m[][20])
{
    int menor = m[0][0], q;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (m[i][j] < menor)
                menor = m[i][j];
            q = menor;
        }
        cout << "especialidad" << q + 1;
    }
}

void pto3(Medicos v[])
{
    for (int i = 0; i < 175; i++)
    {
        cout << v[i].nombre;
        cout << v[i].nroMat;
        cout << v[i].consultas;
    }
}

void ingresarConsultas(Medicos v[], int m[][20])
{
    int histClinica, nroMat, pos, dia;

    cin >> histClinica;

    while (histClinica != 0)
    {
        cin >> nroMat;
        pos = buscar(v, 175, nroMat);

        while (pos == -1)
        {
            cin >> nroMat;
            pos = buscar(v, 175, nroMat);
        }
        if (pos != -1)
        {
            cin >> dia;
            m[dia - 1][v[pos].codEsp - 1]++;
            v[pos].consultas++;
        }
        cin >> histClinica;
    }
}

int buscar(Medicos v[], int t, int nroMat)
{
    int i = 0;
    while (i < t && v[i].nroMat != nroMat)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}

void ingresarMedicos(Medicos v[])
{
    for (int i = 0; i < 175; i++)
    {
        cin >> v[i].nroMat;
        cin >> v[i].codEsp;
        cin >> v[i].nombre;
        v[i].consultas = 0;
    }
}