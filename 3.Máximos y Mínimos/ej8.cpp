#include <iostream>

using namespace std;

/* 
El gobierno de la Ciudad de Buenos Aires realiza una encuesta en casas de familia. De cada 
familia encuestada se conoce: domicilio, tipo de vivienda (‘C’: casa, ‘D’: departamento) y 
cantidad de integrantes.
De cada integrante de la familia se conoce: nombre y apellido, edad, sexo (‘F’, ‘M’), nivel de 
estudios alcanzados (‘N’: no posee, ‘P’: primario, ‘S’: secundario, ‘T’: terciario), y un indicador 
(‘I’: Incompleto, ‘C’: Completo) referente al ítem anterior.
Se identifica el fin de ingreso de datos con un cero como cantidad de integrantes.
Informar:
    a) La cantidad de encuestados que han completado los estudios primarios,
    b) el porcentaje de analfabetismo en la ciudad (se consideran analfabetos a los mayores de 
10 años que no poseen estudios),
    c) el domicilio de la familia con mayor cantidad de integrantes que viven en un 
departamento,
    d) la edad promedio de todos los habitantes de la ciudad,
    e) la mayor edad promedio de las familias,
    f) la cantidad de encuestados con estudios secundarios incompletos,
    g) el porcentaje de encuestados de sexo femenino con estudios terciarios completos.
FALTA ARREGLAR

*/
int main()
{
    int integrantes, edad, est = 0, analf = 0;
    float prom;
    string domicilio, vivienda, nombre, sexo, estudios, indicador;
    
    do
    {
        cout<<"cantidad de integrantes de la familia "<<endl;
        cin>>integrantes;

        cout<<"domicilio "<<endl;

        cout<<"tipo de vivienda (‘C’: casa, ‘D’: departamento)"<<endl;
        cin>>vivienda;

        cout<<"nombre completo "<<endl;
        cin>>nombre;

        cout<<"edad "<<endl;
        cin>>edad;

        cout<<"sexo "<<endl;
        cin>>sexo;

        cout<<"nivel de estudios alcanzados (‘N’: no posee, ‘P’: primario, ‘S’: secundario, ‘T’: terciario) "<<endl;
        cin>>estudios;

        cout<<"estos se encuentran  (‘I’: Incompleto, ‘C’: Completo)"<<endl;
        cin>>estudios;
        
        if (estudios == "P")
            est++;
        
        if (edad > 10 && estudios == "N")
        {
            analf++;

        }
        
        




    }while (analf == 0);

    
    
    return 0;
}