#include <iostream>

using namespace std;

/* 
Un buque de carga traslada contenedores a tres diferentes puertos del país. Los puertos se 
identifican con los números 1, 2 y 3. 
De cada contenedor que el buque traslade se registran los siguientes datos:
- Identificación del contenedor
- Peso del contenedor en kg
- Puerto de arribo (un valor de 1 a 3).
El ingreso de datos finaliza con la identificación de un contenedor igual a cero.
Se pide calcular e informar:
a) El peso total que el buque debe trasladar.
b) La identificación del contenedor de mayor peso.
c) La cantidad de contenedores que debe trasladar a cada puerto


*/
int main()
{
    int ident, peso, pesoTotal = 0, puerto, mayor = 0, puertoUno = 0, puertoDos = 0, puertoTres = 0, identMayor;
      
        cout<<"identificacion (cero para fin)";
        cin>>ident;

    while (ident != 0)
    {
        cout<<"peso en kg ";
        cin>>peso;
        pesoTotal += peso;
    
        if (peso > mayor)
        {
            mayor = peso;
            identMayor = ident;       
        }

        cout<<"puerto (1, 2 o 3) ";
        cin>>puerto;

        switch (puerto)
        {
        case 1:
            puertoUno++;
            break;
        case 2:
            puertoDos++;
            break;
        case 3:
            puertoTres++;
            break;     

        default:
            break;
        }
        
        cout<<"identificacion ";
        cin>>ident;
}

    cout<<"el peso total es "<<pesoTotal<<" kg"<<endl;
    cout<<"el contenedor "<<identMayor<<" es el de mayor peso, con: "<<mayor<<" kg"<<endl;
    cout<<"debe trasladar al 1er puerto "<<puertoUno<<" contenedores"<<endl;
    cout<<"debe trasladar al 2do puerto "<<puertoDos<<" contenedores"<<endl;
    cout<<"debe trasladar al 3er puerto "<<puertoTres<<" contenedores"<<endl;
    

    
    return 0;
}