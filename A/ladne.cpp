//kamil gieras
#include <iostream>
#define MaxGraczy 26

using namespace std;

//##########! Sposob postrzegania tablic globalnych !##################//
                    //gracz[0]==a gracz[1]==b
char Gracze[MaxGraczy];
int WygraneGracza[MaxGraczy] = {0};
int PrzegraneGracza[MaxGraczy] = {0};
int RemisyGracza[MaxGraczy] = {0};


//##################       przegladac od int main nie od gory       !##################//

double oblicz_procent(int numer_gracza, int liczba_zdarzen)
{
    double wszystkie_zdarzenia=(WygraneGracza[numer_gracza] + RemisyGracza[numer_gracza] + PrzegraneGracza[numer_gracza]);

    return 100 * (double)liczba_zdarzen / wszystkie_zdarzenia;
}

void WypiszStatystykiGracza(int numer_gracza)
{
    double procent_wygranych = oblicz_procent(numer_gracza, WygraneGracza[numer_gracza]);
    double procent_remisow = oblicz_procent(numer_gracza, RemisyGracza[numer_gracza]);
    double procent_przegranych = oblicz_procent(numer_gracza, PrzegraneGracza[numer_gracza]);
    
    cout << "gracz " << Gracze[numer_gracza] << endl;
    if (WygraneGracza[numer_gracza])
        cout << "    wygrane: " << procent_wygranych << "%"<<endl;
    if (RemisyGracza[numer_gracza])
        cout << "    remisy: " << procent_remisow << "%"<<endl;
    if (PrzegraneGracza[numer_gracza])
        cout << "    przegrane: " << procent_przegranych << "%"<<endl;
        
}

void WypiszRanking()
{
    int flaga=0;
    for (int i = 0; i < MaxGraczy; i++){
        if (WygraneGracza[i] || PrzegraneGracza[i] || RemisyGracza[i])
        {
            if(flaga==0)
            flaga=1;
            else
            cout<<endl;
            WypiszStatystykiGracza(i);

        }
    }
}



int wynik_wszystkie_jednakowe_rzuty(short rzut[])
{
    for (int i = 0; i < 3; i++)
    {
        if (rzut[i] != rzut[i + 1])
            return false;
    }
    return rzut[0];
}

bool wszystkie_rozne_rzuty(short rzuty[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if(rzuty[i]==rzuty[j])
            return false;
        }
    }
    return true;
}

int wynik_dwa_pary_rzutow_rozne(short rzut[])
{
    int najwieksza_para = 0;
    for (int i = 0; i < 4; i++)
    {
        int licznik = 0;
        for (int j = 0; j < 4; j++)
        {
            if (rzut[i] == rzut[j])//kazda pare sprawdzam dla 4 rzutow raz napewno licznik sie powiekszy bo bedzie sprawdzal swoj indeks
                licznik++;
        }
        if (licznik != 2)
            return false;//jak licznik nie jest 2 to oznacza ze takich samych rzutow jest wiecej np 1 lub mniej np 3 wiec zwraca ze nie ma 2 par

        if (najwieksza_para < rzut[i])//tu licze jaka para jest najwieksza nie musze znac obu par musze znac wartosc najwiekszej
            najwieksza_para = rzut[i];
    }
    return najwieksza_para;//po wyjsciu z 2 petli mam wartosci najwiekszej pary z 2 par 
}

int wynik_trzy_jednakowe_rzuty(short rzut[])
{
    for (int i = 0; i < 2; i++)
    {
        int licznik = 0;
        for (int j = 0; j < 4; j++)
        {
            if (rzut[i] == rzut[j])
                licznik++;
        }
        if (licznik == 3)
            return rzut[i];
    }
    return false;
}

int wynik_pary_rzutow(short rzuty[])
{
   int licznik_par = 0;
   int para;

    for (int i = 0; i < 4; i++) 
    {
        for (int j = i + 1; j < 4; j++) 
        {
            if (rzuty[i] == rzuty[j]) 
            {
                licznik_par++;
                para=rzuty[i];
            }
        }
    }

    if(licznik_par==1)
    return para;
    else
    return false;
}

int wynik_sumarycznie_rzutow(short rzuty[])
{
    int wynik = 0;
    for (int i = 0; i < 4; i++){
        wynik += rzuty[i];
    }
    return wynik;
}

int KtoWygral(short rzuty_gracza_1[], short rzuty_gracza_2[]) {
    int wynik1, wynik2;
    //dla kazdego argumentu sprawdzam czy zachodzi
    // jak zachodzi daje jego wartosci np 
    wynik1 = wynik_wszystkie_jednakowe_rzuty(rzuty_gracza_1);//dla 3 3 3 3 da wartosc tutaj 3 
    wynik2 = wynik_wszystkie_jednakowe_rzuty(rzuty_gracza_2);//dla 3 2 1 4 nie mamy wszystrkich wynikow jedankowcy wiec zwracamy 0 
    if (wynik1 != wynik2) return (wynik1 > wynik2 ? 1 : 2);//jak jeden jest rowny 3 a drugi 0 no to nie sa rowne i zwracamy tego gracza co ma wiekszy wynik jako wygranego
    //i tak dalej i tak dalej dla kazdego argumentu 
    wynik1 = wszystkie_rozne_rzuty(rzuty_gracza_1);
    wynik2 = wszystkie_rozne_rzuty(rzuty_gracza_2);
    if (wynik1 != wynik2) return (wynik1 > wynik2 ? 1 : 2);

    wynik1 = wynik_dwa_pary_rzutow_rozne(rzuty_gracza_1);
    wynik2 = wynik_dwa_pary_rzutow_rozne(rzuty_gracza_2);
    if (wynik1 != wynik2) return (wynik1 > wynik2 ? 1 : 2);

    wynik1 = wynik_trzy_jednakowe_rzuty(rzuty_gracza_1);
    wynik2 = wynik_trzy_jednakowe_rzuty(rzuty_gracza_2);
    if (wynik1 != wynik2) return (wynik1 > wynik2 ? 1 : 2);

    wynik1 = wynik_pary_rzutow(rzuty_gracza_1);
    wynik2 = wynik_pary_rzutow(rzuty_gracza_2);
    if (wynik1 != wynik2) return (wynik1 > wynik2 ? 1 : 2);

    wynik1 = wynik_sumarycznie_rzutow(rzuty_gracza_1);
    wynik2 = wynik_sumarycznie_rzutow(rzuty_gracza_2);
    if (wynik1 != wynik2) return (wynik1 > wynik2 ? 1 : 2);

    //jak przejdzie przez wszystkie warunki bez wygranego to znaczy ze mamy remis lol
    return 0;

}

void Pojedynek()
{
    char gracz_1, gracz_2;
    short rzuty_gracza_1[4], rzuty_gracza_2[4];
    int WygranyGracz;
    

    cin >> gracz_1 >>rzuty_gracza_1[0]>>rzuty_gracza_1[1]>>rzuty_gracza_1[2]>>rzuty_gracza_1[3]>>gracz_2>>rzuty_gracza_2[0]>>rzuty_gracza_2[1]>>rzuty_gracza_2[2]>>rzuty_gracza_2[3];

    WygranyGracz = KtoWygral(rzuty_gracza_1, rzuty_gracza_2); // zwroci 0 jak remis

    switch (WygranyGracz) {
        case 1:
            ++WygraneGracza[gracz_1 - 'a'];
            ++PrzegraneGracza[gracz_2 - 'a'];
            break;
        case 2:
            ++WygraneGracza[gracz_2 - 'a'];
            ++PrzegraneGracza[gracz_1 - 'a'];
            break;
         default :
            ++RemisyGracza[gracz_1 - 'a'];
            ++RemisyGracza[gracz_2 - 'a'];
            break;
    }
}

int main()
{
     for (int i = 0; i < MaxGraczy; i++){
        Gracze[i] = 'a' + i;//gracz[0]==a gracz[1]==b
    }
    unsigned ilosci_gier;
    cin >> ilosci_gier;
    for (int i = 0; i < ilosci_gier; i++)
    {
        Pojedynek();
    }
    WypiszRanking();

    return 0;
}