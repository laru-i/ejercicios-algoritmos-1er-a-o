#include <iostream>

using namespace std;

/* Desarrollar una función que dados n y m devuelva el combinatorio de m tomados de a n.
Usar función punto 2
m!/n!(m-n)!
 */
int factorial(int);
int combinatorio (int, int);

int main()
{   
    
    int m, n, res;

    cout<<"ingrese dos numeros: ";
    cin>>m>>n;
    cout<<"el numero combinatorio es "<<combinatorio(m,n);

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

int combinatorio(int a, int b){
    int combinatorio;
    combinatorio = factorial(a) / (factorial(b) * (factorial(a - b)));
    return combinatorio;
}