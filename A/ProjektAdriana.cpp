// Adrian Płonka
#include <iostream>
using namespace std;

int tosamo(int rzut[])
{
    for (int i = 0; i < 3; i++)
    {
        if (rzut[i] != rzut[i + 1])
            return false;
    }
    return rzut[0];
}

bool bezpow(int rzut[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if (rzut[i] == rzut[j])//to nie zadziaka wystarczy ze rzuty[0]!=rzuty[1] i juz zwroci ze prawda jest ze wszystkie sa inne a to ma patrzec czy kazdy jest inny(pomysl na odwrot)
                return false;
        }
    }
    return true;
}
int dwieroz(int rzut[])
{
    int najwieksze = 0;
    for (int i = 0; i < 4; i++)
    {
        int ilepow=0;
        for (int j = 0; j < 4; j++)//to nie zadziala od 1 indeksu po pomijajac indeks 0 np dla rzutow 1 1 2 2 ile pow bedzie wynosic 1 bo dla i=0
        {
            if (rzut[i] == rzut[j]) 
                ilepow++;
        }
        if (ilepow != 2)
            return false;
        if (najwieksze < rzut[i])
            najwieksze = rzut[i];
            //to nie powino byc tutaj po 1 literacji petli juz ci zwroci najwieksza nie sprawdzajac reszty
    }
    return najwieksze;
}

int trzytakiesame(int rzut[])
{
    
    for (int i = 0; i < 2; i++)
    {   int ilepow=0;
        for (int j = 0; j < 4; j++)// musisz ogarnac bardziej te podwojne petle rzuty (3 2 3 3)tutaj zworca ze nie sa prawda ze sa 3 powtorzenia 
        {
            if (rzut[i] == rzut[j])
                ilepow++;
        }

        if (ilepow == 3)
            return rzut[i];
    }
    return false; 
}

int dwatakiesame(int rzut[])
{
    int ilepow = 0;
        int czypara;
    {
    
        for (int i = 0; i < 4; i++)
        {
            for (int j = i+1; j < 4; j++)
            {
                if (rzut[i] == rzut[j]) {
                    ilepow++;
                    czypara=rzut[i];
                }
            }

            //niestaty ta funkcja musi sprawdzac tez czy nie ma dwoch par a nie tylko 1 wiec np 3 3 2 2 ma zwracac falsz bo teraz jakby tu doszlo np (3 3 2 2 )z (2 2 3 3 )napisal by ze 1 gracz wygral a to jest remis. wystarczy zamiast zwracac wynik liczyc  ile jest takich par jak po petlach bedzie 1 to znaczy ze mamy jedna para i zwraca ta pare  
                
        }
    }
    if(ilepow==1) 
    return czypara;
    else 
    return false;
}

int nic(int rzut[])// ta funkcja wgl nie jest uzywana a tam pod koniec by sie sprzydala by sprawdzala ta sume 
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = sum + rzut[i];
    }
    return sum;
}

int liczwyniki(int rzutyA[], int rzutyB[])
{
    int wynikA, wynikB;
    wynikA = tosamo(rzutyA);
    wynikB = tosamo(rzutyB);
    if (wynikA != wynikB)
        return (wynikA > wynikB ? 1 : 2);

    wynikA = bezpow(rzutyA);
    wynikB = bezpow(rzutyB);
    if (wynikA != wynikB)
        return (wynikA > wynikB ? 1 : 2);

    wynikA = dwieroz(rzutyA);
    wynikB = dwieroz(rzutyB);
    if (wynikA != wynikB)
        return (wynikA > wynikB ? 1 : 2);

    wynikA = trzytakiesame(rzutyA);
    wynikB = trzytakiesame(rzutyB);
    if (wynikA != wynikB)
        return (wynikA > wynikB ? 1 : 2);

    wynikA = dwatakiesame(rzutyA);
    wynikB = dwatakiesame(rzutyB);
    if (wynikA != wynikB)
        return (wynikA > wynikB ? 1 : 2);

    wynikA = nic(rzutyA);
    wynikB = nic(rzutyB);
    if (wynikA != wynikB)
        return (wynikA > wynikB ? 1 : 2);

    return 0;
}

int main()
{
    int N;
    cin >> N;
    int wygrana[26] = {0}, remis[26] = {0}, przegrana[26] = {0};
    int gry[26] = {0};

    for (int i = 0; i < N; i++)
    {
        char idA, idB;
        int rzutyA[4], rzutyB[4];
        cin >> idA >> rzutyA[0] >> rzutyA[1] >> rzutyA[2] >> rzutyA[3] >> idB >> rzutyB[0] >> rzutyB[1] >> rzutyB[2] >> rzutyB[3];

        int WygranyGracz = liczwyniki(rzutyA, rzutyB);
        gry[idA - 'a']++;
        gry[idB - 'a']++;
        if (WygranyGracz == 1)
        {
            wygrana[idA - 'a']++;
            przegrana[idB - 'a']++;
        }
        else if (WygranyGracz == 0)
        {
            remis[idA - 'a']++;
            remis[idB - 'a']++;
        }
        else
        {
            przegrana[idA - 'a']++;
            wygrana[idB - 'a']++;
        }
    }
    bool czygracz = true;
    for (char gracz = 'a'; gracz <= 'z'; gracz++)
    {
        int idx = gracz - 'a';
        if (gry[idx] > 0)
        {
            if (!czygracz)
            {
                cout << endl;
            }
            else
            {
                czygracz = 0;
            }
            cout << "gracz " << gracz << endl;
            if (wygrana[idx] > 0)
                cout << "    wygrane: " << (static_cast<double>(100 * wygrana[idx]) / gry[idx]) << "%\n";
            if (remis[idx] > 0)
                cout << "    remisy: " << (static_cast<double>(100 * remis[idx]) / gry[idx]) << "%\n";
            if (przegrana[idx] > 0)
                cout << "    przegrane: " << (static_cast<double>(100 * przegrana[idx]) / gry[idx]) << "%\n";
        }
    }
    return 0;
}
