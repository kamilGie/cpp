#include <iostream>
using namespace std;

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
        Add(zbiorA[i], zbiorWyjsciowy);
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
        if (wystapila == false)
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
        if (wystapila[i] == false)
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
        if(jestToPozdbior==false)
        return false;
    }
    return true;
}


bool Equal (int zbiorA[], int zbiorB[])
{
    if(Subset(zbiorA,zbiorB) && Subset(zbiorA,zbiorB) )
    return true;
    else
    return false;
}


bool Empty (int zbiorA[])
{
    if(zbiorA[0]==-1)
    return true;
    else
    return false;
}
bool Nonempty (int zbiorA[])
{
    if(Empty(zbiorA)==false)
    return true;
    else
    return false;

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
         cout<<ilosciElementow<<" "<<srednia<<endl;
    }
    
    return (double)ilosciElementow/srednia;

}

bool Element (int element, int zbiorA[])
{
    int tablicaElementu[2]={element,-1};
 
    if(Subset(tablicaElementu,zbiorA)==true)
    return true;
    else
    return false;
}

void MinMax (int zbiorA[], int *min, int *max)
{
    if(zbiorA[0]==-1)
    return;

    *min=*max=zbiorA[0];
    for (int i = 0; zbiorA[i] != -1; i++)
    {
        if(*min>zbiorA[i])
            *min=zbiorA[i];

        if(*max<zbiorA[i])
            *max=zbiorA[i];
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
void Properties(int zbiorA[], char znaki[], double&, double*, int&, int*, int&);