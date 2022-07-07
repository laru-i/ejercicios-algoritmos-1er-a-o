#include <iostream>

using namespace std;
/*
Desarrollar un programa que permita:
- Cargar un vector de 50 valores enteros
- Mostrar por pantalla el contenido del vector
- Obtener el mayor valor entero contenido en el vector y su posición en el mismo
- Obtener el menor valor entero contenido en el vector y su posición en el mismo.
Analizar y describir los cambios necesarios para resolver el mismo problema considerando a lo
sumo 50 valores enteros.
*/
int inicializar(int v[]);
int recorrer(int v[]);
int mayor(int v[]);
int menor(int v[]);

int main()
{
  int v[5];

  inicializar(v);
  recorrer(v);
  mayor(v);
  menor(v);

  return 0;
}

int inicializar(int v[])
{
  for (int i = 0; i < 5; i++)
  {
    cout << "ingrese un valor entero " << endl;
    cin >> v[i];
  }
}

int recorrer(int v[])
{
  for (int i = 0; i < 5; i++)
    cout << v[i] << endl;
}

int mayor(int v[])
{
  int mayorV = 0, pos = 0;
  for (int i = 0; i < 5; i++)
  {
    if (v[i] > mayorV)
    {
      mayorV = v[i];
      pos++;
    }
  }
  cout << "el mayor numero es " << mayorV << " y esta en la posicion " << pos + 1 << endl;
}

int menor(int v[])
{
  int menorV = 0, pos = 0;
  for (int i = 0; i < 5; i++)
  {
    if (i == 0 || v[i] < menorV)
    {
      menorV = v[i];
      pos++;
    }
  }
  cout << "el menor numero es " << menorV << " y esta en la posicion " << pos;
}

/*
int main()
{
    int num[5], mayor = 0, menor = 0, i, posMenor, posMayor;
    float prom;

    for (i = 0; i < 5; i++)
    {
        cout<<"ingrese un num: ";
        cin>>num[i];

        if (i == 0)
          {
            mayor = num[i];
            menor = num[i];
            posMayor = i;
            posMenor = i;
          }
        else
         {
            if (mayor < num[i])
             {
            mayor = num[i];
            posMayor = i;
             }

            if (menor > num[i])
             {
            menor = num[i];
            posMayor = i;
             }
         }

    }

    for (int i = 0; i < 5; i++)
    {
      cout<<num[i]<<endl;
    }

    cout<<" el mayor es: "<<mayor<<" y se encuentra en la posicion: "<<posMayor+1;
    cout<<" el menor es: "<<menor<<" y se encuentra en la posicion: "<<posMenor+1;


    return 0;
}
*/