#include <iostream>

using namespace std;

/* Dada una serie de números enteros positivos que finalizan con cero, informar: 
a) su factorial 
b) cuantos múltiplos de 3 
c) cuantos múltiplos de 5 
d) cuantos múltiplos de 3 y de 5 
 */
int factorial(int);
int multiplo3(int);
int multiplo5(int);
int multiplo3y5(int);

int main()
{   
    int num, mult3 = 0, mult5 = 0, mult3y5 = 0;

    do
    {
        cout<<"ingrese un numero (cero para finalizar): ";
        cin>>num;
    if (num != 0)
        {
         
        cout << "El factorial de " << num << " es " << factorial(num) <<endl;

    if (multiplo3(num))
        mult3++;
    if (multiplo5(num))
        mult5++;
    if (multiplo3y5(num))
        mult3y5++;
        }
    }
     while (num != 0);
          

    cout << mult3 << " numeros son multiplos de 3" << endl;
    cout << mult5 << " numeros son multiplos de 5" << endl;
    cout << mult3y5 << " numeros son multiplos de 3 y 5" << endl;

    return 0;


}

int multiplo3 (int a){

    return a % 3 == 0;
}

int multiplo5(int a)
{
  return a % 5 == 0;
}

int multiplo3y5(int a)
{
  return a % 3 == 0 && a % 5 == 0;
}

int factorial (int a){
    
    int factorial = 1;

 for (int i = 1; i <= a; i++)
  {
    factorial *= i;
  }

  return factorial;
}
