// LISTA SIMPLE

void insertar(Nodo *&lista, Personas persona)
{
    Nodo *q, *p, *ant;
    q = new Nodo;
    q->info = persona;
    p = lista;
    while (p != NULL && p->info.dni < persona.dni)
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

// junto con ordenar2 cambia el orden de los nodos
void insertarLog(Nodo *&lista, Nodo *n)
{
    Nodo *r, *ant;

    r = lista;
    while (r != NULL && r->info.< n->info)
    {
        ant = r;
        r = r->sig;
    }
    n->sig = r;
    if (r != lista)
        ant->sig = n;
    else
        lista = n;
}

void ordenar2(Nodo *&lista)
{
    Nodo *listaOrd = NULL;
    Nodo *r;
    while (lista != NULL)
    {
        r = lista;
        lista = lista->sig;
        insertarLog(listaOrd, r);
    }
    lista = listaOrd;
}

bool eliminar(Nodo *&lista, int dni)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.dni != dni)
    {
        ant = p;
        p = p->sig;
    }

    if (p != NULL)
    {
        if (p == lista)
            lista = p->sig;
        else
            ant->sig = p->sig;
        delete p;
        return true;
    }
    else
        return false;
    // cout<<"no existe";
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL) // p
    {
        cout << p->info.stock << " --- " << p->info.cod << endl;
        p = p->sig;
    }
}

Nodo *buscar(Nodo *lista, int unLeg)
{
    Nodo *p;
    p = lista;
    while (p != NULL && p->info.leg < unLeg)
        p = p->sig;
    if (p == NULL || p->info.leg != unLeg)
        return NULL;
    else
        return p;
}

void mostrarNota(Nodo *lista, int unLeg)
{
    // dado un legajo, muestra su nota
    Nodo *p = buscar(lista, unLeg);
    // Nodo*p=buscarMejor(lista,unLeg);
    if (p == NULL)
        cout << "No hay un alumno con ese legajo" << endl;
    else
        cout << p->info.nota << endl;
}

Nodo *buscarInsertar(Nodo *&lista, Alumno alu)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.leg < alu.leg)
    {
        ant = p;
        p = p->sig;
    }
    if (p == NULL || p->info.leg != alu.leg)
    {
        Nodo *q = new Nodo;
        q->info = alu;
        q->sig = p;
        if (p != lista)
            ant->sig = q;
        else
            lista = q;
        return q;
    }
    else
        return p;
    // p->info.nota=alu.nota;
}

void agregarAdelante(Nodo *&lista, int dato)
{
    Nodo *n = new Nodo;
    n->info = dato;
    n->sig = lista;
    lista = n;
}

void apareo(Nodo *lista1, Nodo *lista2)
{
    Nodo *p1, *p2;
    p1 = lista1;
    p2 = lista2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->info.leg < p2->info.leg)
        {
            cout << p1->info.leg << p1->info.nom << p1->info.nota << endl;
            p1 = p1->sig;
        }
        else
        {
            if (p1->info.leg == p2->info.leg)
            {
                cout << p1->info.leg << p1->info.nom;
                if (p1->info.nota > p2->info.nota)
                    cout << p1->info.nota << endl;
                else
                    cout << p2->info.nota << endl;
                p1 = p1->sig;
                p2 = p2->sig;
            }
            else
            {
                cout << p2->info.leg << p2->info.nom << p2->info.nota << endl;
                p2 = p2->sig;
            }
        }
    }
    while (p1 != NULL)
    {
        cout << p1->info.leg << p1->info.nom << p1->info.nota << endl;
        p1 = p1->sig;
    }
    while (p2 != NULL)
    {
        cout << p2->info.leg << p2->info.nom << p2->info.nota << endl;
        p2 = p2->sig;
    }
}

void cc1(Nodo *lista)
{
    int legA, suma, cont;
    string nomA;
    Nodo *p = lista;
    while (p != NULL)
    {
        legA = p->info.leg;
        nomA = p->info.nom;
        suma = cont = 0;
        do
        {
            suma += p->info.nota;
            cont++;
            p = p->sig;
        } while (p != NULL && p->info.leg == legA);
        cout << legA << nomA << suma / cont;
    }
}

void cc2(Nodo *lista) // versión con 2 punteros
{
    int suma, cont;
    Nodo *p, *q;
    p = q = lista;
    while (p != NULL)
    {
        // q=p;
        suma = cont = 0;
        do
        {
            suma += q->info.nota;
            cont++;
            q = q->sig;
        } while (q != NULL && q->info.leg == p->info.leg);
        cout << p->info.leg << p->info.nom << suma / cont << endl;
        p = q;
    }
}

// ################################
// LISTA DOBLEMENTE ENLAZADA

void insertar(Nodo *&lis1, Nodo *&lis2, int nro)
{
    Nodo *n = new Nodo;
    n->dato = nro;
    if (lis1 == NULL && lis2 == NULL)
    {
        n->sig = NULL;
        n->ant = NULL;
        lis1 = n;
        lis2 = n;
    }
    else
    {
        Nodo *p = lis1;
        while (p != NULL && p->dato < nro)
            p = p->sig;
        if (p == lis1) // p->ant==NULL
        {
            n->sig = p; // n->sig=lis1;
            n->ant = NULL;
            lis1->ant = n;
            lis1 = n;
        }
        else
        {
            if (p == NULL)
            {
                n->sig = NULL; // n->sig=p;
                n->ant = lis2;
                lis2->sig = n;
                lis2 = n;
            }
            else
            {
                /*
                Nodo*ante;
                ante=p->ant;
                n->sig=p;
                n->ant=ante;
                ante->sig=n;
                p->ant=n;
                */
                n->sig = p;
                n->ant = p->ant;
                p->ant->sig = n;
                p->ant = n;
            }
        }
    }
}

void mostrarAsc(Nodo *l)
{
    Nodo *p = l;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->sig;
    }
}

void mostrarDesc(Nodo *l)
{
    Nodo *p = l;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->ant;
    }
}

// ################################
// LISTA CIRCULAR

void mostrar(Nodo *listaC)
{
    if (listaC != NULL)
    {

        Nodo *p = listaC->sig;
        do
        {
            cout << p->dato << endl;
            p = p->sig;
        } while (p != listaC->sig);
    }
}

void agregar(Nodo *&listaC, int nro)
{
    // agrega un nodo a la lista circular sin orden
    Nodo *n = new Nodo;
    n->dato = nro;
    if (listaC != NULL)
    {
        n->sig = listaC->sig;
        listaC->sig = n;
    }
    else
    {
        n->sig = n;
        listaC = n;
    }
}

void insertar(Nodo *&listaC, int nro)
{
    // agrega un nodo a la lista circular ordenada
    Nodo *n = new Nodo;
    n->dato = nro;
    if (listaC == NULL)
    {
        n->sig = n;
        listaC = n;
    }
    else
    {
        Nodo *p = listaC->sig, *ant = listaC;
        if (p->dato < nro)
        {
            do
            {
                ant = p;
                p = p->sig;
            } while (p != listaC->sig && p->dato < nro);
        }
        n->sig = p;
        ant->sig = n;
        if (n->dato > listaC->dato)
            listaC = n;
    }
}

// ################################
// LISTA c/SUBLISTA

void generar(Nodo *&lista)
{
    Alumno alu;
    Examen exa;
    NodoL *p;
    cout << "DNI alumno: ";
    cin >> dniAl;
    while (dniAl != 0) // ingresa datos del examen
    {
        cout << "Nombre alumno: ";
        cin >> nomAl;
        cout << "Fecha examen: ";
        cin >> fechaEx;
        cout << "Materia rendida: ";
        cin >> codMateria;
        cout << "Nota: ";
        cin >> notaOb;

        alu.dni = dniAl;
        alu.nom = nomAl;
        alu.listaExa = NULL;
        p = buscarInsertar(lista, alu);

        exa.dia = fechaEx;
        exa.codMat = codMateria;
        exa.nota = notaOb;
        insertar(p->info.listaExa, exa);

        cout << "DNI alumno: ";
        cin >> dniAl;
    }
}

void insertar(NodoSL *&lista, Examen ex) // ordenado por fecha
{
    NodoSL *n, *p, *ant;
    n = new NodoSL;
    n->info = ex;
    p = lista;
    while (p != NULL && p->info.fecha < ex.fecha)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista)
        ant->sig = n;
    else
        lista = n;
}

Nodo *buscarInsertar(Nodo *&lista, Alumno al)
{
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.dni < al.dni)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && al.dni == p->info.dni)
        return p;
    else
    {
        Nodo *n = new Nodo;
        n->info = al;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}
