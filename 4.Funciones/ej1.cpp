#include <iostream>

using namespace std;
/*
Desarrollar una función que calcule el máximo común divisor de dos números enteros A, B 
con el siguiente algoritmo: 
1. Dividir A por B, y calcular el resto (0 < R < B) 
2. Si R = 0, el MCD es B, si no seguir en 3.
3. Reemplazar A por B, B por R, y volver al paso 1.



*/
int mcod(int,int);

int main()
{
    int a, b, num;

        cout<<"ingrese dos numeros: ";
        cin>>a>>b;
        cout<<"el mcd es: "<<mcod(a,b);
    
    return 0;
}
int mcod(int a, int b)
    {
        int resto, mcd; 

        resto = a%b;

        if (resto == 0)
        {
            mcd = b;
            return mcd;
        }
        else {
            b = a;
            b = resto;
            mcod(a, b);
        }
    }