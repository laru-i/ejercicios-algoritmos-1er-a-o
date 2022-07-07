#include <iostream>
using namespace std;

/*
Desarrollar una función tal que dado un número entero positivo calcule y retorne su 
factorial.
*/
int factorial(int);

int main()
{
    int num;

    cout<<"ingrese un numero: ";
    cin>>num;
    cout << "El factorial de " << num << " es " << factorial(num);
    
    return 0;
}
int factorial (int a){
    
    int factorial = 1;

 for (int i = 1; i <= a; i++)
  {
    factorial *= i;
  }

  return factorial;
}