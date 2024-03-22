//kamil gieras
void Add(int wartosc, int *zbiorWyjsciowy)
{
    if (wartosc <= 0 || wartosc > 4095)
        return;

    int i = 0;
    for (; zbiorWyjsciowy[i] != -1; i++)
    {
        if (zbiorWyjsciowy[i] == wartosc)
            return;
    };
    zbiorWyjsciowy[i + 1] = -1;
    zbiorWyjsciowy[i] = wartosc;
}

void Create(int rozmiar_tablicy, int zbiorLiczbWejsciowy[], int *zbiorWyjsciowy)
{
    for (int i = 0; i < rozmiar_tablicy; i++)
    {
        Add(zbiorLiczbWejsciowy[i], zbiorWyjsciowy);
    }
}

void Union(int zbiorA[], int zbiorB[], int *zbiorWyjsciowy)
{
    for (int i = 0; zbiorA[i] != -1; i++)
    {
        Add(zbiorA[i], zbiorWyjsciowy);
    }
    for (int i = 0; zbiorB[i] != -1; i++)
    {
        Add(zbiorB[i], zbiorWyjsciowy);
    }
}

void Intersection(int zbiorA[], int zbiorB[], int *zbiorWyjsciowy)
{
    for (int i = 0; zbiorA[i] != -1; i++)
    {
        for (int j = 0; zbiorB[j] != -1; j++)
        {
            if (zbiorA[i] == zbiorB[j])
                Add(zbiorA[i], zbiorWyjsciowy);
        }
    }
}

void Difference(int zbiorA[], int zbiorB[], int *zbiorWyjsciowy)
{

    for (int i = 0; zbiorA[i] != -1; i++)
    {
        bool wystapila = false;
        for (int j = 0; zbiorB[j] != -1; j++)
        {
            if (zbiorA[i] == zbiorB[j])
                wystapila = true;
        }
        if (!wystapila)
            Add(zbiorA[i], zbiorWyjsciowy);
    }
}

void Symmetric(int zbiorA[], int zbiorB[], int *zbiorWyjsciowy)
{
    Difference(zbiorA, zbiorB, zbiorWyjsciowy);
    Difference(zbiorB, zbiorA, zbiorWyjsciowy);
}

void Complement(int zbiorA[], int *zbiorWyjsciowy)
{
    bool wystapila[4096] = {};
    for (int i = 0; zbiorA[i] != -1; i++)
    {
        wystapila[zbiorA[i]] = true;
    }
    for (int i = 1; i < 4096; i++)
    {
        if (!wystapila[i])
            Add(i, zbiorWyjsciowy);
    }
}

bool Subset (int podZbior[], int zbioru[])
{
    for (int i = 0; podZbior[i] != -1; i++)
    {
        int jestToPozdbior=false;
        for (int j = 0; zbioru[j] != -1; j++)
        {
            if(podZbior[i]==zbioru[j])
            jestToPozdbior=true;
        }
        if(!jestToPozdbior)
        return false;
    }
    return true;
}

bool Equal(int zbiorA[], int zbiorB[])
{
    return Subset(zbiorA, zbiorB) && Subset(zbiorB, zbiorA);
}

bool Empty(int zbiorA[])
{
    return zbiorA[0] == -1;
}

bool Nonempty(int zbiorA[])
{
    return !Empty(zbiorA);
}

double Arithmetic (int zbiorA[])
{
    if(zbiorA[0]==-1)
    return 0;

    int ilosciElementow=0;
    double srednia=0;
    for (; zbiorA[ilosciElementow] != -1; ilosciElementow++)
    {
        srednia+=zbiorA[ilosciElementow];
    }
    return srednia =srednia/ilosciElementow;
}

double Harmonic (int zbiorA[])
{
    if(zbiorA[0]==-1)
    return 1;

    int ilosciElementow=0;
    double srednia=0;
    for (; zbiorA[ilosciElementow] != -1; ilosciElementow++)
    {
        srednia=srednia+1.0/zbiorA[ilosciElementow];
    }
    
    return (double)ilosciElementow/srednia;

}

bool Element(int element, int zbiorA[])
{
    for (int i = 0; zbiorA[i] != -1; i++)
    {
        if (zbiorA[i] == element)
        {
            return true;
        }
    }
    return false;
}

void MinMax (int zbiorA[], int *min, int &max)
{
    if(zbiorA[0]==-1)
    return;

    *min=max=zbiorA[0];
    for (int i = 1; zbiorA[i] != -1; i++)
    {
        if(*min>zbiorA[i])
            *min=zbiorA[i];

        if(max<zbiorA[i])
            max=zbiorA[i];
    }

}

void Cardinality (int zbiorA[], int *ilosciElementow)
{
    *ilosciElementow=0;
    while (zbiorA[*ilosciElementow] != -1)
    {
        (*ilosciElementow)++;
    }
}

void Properties(int zbiorA[], char znaki[], double &sredniaArmetyczna, double *sredniaHarmoniczna, int & minimum, int *maksimum, int& mocZbioru)
{
    for(int i=0;znaki[i]!='\0';i++)
    {
        if(znaki[i]=='a'||znaki[i]=='A')
            sredniaArmetyczna= Arithmetic(zbiorA);

        if(znaki[i]=='h'||znaki[i]=='H')
            *sredniaHarmoniczna= Harmonic(zbiorA);

        if(znaki[i]=='m'||znaki[i]=='M')
            MinMax(zbiorA,&minimum,*maksimum);

        if(znaki[i]=='c'||znaki[i]=='C')
            Cardinality(zbiorA,&mocZbioru);
    }
}
