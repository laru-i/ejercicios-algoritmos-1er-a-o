// BUSQUEDAS

int secuencial(int v[], unsigned t, int bus)
{
    unsigned i = 0;
    while (i < t && v[i] != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}

int binaria(int v[], unsigned t, int bus)
{
    int desde = 0, hasta = t - 1, medio;
    do
    {
        medio = (desde + hasta) / 2;

        if (bus < v[medio])
            hasta = medio - 1;
        else
            desde = medio + 1;

    } while (desde <= hasta && v[medio] != bus);
    if (v[medio] == bus)
        return medio;
    else
        return -1;
}

// ORDENAMIENTOS
void burbujeo(int v[], unsigned t)
{
    unsigned i = 1, j;
    int aux;
    bool cambio;
    do
    {
        cambio = false;
        for (j = 0; j < t - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cambio = true;
            }
        }
        i++;
    } while (i < t && cambio);
}

void seleccion(int v[], unsigned t)
{
    unsigned i, j;
    int menor, pos;
    for (i = 0; i < t - 1; i++)
    {
        menor = v[i];
        pos = i;
        for (j = i + 1; j < t; j++)
        {
            if (v[j] < menor)
            {
                menor = v[j];
                pos = j;
            }
        }
        v[pos] = v[i];
        v[i] = menor;
    }
}

void insercion(int v[], unsigned t)
{
    unsigned i;
    int a, j;
    for (i = 1; i < t; i++)
    {
        a = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > a)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = a;
    }
}

// MATRICES
void inicializar(int v[], int t)
{
    for (int i = 0; i < t; i++)
        v[i] = 0;
}

void cargarPorColumna(int m[][6], int cf, int cc)
{
    for (int c = 0; c < cc; c++)
    {
        for (int f = 0; f < cf; f++)
        {
            // cout<<"Fila "<<f<<" columna "<<c<<endl;
            // cin>>m[f][c];
        }
    }
}

void mostrarPorFila(int m[][6], int cf, int cc)
{
    for (int i = 0; i < cf; i++)
    {
        for (int j = 0; j < cc; j++)
        // cout<<m[i][j]<<"   ";
        // cout<<endl;
    }
}

void mostrarCol(int m[][25], int cf, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < cf; j++)
        {
            cout << m[j][i] << " ";
        }
        cout << endl;
    }
}

void sumatoriaFilas(int m[][6], int cf, int cc, int vf[])
{
    // int s;
    for (int i = 0; i < cf; i++)
    {
        // s=0;
        // vf[i]=0;
        for (int j = 0; j < cc; j++)
        {
            // s+=m[i][j];
            vf[i] += m[i][j];
        }
        // vf[i]=s;
    }
}

void sumatoriaColumnas(int m[][6], int cf, int cc, int vc[])
{

    for (int j = 0; j < cc; j++)
        for (int i = 0; i < cf; i++)
            vc[j] += m[i][j];
}
void sumatoria(int m[][25], int vc[], int cf, int cc)
{
    for (int i = 0; i < cc; i++)
    {
        for (int j = 0; j < cf; j++)
            vc[i] += m[j][i];
    }
}
void mostrarMayor(int m[][25], int vm[], int cf, int cc)
{
    for (int i = 0; i < cf; i++)
    {
        int mayor = m[i][0];
        for (int j = 0; j < cc; j++)
        {
            if (m[i][j] > mayor)
                mayor = m[i][j];
        }
        vm[i] = mayor;
    }
}