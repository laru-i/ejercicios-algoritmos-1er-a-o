/*
Hacer un programa que presente al usuario un menú de opciones para:

1- Inscripción de estudiante
Cuando un estudiante se inscribe, se ingresan por teclado los siguientes datos:
Nombre y número de documento del estudiante
Código del curso en el que se inscribe.
Verificar que exista el curso, si no rechazar la inscripción.
Inscribir al estudiante en el curso si hay cupo disponible, si no agregarlo a la cola de espera para ese
idioma y ese nivel.

2- Baja de estudiante
Dado el número de documento del estudiante que pide la baja y código del curso del cual se baja,
eliminarlo y darle la vacante a quien corresponda si es que hay estudiantes en cola de espera.

3- Mostrar
Mostrar el estado de las inscripciones hasta el momento
Mostrar por cada curso (ordenado por código de curso):
Código de curso
Cantidad de vacantes ocupadas
Cantidad de vacantes disponibles
Listado de estudiantes inscriptos hasta el momento (número de documento y nombre,
ordenados por número de documento)

4- Salir
Al finalizar el programa:
a) Emitir un listado de los estudiantes que no obtuvieron vacante, informando número de
documento y nombre.
b) Emitir un listado con los docentes que dictarán cursos, indicando número de documento,
nombre y cantidad total de estudiantes a su cargo, ordenado de menor a mayor por
número de documento, utilizando un árbol binario de búsqueda. Se deberán cargar los
datos en el mismo y recorrerlo INORDER para emitir el listado. El árbol binario se puede
generar al finalizar el programa o ir almacenando los datos durante el proceso. La
emisión del listado debe ser al finalizar el programa.
c) Generar un archivo por curso con los inscriptos, ordenados por número de documento
(obtener el nombre de los archivos de los datos almacenados en memoria)
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define niveles 8
#define idiomas 6

struct Alumno
{
  string nombre;
  int dni, codCurso;
};

struct NodoSL
{
  Alumno info;
  NodoSL *sigSub;
};

struct DatosArchivo
{
  int codCurso, cupos, dniProfe, nivel;
  char nombre[25];
};

struct DatosLista
{
  int codCurso, cupos, idioma, nivel;
  NodoSL *sigSub;
};

struct NodoL
{
  DatosLista info;
  NodoL *sig;
};

struct NodoCola
{
  Alumno info;
  NodoCola *sig;
};

struct NodoMatriz
{
  NodoCola *pri;
  NodoCola *ult;
};

void armarListaCursos(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *, NodoL *&);
void leerArchivos(FILE *, NodoL *&, int);
void insertar(NodoL *&, DatosLista);
void busquedaCurso(NodoL *&, Alumno, NodoMatriz matrizDeColas[niveles][idiomas]);
void punto1(NodoL *&, NodoMatriz matrizDeColas[niveles][idiomas]);
void punto2(NodoL *&listaCursos, NodoMatriz matrizDeColas[niveles][idiomas]);
void punto3(NodoL *, NodoMatriz matrizDeColas[niveles][idiomas]);
void insertarEnSublista(NodoSL *&, Alumno);
void inicializarMatriz(NodoMatriz matrizDeColas[niveles][idiomas]);
// void insertarEnMatriz(NodoMatriz matrizDeColas[niveles][idiomas], DatosLista, Alumno);
void encolar(NodoCola *&, NodoCola *&, Alumno);
Alumno desencolar(NodoCola *&pri, NodoCola *&ult);
void eliminar(NodoL *&lista, int dni);

int main()
{
  FILE *ingles = fopen("Ingles.dat", "rb");
  FILE *frances = fopen("Frances.dat", "rb");
  FILE *portugues = fopen("Portugues.dat", "rb");
  FILE *italiano = fopen("Italiano.dat", "rb");
  FILE *aleman = fopen("Aleman.dat", "rb");
  FILE *chino = fopen("Chino.dat", "rb");

  NodoL *listaCursos = NULL;
  NodoMatriz matrizDeColas[niveles][idiomas];
  inicializarMatriz(matrizDeColas);

  armarListaCursos(portugues, italiano, frances, aleman, ingles, chino, listaCursos);

  fclose(ingles);
  fclose(frances);
  fclose(portugues);
  fclose(italiano);
  fclose(aleman);
  fclose(chino);

  punto1(listaCursos, matrizDeColas);

  int opcionElegida;
  cout << "MENU DE OPCIONES" << endl;
  cout << " 1. Inscripcion de estudiante" << endl; // esta opcion no se puede seleccionar en realidad
  cout << " 2. Baja de estudiante" << endl;
  cout << " 3. Mostrar el estado de las inscripciones hasta el momento" << endl;
  cout << " 4. Salir" << endl;
  cin >> opcionElegida;

  while (opcionElegida != 4)
  {
    switch (opcionElegida)
    {
      // case 1:
      //   punto1(listaCursos, matrizDeColas);
      //   break;

    case 2:
      punto2(listaCursos, matrizDeColas);
      break;

    case 3:
      punto3(listaCursos, matrizDeColas);
      break;
    }
    cout << "MENU DE OPCIONES" << endl;
    cout << " 1. Inscripcion de estudiante" << endl; // esta opcion no se puede seleccionar en realidad
    cout << " 2. Baja de estudiante" << endl;
    cout << " 3. Mostrar el estado de las inscripciones hasta el momento" << endl;
    cout << " 4. Salir" << endl;
    cin >> opcionElegida;
  }

  // punto4();

  return 0;
}

void inicializarMatriz(NodoMatriz matrizDeColas[niveles][idiomas])
{
  for (int f = 0; f < niveles; f++)
  {
    for (int c = 0; c < idiomas; c++)
    {
      matrizDeColas[f][c].pri = NULL;
      matrizDeColas[f][c].ult = NULL;
    }
  }
}

void armarListaCursos(FILE *portugues, FILE *italiano, FILE *frances, FILE *aleman, FILE *ingles, FILE *chino, NodoL *&listaCursos)
{
  if (portugues == NULL && italiano == NULL && frances == NULL && aleman == NULL && ingles == NULL && chino == NULL)
    cout << "ERROR";
  else
  {
    leerArchivos(ingles, listaCursos, 0); // el int es el numero de idioma para relacionarlo con la matriz
    leerArchivos(frances, listaCursos, 1);
    leerArchivos(portugues, listaCursos, 2);
    leerArchivos(italiano, listaCursos, 3);
    leerArchivos(aleman, listaCursos, 4);
    leerArchivos(chino, listaCursos, 5);
  }
}

void leerArchivos(FILE *arch, NodoL *&lCursos, int nroIdioma)
{
  DatosArchivo datosArch;
  DatosLista datosLis;

  fread(&datosArch, sizeof(DatosArchivo), 1, arch);
  while (!feof(arch))
  {
    datosLis.codCurso = datosArch.codCurso;
    datosLis.cupos = datosArch.cupos;
    datosLis.idioma = nroIdioma;
    datosLis.nivel = datosArch.nivel;
    insertar(lCursos, datosLis);
    fread(&datosArch, sizeof(DatosArchivo), 1, arch);
  }
}

void insertar(NodoL *&lista, DatosLista datosLis)
{
  datosLis.sigSub = NULL;

  NodoL *q, *p, *ant;
  q = new NodoL;
  q->info = datosLis;

  p = lista;
  while (p != NULL && p->info.codCurso < datosLis.codCurso)
  {
    ant = p;
    p = p->sig;
  }
  q->sig = p;
  if (p != lista)
    ant->sig = q;
  else
    lista = q;
}

void punto1(NodoL *&listaCursos, NodoMatriz matrizDeColas[niveles][idiomas])
{
  Alumno alum;

  cout << "INSCRIPCION DE ESTUDIANTE" << endl;
  cout << "Ingrese el codigo del curso a inscribirse (cero para finalizar): " << endl;
  cin >> alum.codCurso;
  while (alum.codCurso != 0)
  {
    cout << "Ingrese su nombre: " << endl;
    cin >> alum.nombre;
    cout << "Ingrese su numero de DNI: " << endl;
    cin >> alum.dni;

    busquedaCurso(listaCursos, alum, matrizDeColas);

    cout << "Ingrese el codigo del curso a inscribirse (cero para finalizar): " << endl;
    cin >> alum.codCurso;
  }
}

void busquedaCurso(NodoL *&lista, Alumno alu, NodoMatriz matrizDeColas[niveles][idiomas])
{
  NodoL *p = lista;

  while (p != NULL && p->info.codCurso < alu.codCurso)
    p = p->sig;

  if (p != NULL && alu.codCurso == p->info.codCurso)
  {
    if (p->info.cupos > 0)
    {
      insertarEnSublista(p->info.sigSub, alu);
      p->info.cupos--;
    }
    else
    {
      // insertarEnMatriz(matrizDeColas, p->info, alu); // estaba así
      encolar(matrizDeColas[p->info.nivel - 1][p->info.idioma].pri, matrizDeColas[p->info.nivel - 1][p->info.idioma].ult, alu);
      cout << "Se encolo un alumno en la matriz de colas" << endl;
    }
  }
  else
    cout << "No se encontro ese curso";
}

// void insertarEnMatriz(NodoMatriz matrizDeColas[niveles][idiomas], DatosLista p, Alumno alu)
// {
//   encolar(matrizDeColas[p.nivel - 1][p.idioma].pri, matrizDeColas[p.nivel - 1][p.idioma].ult, alu);
//   cout << "Se encolo un alumno en la matriz de colas" << endl;
// }

void encolar(NodoCola *&pri, NodoCola *&ult, Alumno alu)
{
  NodoCola *p = new NodoCola;
  p->info = alu;
  p->sig = NULL;
  if (ult != NULL)
    ult->sig = p;
  else
    pri = p;
  ult = p;
}

void insertarEnSublista(NodoSL *&lista, Alumno alu)
{
  NodoSL *n, *p, *ant;
  n = new NodoSL;
  n->info = alu;
  p = lista;
  while (p != NULL && p->info.dni < alu.dni)
  {
    ant = p;
    p = p->sigSub;
  }
  n->sigSub = p;
  if (p != lista)
    ant->sigSub = n;
  else
    lista = n;
}

void punto2(NodoL *&listaCursos, NodoMatriz matrizDeColas[niveles][idiomas])
{
  int cod, dni;
  NodoL *p = listaCursos;
  NodoSL *p2;

  cout << "Ingrese el codigo de curso del cual quiere darse de baja (cero para finalizar): ";
  cin >> cod;
  while (cod != 0)
  {
    cout << "Ingrese su dni: ";
    cin >> dni;

    while (p && p->info.codCurso < cod)
      p = p->sig;
    if (p && p->info.codCurso == cod)
    {
      p2 = p->info.sigSub;
      while (p2 && p2->info.dni < dni)
        p2 = p2->sigSub;
      if (p2 && p2->info.dni == dni)
      {
        eliminar(p, dni);
        p->info.cupos++;
        if (matrizDeColas[p->info.nivel - 1][p->info.idioma].pri)
        {
          cout << "entraa" << endl;
          Alumno desencolado = desencolar(matrizDeColas[p->info.nivel - 1][p->info.idioma].pri, matrizDeColas[p->info.nivel - 1][p->info.idioma - 1].ult);
          insertarEnSublista(p->info.sigSub, desencolado);
          p->info.cupos--;
        }
      }
      else
        cout << "El alumno no esta inscripto en ese curso" << endl;
    }
    else
      cout << "El codigo de curso no existe" << endl;

    cout << "Inserte codigo de curso del cual quiere darse de baja (cero para finalizar): ";
    cin >> cod;
  }
}

Alumno desencolar(NodoCola *&pri, NodoCola *&ult)
{
  Alumno dato;
  NodoCola *p = pri;
  pri = p->sig;
  dato = p->info;
  delete p;
  if (pri == NULL)
    ult = NULL;
  return dato;
}

void eliminar(NodoL *&lista, int dni)
{
  NodoL *p = lista;
  NodoSL *p2 = lista->info.sigSub, *ant;
  while (p2 != NULL && p2->info.dni != dni)
  {
    ant = p2;
    p2 = p2->sigSub;
  }
  if (p2 == lista->info.sigSub)
    lista->info.sigSub = p2->sigSub;
  else
    ant->sigSub = p2->sigSub;
  delete p2;
}

void punto3(NodoL *lis, NodoMatriz matrizDeColas[niveles][idiomas])
{
  NodoL *p = lis;
  NodoSL *q;
  NodoCola *m;

  while (p)
  {
    int cantVacantesOcupadas = 0;
    q = p->info.sigSub;

    cout << "Codigo: " << p->info.codCurso << endl;
    cout << endl;
    cout << "Inscriptos " << endl;
    while (q)
    {
      cout << "DNI: " << q->info.dni << " Nombre: " << q->info.nombre << endl;
      cantVacantesOcupadas++;
      q = q->sigSub;
    }
    cout << endl;
    cout << "Cantidad de vacantes ocupadas: " << cantVacantesOcupadas;
    cout << endl;
    cout << "Cantidad de vacantes disponibles: " << p->info.cupos << endl;

    // cout << "Cola: ";
    // m = matrizDeColas[p->info.nivel - 1][p->info.idioma].pri; // Los idiomas se cargaron como en una matriz entonces no pongo el -1
    // while (m)
    // {
    //   cout << m->info.nombre << "-" << m->info.dni << " -> ";
    //   m = m->sig;
    // }

    cout << endl
         << endl;

    p = p->sig;
  }
}

/* OPCION MENÚ RECURSIVO - IDEA DE GONZA */
// void menu(bool inscri)
// {
//   int opcionElegida;
//   cout << "MENU DE OPCIONES" << endl;
//   cout << " 1. Inscripcion de estudiante" << endl;
//   cout << " 2. Baja de estudiante" << endl;
//   cout << " 3. Mostrar el estado de las inscripciones hasta el momento" << endl;
//   cout << " 4. Salir" << endl;
//   cin >> opcionElegida;
//   switch (opcionElegida)
//   {
//     case 1:
//       punto1(listaCursos, matrizDeColas);
//       inscri=true;
//       menu();
//       break;
//     case 2:
//       punto2(listaCursos, matrizDeColas);
//       mostrarLista(listaCursos, matrizDeColas);
//       menu();
//       break;
//     case 3:
//       punto3();
//       menu();
//       break;
//     case 4:
//       punto4();
//       break;
//   }
// }
