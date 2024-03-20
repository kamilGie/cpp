//Kamil Gieras



//############# tresc tego zadania jest tak nie jasna ze nie zrobie tego programu do czasu jak ono nie wyladuje i nie dopytam o co chodzi
#include <iostream>
using namespace std;

int wielkosci_tablicy;

void TablicaCykliczna();
int *wczytaj_tablice();
void wypiszTablice(int *tablica);
void operujNaTablicy(int *tablica);
void Odwrocenie(int *tablica);
void cyklicznePrzesuniecie(int *tablica);
void zamianyParami(int *tablica);
void cyklicznePrzesuniecieOdcinkaPrawo(int *tablica,int poczatekOdcinka,int dlugosciOdicnka);
void cyklicznePrzesuniecieOdcinkaLewo(int *tablica,int poczatekOdcinka,int dlugosciOdicnka);
int obliczIndeks(int indeks);
void zamien_elementy(int *wartosc1,int *wartosc2);

int main()
{
    int ilosci_tablic;
    cin >> ilosci_tablic;
    while (ilosci_tablic--)
        TablicaCykliczna();

    return 0;
}

void TablicaCykliczna()
{
    cin >> wielkosci_tablicy;

    int *tablica = wczytaj_tablice();

    wypiszTablice(tablica);
    operujNaTablicy(tablica);
    wypiszTablice(tablica);

    delete[] tablica;
}

int *wczytaj_tablice()
{
    int *tablica = new int[wielkosci_tablicy];
    for (int i = 0; i < wielkosci_tablicy; i++)
    {
        cin >> tablica[i];
    }
    return tablica;
}

void wypiszTablice(int *tablica)
{
    for (int i = 0; i < wielkosci_tablicy; i++)
    {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

void operujNaTablicy(int *tablica)
{
    char znakOperacji = 'X';
    while (znakOperacji != 'F')
    {
        wypiszTablice(tablica);
        cin >> znakOperacji;
        switch (znakOperacji)
        {
        case 'R':
            Odwrocenie(tablica);
            break;
        case 'C':
            cyklicznePrzesuniecie(tablica);
            break;
        case 'S':
            zamianyParami(tablica);
            break;
        default:
            break;
        }
    }
}

void Odwrocenie(int *tablica )
{
    cout<<"odwracam"<<endl;
    int i, L, I, drugiObieg_i;
    cin >> i >> L;

    if(L*2>wielkosci_tablicy)
    return;


    bool pierwszyObieg = true;
    i=obliczIndeks(i);
    drugiObieg_i = obliczIndeks(i + L);
 
    while (true)
    {
        I = obliczIndeks( i + L - 1);
        for (int j = 0; j < L / 2; j++,i++,I--)
        {
            i = obliczIndeks( i );
            I = obliczIndeks( I );
            zamien_elementy(&tablica[i],&tablica[I]);
        }
        if (pierwszyObieg==false)
            break;

        pierwszyObieg = false;
        i = drugiObieg_i;
        
    }
}

void zamianyParami(int *tablica )
{
    cout<<"zamieniam parami"<<endl;

    int i,I, L;
    cin >> i >> L;
    i=obliczIndeks(i);
    I=obliczIndeks(i+L);

    if(L*2>wielkosci_tablicy)
    return;

    for (int j=0;j<L;j++,i++,I++)
    {
         i = obliczIndeks(i);
         I = obliczIndeks(I);
        cout<<i<<" "<<I<<endl;
         zamien_elementy(&tablica[i],&tablica[I]);
    }
}

void cyklicznePrzesuniecie(int *tablica)
{
    cout<<"cyklicznie przesuwam"<<endl;

    int i, L, s;
    cin >> i >> L >> s; 
    while(s>0)
    {
        cyklicznePrzesuniecieOdcinkaPrawo(tablica,obliczIndeks(i),L);
        cyklicznePrzesuniecieOdcinkaPrawo(tablica,obliczIndeks(i+L),L);
        cyklicznePrzesuniecieOdcinkaPrawo(tablica,obliczIndeks(i+2*L),wielkosci_tablicy-2*L);
        s--;
    }
    while(s<0)
    {
        cyklicznePrzesuniecieOdcinkaLewo(tablica,obliczIndeks(i),L);
        cyklicznePrzesuniecieOdcinkaLewo(tablica,obliczIndeks(i+L),L);
        cyklicznePrzesuniecieOdcinkaLewo(tablica,obliczIndeks(i+2*L),wielkosci_tablicy-2*L);
        s++;
    }
}

void cyklicznePrzesuniecieOdcinkaPrawo(int *tablica,int pierwszyIndeks,int dlugosciOdicnka)
{
    if(dlugosciOdicnka<1)
    return;

    int ostatniIndeks=obliczIndeks(pierwszyIndeks+dlugosciOdicnka-1);
    int ostatniElement=tablica[ostatniIndeks];
    
    for(int i=1;i<dlugosciOdicnka;i++)
    {
        tablica[ostatniIndeks]=tablica[obliczIndeks(ostatniIndeks-1)];
        ostatniIndeks=obliczIndeks(ostatniIndeks-1);

    }
    tablica[pierwszyIndeks]=ostatniElement;
}

void cyklicznePrzesuniecieOdcinkaLewo(int *tablica,int pierwszyIndeks,int dlugosciOdicnka)
{
    if(dlugosciOdicnka<1)
    return;

    int ostatniIndeks=obliczIndeks(pierwszyIndeks+dlugosciOdicnka-1);
    int PierwszyElement=tablica[pierwszyIndeks];
    
    for(int i=1;i<dlugosciOdicnka;i++)
    {
        tablica[pierwszyIndeks]=tablica[obliczIndeks(pierwszyIndeks+1)];
        pierwszyIndeks=obliczIndeks(pierwszyIndeks+1);

    }
    tablica[ostatniIndeks]=PierwszyElement;
}

int obliczIndeks( int indeks){
    return indeks >= 0 ? indeks % wielkosci_tablicy : (indeks % wielkosci_tablicy) + wielkosci_tablicy;
}

void zamien_elementy(int *wartosc1,int *wartosc2){
    int tmp = *wartosc1;
    *wartosc1 = *wartosc2;
    *wartosc2 = tmp;
}