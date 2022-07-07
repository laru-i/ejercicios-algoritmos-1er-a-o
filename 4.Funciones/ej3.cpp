#include <iostream>

using namespace std;

/* Desarrollar una función que dados dos números, retorne verdadero si el primero es múltiplo 
del segundo, falso en caso contrario. */
int multiplo(int, int);

int main()
{
    int n1, n2;

    cout<<"ingrese dos numeros: ";
    cin>>n1>>n2;
    if (multiplo(n1,n2))
    {
        cout << "Los numeros son multiplos - VERDADERO";
    }
    else {
        cout << "Los numeros no son multiplos - FALSO";
    }
      
    return 0;
}
int multiplo (int a, int b){

    return a % b == 0;
}