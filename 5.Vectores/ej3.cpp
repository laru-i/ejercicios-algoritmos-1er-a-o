#include <iostream>

using namespace std;
/*
Hacer un algoritmo que lea 40 edades de alumnos y muestre por pantalla las edades que superen a
la edad promedio.
*/

int main()
{
    int edad[4], suma = 0;
    float prom;

    for (int i = 0; i < 4; i++)
    {
        cout << "ingrese su edad ";
        cin >> edad[i];
        suma += edad[i];
    }
    prom = suma / 4;
    cout << "el promedio es " << prom << endl;

    for (int j = 0; j < 4; j++)
        if (edad[j] > prom)
            cout << "la edad " << edad[j] << " es mayor al promedio";

    return 0;
}

/*
Hacer un algoritmo que lea 40 edades de alumnos y muestre por pantalla las edades que superen a
la edad promedio.


int main()
{
    int edad[4], suma = 0, i;
    float prom;

    for (i = 0; i < 4; i++)
    {
        cout<<"ingrese una edad: ";
        cin>>edad[i];
        suma += edad[i];
    }
    prom = (float)suma / i+1;

    for (int j = 0; j < 4; j++)
    {
       if (edad[j] > prom)
        {
            cout<<" la edad que superan al promedio "<< prom <<" son: "<<edad[j]<<endl;
        }
    }


    return 0;
}

*/