#include <iostream>

using namespace std;

/* 
Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un 
Nombre = ‘FIN’, informar el nombre de la persona con mayor edad y el de la más joven.

*/
int main()
{
    int fechaNac, mayor, menor;
    bool pri = true;
    string nombre, viejo, joven;
    
    cout<<"ingrese su nombre (fin para finalizar): ";
    cin>>nombre;
    
    while (nombre != "fin")
    {
        cout<<"ingrese su fecha de nacimiento (AAAAMMDD): ";
        cin>>fechaNac;

        if (pri)
        {
            menor = fechaNac;
            mayor = fechaNac;
            viejo = nombre;
            joven = nombre;
            pri = false;
        }
        else {
            if (fechaNac < mayor)
            {
                mayor = fechaNac;
                viejo = nombre;
            }
            else if (fechaNac > menor)
            {
                menor = fechaNac;
                joven = nombre;
            }
        }
        cout<<"ingrese su nombre (fin para finalizar): ";
        cin>>nombre;
    }

    if(pri)
        cout<<"no hubo ingreso"<<endl;
    else
    {
        cout<<"La persona mas vieja es "<<viejo<<endl;
        cout<<"La persona mas joven es "<<joven<<endl;
    }
    
    
    
    return 0;
}
