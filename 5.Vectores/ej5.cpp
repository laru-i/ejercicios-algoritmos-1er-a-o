#include <iostream>

using namespace std;
/*
Dado un conjunto desordenado de valores enteros comprendidos entre 1 y 10, sin repetición, que
finaliza con cero, desarrollar un algoritmo que:
. Imprima un listado ordenado de aquellos valores enteros que se encuentran en el conjunto
. Imprima un listado ordenado de aquellos valores enteros que no se encuentran en el conjunto.

*/
void inicializar(bool v[], int cant);
void ingr(bool v[]);
void mostrar(bool v[], int cant, bool valor);

int main()
{
  int cant = 10;
  bool v[cant];

  inicializar(v, cant);
  ingr(v);

  cout << "numeros ingresados " << endl;
  mostrar(v, cant, true);
  cout << endl;

  cout << "numeros no ingresados " << endl;
  mostrar(v, cant, false);

  return 0;
}
void inicializar(bool v[], int cant)
{
  for (int i = 0; i < cant; i++)
  {
    v[i] = false;
  }
}

void ingr(bool v[])
{
  int num;
  cout << "ingrese un valor entero comprendido entre el 1 y 10, cero fin " << endl;
  cin >> num;
  while (num != 0)
  {
    v[num - 1] = true;
    cout << "ingrese un valor entero comprendido entre el 1 y 10, cero fin " << endl;
    cin >> num;
  }
}

void mostrar(bool v[], int cant, bool valor)
{
  for (int i = 0; i < cant; i++)
  {
    if (v[i] == valor)
      cout << i + 1;
  }
}
/*
void cargar(bool v[]);
void inic(bool v[]);
void mostrar(bool v[],bool valor);


int main()
{
    bool vec[10];
    inic(vec);
    cargar(vec);

    cout<<"Numeros ingresados"<<endl;
    mostrar(vec,true);
    cout<<"Numeros no ingresados"<<endl;
    mostrar(vec,false);


    return 0;
}
//inicializo el vector en falso para no tener basura
void inic(bool v[]){
  for (int i = 0; i < 10; i++)
  {
    v[i] = false;
  }
}

//carga los valores
void cargar(bool v[]){
  int num;
  cout<<" ingrese valores entre 1 y 10: ";
  cin>>num;

  while (num != 0){
    v[num-1] = true;
    cin>>num;
  }
}

//asigna el bool al num ingresado
void mostrar(bool v[], bool valor){
  for (int i = 0; i < 10; i++)
  {
    if (v[i] == valor)
    cout<<i+1;
  }
}
*/