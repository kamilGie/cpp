// Kamil Gieras
#include <iostream>
using namespace std;

void TablicaCykliczna();
void wypiszTablice(int *tablica);
void operujNaTablicy(int *tablica);
void Odwrocenie(int *tablica);
void zamianyParami(int *tablica);
void cyklicznePrzesuniecie(int *tablica);
void zamien_elementy(int *wartosc1, int *wartosc2);
void cyklicznePrzesuniecieOdcinkaLewo(int *tablica, int poczatekOdcinka, int dlugosciOdicnka);
void cyklicznePrzesuniecieOdcinkaPrawo(int *tablica, int poczatekOdcinka, int dlugosciOdicnka);
int *wczytaj_tablice(); int obliczIndeks(int indeks); int obliczIlosciFragmentow(int dlugoscL);

int dlugosci_tablicy;//zmiena globalna bo jest potrzebna prawie wszedzie wiec tak wygodniej;

int main()
{
    int ilosci_tablic;
    cin >> ilosci_tablic;
    while (ilosci_tablic--){
        TablicaCykliczna();
    }
}

void TablicaCykliczna()
{
    cin >> dlugosci_tablicy;

    int *tablica = wczytaj_tablice();

    wypiszTablice(tablica);
    operujNaTablicy(tablica);
    wypiszTablice(tablica);

    delete[] tablica;
}

int *wczytaj_tablice()
{
    int *tablica = new int[dlugosci_tablicy];

    for (int i = 0; i < dlugosci_tablicy; i++)
    {
        cin >> tablica[i];
    }
    return tablica;
}

void wypiszTablice(int *tablica)
{
    for (int i = 0; i < dlugosci_tablicy; i++)
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

void Odwrocenie(int *tablica)
{
    int i, L, I;
    cin >> i >> L;

    int ilosciFragmentow = obliczIlosciFragmentow(L);
    while (ilosciFragmentow--)
    {
         I = obliczIndeks(i + L - 1);
        int indeksNastepnegoFragmentu = obliczIndeks(I + 1);
        for (int j = 0; j < L / 2; j++, i++, I--)
        {
            i = obliczIndeks(i);
            I = obliczIndeks(I);
            zamien_elementy(&tablica[i], &tablica[I]);
        }
        i = indeksNastepnegoFragmentu;
    }
}

void zamianyParami(int *tablica)
{
    int i, I, L;
    cin >> i >> L;

    int ilosciFragmentow = obliczIlosciFragmentow(2 * L);
    while (ilosciFragmentow--)
    {
        I = obliczIndeks(i + L);
        for (int j = 0; j < L; j++, i++, I++)
        {
            i = obliczIndeks(i);
            I = obliczIndeks(I);
            zamien_elementy(&tablica[i], &tablica[I]);
        }
        i = obliczIndeks(I);
    }
}

void cyklicznePrzesuniecie(int *tablica)
{
    int i, L, s;
    cin >> i >> L >> s;
    if(L==0) {
        return;
    }

    int ilosciFragmentow = obliczIlosciFragmentow(L);
    while (ilosciFragmentow--)
    {
        int ilosciPrzesuniec = s;

        while (ilosciPrzesuniec > 0)
        {
            cyklicznePrzesuniecieOdcinkaPrawo(tablica, obliczIndeks(i+L-1), L);
            ilosciPrzesuniec--;
        }
        while (ilosciPrzesuniec < 0)
        {
            cyklicznePrzesuniecieOdcinkaLewo(tablica, obliczIndeks(i), L);
            ilosciPrzesuniec++;
        }

        i = obliczIndeks(i + L);
    }

    int dlugosciFragmenuMniejszegoNizL = dlugosci_tablicy %L;
    if(dlugosciFragmenuMniejszegoNizL)
    {
        while (s > 0)
        {
            cyklicznePrzesuniecieOdcinkaPrawo(tablica, obliczIndeks(i+dlugosciFragmenuMniejszegoNizL-1), dlugosciFragmenuMniejszegoNizL);
            s--;
        }
        while (s < 0)
        {
            cyklicznePrzesuniecieOdcinkaLewo(tablica, obliczIndeks(i), dlugosciFragmenuMniejszegoNizL);
            s++;
        }
    }
}

void cyklicznePrzesuniecieOdcinkaPrawo(int *tablica, int ostatniIndeks, int dlugosciOdicnka)
{
    for (int i = 1; i < dlugosciOdicnka; i++)
    {
        zamien_elementy(&tablica[ostatniIndeks],&tablica[obliczIndeks(ostatniIndeks-1)]);
        ostatniIndeks=obliczIndeks(ostatniIndeks-1);
    }
}

void cyklicznePrzesuniecieOdcinkaLewo(int *tablica, int pierwszyIndeks, int dlugosciOdicnka)
{
    for (int i = 1; i < dlugosciOdicnka; i++)
    {
        zamien_elementy(&tablica[pierwszyIndeks],&tablica[obliczIndeks(pierwszyIndeks+1)]);
        pierwszyIndeks=obliczIndeks(pierwszyIndeks+1);
    }
}

int obliczIndeks(int indeks)
{
    return indeks >= 0 ? indeks % dlugosci_tablicy : (indeks % dlugosci_tablicy) + dlugosci_tablicy;
}

void zamien_elementy(int *wartosc1, int *wartosc2)
{
    int tmp = *wartosc1;
    *wartosc1 = *wartosc2;
    *wartosc2 = tmp;
}

int obliczIlosciFragmentow(int dlugoscL)
{
    int ilosciFragmentow = 0;
    if(dlugoscL==0){
        return ilosciFragmentow;
    }
    while (ilosciFragmentow <= dlugosci_tablicy)
    {
        ilosciFragmentow += dlugoscL;
    }
    ilosciFragmentow /= dlugoscL;
    return --ilosciFragmentow;
}