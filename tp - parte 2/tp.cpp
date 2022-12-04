#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define niveles 8
#define idiomas 6

struct Alumno
{
  char nombre[36];
  int dni;
};

struct NodoSL
{
  Alumno info;
  NodoSL *sigSub;
};

struct NodoL
{
  DatosLista info;
  NodoL *sig;
};

struct DatosLista
{
  int codCurso, cupos, idioma, nivel, dniProfe;
  char nombre[25];
  NodoSL *sigSub;
};

struct DatosArchivo
{
  int codCurso, cupos, dniProfe, nivel;
  char nombre[25];
};

struct Profesor
{
  int dniProfe, alumnos;
  char nombre[25];
};

struct NodoRaiz
{
  Profesor info;
  NodoRaiz *izq;
  NodoRaiz *der;
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

void menuDeOpciones(NodoL *listaCursos, NodoMatriz matrizDeColas[niveles][idiomas]);
void armarListaCursos(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *, NodoL *&);
void leerArchivos(FILE *, NodoL *&, int);
void insertar(NodoL *&, DatosLista);
void busquedaCurso(NodoL *&lista, Alumno alu, NodoMatriz matrizDeColas[niveles][idiomas], int cursoAInscribirse);
void punto1(NodoL *&, NodoMatriz matrizDeColas[niveles][idiomas]);
void punto2(NodoL *&listaCursos, NodoMatriz matrizDeColas[niveles][idiomas]);
void punto3(NodoL *);
void insertarEnSublista(NodoSL *&, Alumno);
void inicializarMatriz(NodoMatriz matrizDeColas[niveles][idiomas]);
void encolar(NodoCola *&, NodoCola *&, Alumno);
Alumno desencolar(NodoCola *&pri, NodoCola *&ult);
bool eliminar(NodoL *&lista, int dni);
void punto4(NodoL *lis, NodoMatriz matrizDeColas[niveles][idiomas]);
void subPuntoA(NodoMatriz matrizDeColas[niveles][idiomas]);
void subPuntoB(NodoRaiz *&, NodoL *);
void subPuntoC(NodoL *lis);
void listarIn(NodoRaiz *);
void insertarEnArbol(NodoRaiz *&raiz, Profesor dato);
int contarAlumnos(NodoSL *);
// void mostrarArchivo();

int main()
{
  FILE *ingles = fopen("Ingles.dat", "rb");
  FILE *frances = fopen("Frances.dat", "rb");
  FILE *portugues = fopen("Portugues.dat", "rb");
  FILE *italiano = fopen("Italiano.dat", "rb");
  FILE *aleman = fopen("Aleman.dat", "rb");
  FILE *chino = fopen("Chino.dat", "rb");

  NodoL *listaCursos = NULL;
  NodoRaiz *raiz = NULL;
  NodoMatriz matrizDeColas[niveles][idiomas];
  inicializarMatriz(matrizDeColas);

  armarListaCursos(portugues, italiano, frances, aleman, ingles, chino, listaCursos);

  fclose(ingles);
  fclose(frances);
  fclose(portugues);
  fclose(italiano);
  fclose(aleman);
  fclose(chino);

  menuDeOpciones(listaCursos, matrizDeColas);

  return 0;
}

void menuDeOpciones(NodoL *listaCursos, NodoMatriz matrizDeColas[niveles][idiomas])
{
  int opcionElegida;
  cout << "MENU DE OPCIONES" << endl;
  cout << " 1. Inscripcion de estudiante" << endl;
  cout << " 2. Baja de estudiante" << endl;
  cout << " 3. Mostrar el estado de las inscripciones hasta el momento" << endl;
  cout << " 4. Salir" << endl;
  cin >> opcionElegida;

  if (opcionElegida <= 4 && opcionElegida >= 0)
  {
    switch (opcionElegida)
    {
    case 1:
      punto1(listaCursos, matrizDeColas);
      menuDeOpciones(listaCursos, matrizDeColas);
      break;

    case 2:
      punto2(listaCursos, matrizDeColas); 
      menuDeOpciones(listaCursos, matrizDeColas);
      break;

    case 3:
      punto3(listaCursos);
      menuDeOpciones(listaCursos, matrizDeColas);
      break;

    case 4:
      punto4(listaCursos, matrizDeColas);
      break;
    }
  }
  else
  {
    cout << "Se debe elegir una opcion del 1 al 4" << endl;
    menuDeOpciones(listaCursos, matrizDeColas);
  }
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
    datosLis.dniProfe = datosArch.dniProfe;
    strcpy(datosLis.nombre, datosArch.nombre);
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
  int codCurso;

  cout << "INSCRIPCION DE ESTUDIANTE" << endl;
  cout << "Ingrese el codigo del curso a inscribirse (cero para finalizar): " << endl;
  cin >> codCurso;
  while (codCurso != 0)
  {
    cout << "Ingrese su nombre: " << endl;
    fflush(stdin);
    cin.getline(alum.nombre, 36);
    cout << "Ingrese su numero de DNI: " << endl;
    cin >> alum.dni;

    busquedaCurso(listaCursos, alum, matrizDeColas, codCurso);

    cout << "Ingrese el codigo del curso a inscribirse (cero para finalizar): " << endl;
    cin >> codCurso;
  }
}

void busquedaCurso(NodoL *&lista, Alumno alu, NodoMatriz matrizDeColas[niveles][idiomas], int cursoAInscribirse)
{
  NodoL *p = lista;

  while (p != NULL && p->info.codCurso < cursoAInscribirse)
    p = p->sig;

  if (p != NULL && cursoAInscribirse == p->info.codCurso)
  {
    if (p->info.cupos > 0)
    {
      insertarEnSublista(p->info.sigSub, alu);
      p->info.cupos--;
    }
    else
    {
      encolar(matrizDeColas[p->info.nivel - 1][p->info.idioma].pri, matrizDeColas[p->info.nivel - 1][p->info.idioma].ult, alu);
      cout << "Se encolo un alumno en la matriz de colas" << endl;
    }
  }
  else
    cout << "No se encontro ese curso";
}

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
      if (eliminar(p, dni))
      {
        p->info.cupos++;
        if (matrizDeColas[p->info.nivel - 1][p->info.idioma].pri)
        {
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

bool eliminar(NodoL *&lista, int dni)
{
  NodoL *p = lista;
  NodoSL *p2 = lista->info.sigSub, *ant;
  while (p2 != NULL && p2->info.dni != dni)
  {
    ant = p2;
    p2 = p2->sigSub;
  }
  if (p)
  {
    if (p2 == lista->info.sigSub)
      lista->info.sigSub = p2->sigSub;
    else
      ant->sigSub = p2->sigSub;
    delete p2;
    return true;
  }
  else
    return false;
}

void punto3(NodoL *lis)
{
  NodoL *p = lis;
  NodoSL *q;

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

    cout << endl
         << endl;

    p = p->sig;
  }
}

void punto4(NodoL *lis, NodoMatriz matrizDeColas[niveles][idiomas])
{
  subPuntoA(matrizDeColas);
  NodoRaiz *raiz = NULL;
  subPuntoB(raiz, lis);
  subPuntoC(lis);
}

void subPuntoA(NodoMatriz matrizDeColas[niveles][idiomas])
{
  cout << "ALUMNOS QUE NO OBTUVIERON VACANTE: " << endl;
  for (int f = 0; f < niveles; f++)
  {
    for (int c = 0; c < idiomas; c++)
    {
      while (matrizDeColas[f][c].pri != NULL)
      {
        Alumno desencolado = desencolar(matrizDeColas[f][c].pri, matrizDeColas[f][c].ult);
        cout << "DNI del alumno: " << desencolado.dni << " - "
             << "Nombre del alumno: " << desencolado.nombre << endl;
      }
    }
  }
}

void subPuntoB(NodoRaiz *&raiz, NodoL *lis)
{
  NodoL *p = lis;
  Profesor profe;
  while (p)
  {
    profe.alumnos = contarAlumnos(p->info.sigSub);
    profe.dniProfe = p->info.dniProfe;
    strcpy(profe.nombre, p->info.nombre);
    insertarEnArbol(raiz, profe);
    p = p->sig;
  }
  listarIn(raiz);
}

int contarAlumnos(NodoSL *lis)
{
  int cant = 0;
  NodoSL *p = lis;
  while (p)
  {
    cant++;
    p = p->sigSub;
  }
  return cant;
}

void listarIn(NodoRaiz *raiz)
{
  if (raiz != NULL)
  {
    listarIn(raiz->izq);
    cout << raiz->info.dniProfe << "  " << raiz->info.nombre << " Cant. alumnos: " << raiz->info.alumnos << endl;
    listarIn(raiz->der);
  }
}

void insertarEnArbol(NodoRaiz *&raiz, Profesor dato)
{
  NodoRaiz *n = new NodoRaiz;
  n->info = dato;
  n->der = n->izq = NULL;
  if (raiz == NULL)
    raiz = n;
  else
  {
    NodoRaiz *r = raiz, *ant;
    while (r && dato.dniProfe != r->info.dniProfe)
    {
      ant = r;
      if (dato.dniProfe < r->info.dniProfe)
        r = r->izq;
      else if (dato.dniProfe > r->info.dniProfe)
        r = r->der;
    }
    if (r && dato.dniProfe == r->info.dniProfe)
      r->info.alumnos += dato.alumnos;
    else
    {
      if (dato.dniProfe < ant->info.dniProfe)
        ant->izq = n;
      else
        ant->der = n;
    }
  }
}

void subPuntoC(NodoL *lis)
{
  NodoL *p = lis;
  NodoSL *q;

  while (p)
  {
    char nomArchivo[3];
    string codCurso = to_string(p->info.codCurso);

    strcpy(nomArchivo, codCurso.c_str());

    FILE *archCurso = fopen(strcat(nomArchivo, ".dat"), "wb");

    if (archCurso == NULL)
      cout << "ERROR" << endl;
    else
    {
      q = p->info.sigSub;
      if (q)
      {
        Alumno alum;

        do
        {
          alum.dni = q->info.dni;
          strcpy(alum.nombre, q->info.nombre);
          fwrite(&alum, sizeof(Alumno), 1, archCurso);
          q = q->sigSub;
        } while (q);

        fclose(archCurso);
      }
    }
    p = p->sig;
    if (p->info.codCurso > 5)
      p = NULL;
  }
}

/* void mostrarArchivo()
{
  char nomArch[20];

  cout << "Nombre archivo (poner al final .dat), f para finalizar" << endl;
  cin >> nomArch;

  while (string(nomArch) != "f")
  {
    FILE *ae = fopen(nomArch, "rb");
    if (ae == NULL)
      cout << "ERROR" << endl;
    else
    {
      Alumno alu;
      fread(&alu, sizeof(Alumno), 1, ae);
      while (!feof(ae))
      {
        cout << alu.dni << " " << alu.nombre << endl;
        fread(&alu, sizeof(Alumno), 1, ae);
      }
      fclose(ae);
    }
    cout << "Nombre archivo (poner al final .dat), f para finalizar" << endl;
    cin >> nomArch;
  }
} */
