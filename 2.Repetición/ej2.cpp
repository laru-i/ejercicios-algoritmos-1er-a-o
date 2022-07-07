
#include <iostream>

using namespace std;

/*
Ingresar la cantidad de alumnos de un curso. Ingresar por cada alumno el nombre y dos notas. Por 
cada alumno informar su nombre y el promedio de sus notas.
*/

int main()
{
    int nota1,nota2,alumnos;
    string nombre;

    cout << "Ingresar la cantidad de alumnos del curso ";
    cin >> alumnos;
    
    for (int i = 1; i < alumnos; i++)
    {
        cout << "Ingresar el nombre del alumno y dos notas ";
        cin >> nombre >> nota1 >> nota2;
        cout << "El promedio del alumno " << nombre << " es: " << (nota1 + nota2) / 2 << endl;
    }
       
    return 0;
}