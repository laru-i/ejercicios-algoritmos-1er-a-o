
void apilar(Nodo *&pila, Personas dato)
{

    Nodo *p = new Nodo;
    p->info = dato;
    p->sig = pila;
    pila = p;
}

void desapilar(Nodo *&pila, Personas &persona)
{
    if (pila == NULL)
        cout << "ERROR, la pila esta vacia" << endl;
    else
    {
        Nodo *p;
        p = pila;
        persona = p->info;
        pila = p->sig;
        delete p;
    }
}

void encolar(NodoCola*&pri,NodoCola*&ult,int dato)
{
    NodoCola*p=new NodoCola;
    p->info=dato;
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p
    else
        pri=p;
    ult=p;
}

int desencolar(NodoCola*&pri,NodoCola*&ult)
{
    int dato;
    NodoCola*p=pri;
    pri=p->sig;
    dato=p->info;
    delete p;
    if(pri==NULL)
        ult=NULL;
    return dato;
}
