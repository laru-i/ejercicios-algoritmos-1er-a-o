#include <iostream>

using namespace std;

/*
Dado un número N (<20), y dos vectores A y B de N elementos que contenga valores entre 0..9
que representan números naturales muy largos
a) genere e informe un tercer vector SUMA de N+1 elementos que sea el resultante de la suma de
los dos números.
b) genere e informe un tercer vector RESTA de N elementos que sea el resultante de la resta de
los dos números.
*/
void sumaV(int a[], int b[], int nro, int suma[]);
void cargarValores(int v[], int cant);
void restaV(int a[], int b[], int nro, int resta[]);

int main()
{
    int n;
    do
    {
        cout << "ingrese un num entre 1 y 20 ";
        cin >> n;

    } while (n > 20 || n <= 1);

    int A[n], B[n], suma[n + 1], resta[n];

    cargarValores(A, n);
    cargarValores(B, n);
    sumaV(A, B, n, suma);
    restaV(A, B, n, resta);

    for (int i = 0; i < n + 1; i++)
    {
        cout << "la suma es " << suma[i] << endl;
        cout << "la resta es " << resta[i] << endl;
    }
}

void cargarValores(int v[], int cant)
{
    int i = 0;
    do
    {
        cout << "ingrese el valor " << i + 1 << " del vector" << endl;
        cin >> v[i];
        i++;

    } while (i <= cant - 1);
}

void sumaV(int a[], int b[], int nro, int suma[])
{
    for (int i = 0; i < nro + 1; i++)
        suma[i] = 0;

    int j = nro;

    for (int i = nro - 1; i >= 0; i--)
    {
        suma[j] = a[i] + b[i];
        j--;
    }
    for (j = nro; j >= 0; j--)
    {
        if (suma[j] >= 10)
        {
            suma[j] = suma[j] - 10;
            suma[j - 1] = suma[j - 1] + 1;
        }
    }
}
void restaV(int a[], int b[], int nro, int resta[])
{
    for (int i = 0; i < nro + 1; i++)
        resta[i] = 0;

    int j = nro;
    for (int i = nro - 1; i >= 0; i--)
    {
        resta[j] = a[i] - b[i];
        j--;
    }

    for (j = nro; j >= 0; j--)
    {
        if (resta[j] < 0)
        {
            resta[j] = resta[j] + 10;
            resta[j - 1] = resta[j - 1] - 1;
        }
    }
}

/*
void restaV(int a[], int b[], int nro, int resta[])
{
    for (int i = 0; i < nro + 1; i++)
        resta[i] = 0;

    int j = nro;
    for (int i = nro - 1; i >= 0; i--)
    {
        resta[j] = a[i] - b[i];
        j--;
    }

    for (j = nro; j >= 0; j--)
    {
        if (a[j] < b[j])
        {
            a[j - 1] = a[j - 1] - 1;
            a[j] = a[j] + 10;
        }
    }
}
*/
/*
void cargarVector(int v[], int cant);
void sumaVectores(int A[], int B[], int cant, int suma[]);

int main()
{
    int n;

    do
    {
    cout<<"ingrese un número mayor a 1 y menor a 20 ";
    cin>>n;

    } while (n > 20 && n <= 1);

    int  a[n], b[n], suma[n + 1];

    cout<<"valores del vector A "<<endl;
    cargarVector(a, n);
    cout<<"valores del vector B "<<endl;
    cargarVector(b, n);

    sumaVectores(a, b, n + 1, suma);


return 0;


}
void cargarVector(int v[], int cant)
{
    int i = 0, num;
    do
    {
    cout<<"ingrese el valor "<< i + 1<< " del vector ";
    cin>>num;
        v[i] = num;
        i++;

    } while (i <= cant - 1);

}

void sumaVectores(int A[], int B[], int cant, int suma[])
{
    int a = cant - 2;
    int s = cant - 1;
    for (s; s >= 0; s--)
    {
        if(a != -1)
            suma[s] = A[a] + B[a];
        else
            suma[s] = 0;
        a--;
    }
    for (int i = cant - 1; i >= 0; i--)
    {
        if (suma[i] >= 10)
        {
            suma[i] = suma[i] - 10;
            if (i != 0)
            {
                suma[i - 1] = suma[i - 1] + 1;
            }
        }
      cout<< suma[i];
    }

}
void restaVectores(int A[], int B[], int cant, int resta[])
{
    int a = cant - 2;
    int r = cant - 1;
    for (r; r >= 0; r--)
    {
        resta[r] = A[a] - B[a];
        a--;
    }
    for (int i = cant - 1; i >= 0; i--)
    {
        if (resta[i] < 0)
        {
            resta[i] = resta[i] + 10;
        }

    }


}
*/