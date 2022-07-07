#include <iostream>

using namespace std;

/*

Dado un número entero positivo informar su factorial.

*/

int main()
{
    int num, factorial = 1;

   cout<<"ingrese un numero: ";
   cin>>num;

    for (int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    
cout<<"el factorial es: "<<factorial;

return 0;
}

