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

void WypiszRanking()
{
     //wypisuje statystyki gracza ktory cos tam gral
}

int wynik_wszystkie_jednakowe_rzuty(short rzut[])
{

            return false;//jak rzuty nie sa jednakowe

            return 4;// jak rzuty to np 4 4 4 4
}

int KtoWygral(short rzuty_gracza_1[], short rzuty_gracza_2[]) {
    int wynik1, wynik2;
    //dla kazdego argumentu sprawdzam czy zachodzi
    // jak zachodzi daje jego wartosci np 
    wynik1 = wynik_wszystkie_jednakowe_rzuty(rzuty_gracza_1);//dla 3 3 3 3 da wartosc tutaj 3 
    wynik2 = wynik_wszystkie_jednakowe_rzuty(rzuty_gracza_2);//dla 3 2 1 4 nie mamy wszystrkich wynikow jedankowcy wiec zwracamy 0 
    if (wynik1 != wynik2) return (wynik1 > wynik2 ? 1 : 2);//jak jeden jest rowny 3 a drugi 0 no to nie sa rowne i zwracamy tego gracza co ma wiekszy wynik jako wygranego
    //i tak dalej i tak dalej dla kazdego argumentu jakies tam sa bylo ich 5 wiec trzeba troceh takich funkcji napisac



    //jak przejdzie przez wszystkie warunki bez wygranego to znaczy ze mamy remis lol
    return 0;

}

void Pojedynek()
{
    char gracz_1, gracz_2;
    short rzuty_gracza_1[4], rzuty_gracza_2[4];
    //trzeba wczytac te dane 

    int WygranyGracz = KtoWygral(rzuty_gracza_1, rzuty_gracza_2); // zwroci 0 jak remis 1 jak wygral gracz 1 2 jak wygral gracz 2 

   //musi potem cos z ta informacaj ktoru gracz wygral robic 
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