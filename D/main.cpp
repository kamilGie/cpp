#include "proces.hpp"

sklad SKLAD(0, 0, 0, 0, 0, 0);

int main()
{
    string polecenie;
    while (true)
    {
        cin >> polecenie;
        if (polecenie == "END")
            break;

        listaPoleceni[polecenie]();
    }

    return 0;
}

void FILL()
{
    int ilosciMagazynow, ilosciRegalow, ilosciPolek, ilosciMiejscaNaTowar;
    unsigned short ilosciTowaru;
    cin >> ilosciMagazynow >> ilosciRegalow >> ilosciPolek >> ilosciMiejscaNaTowar >> ilosciTowaru;
    SKLAD = sklad(ilosciMagazynow, ilosciRegalow, ilosciPolek, ilosciMiejscaNaTowar, ilosciTowaru, 0);
}

void SET_AP()
{
    int wb, rb, sb, Pe;
    cin >> wb >> rb >> sb >> Pe;
    //!\todo Ustaw ilość możliwych miejsc na wartość Pe w magazynie o numerze wb, w regale o numerze rb, na półce o numerze sb
    // Nowo powstałe miejsca mają zerowe ilości towarów i puste etykiety
    // Dotychczasowe miejsca niemieszczące się w zakresie wartości Pe znikają
    // Dotychczasowe miejsca o pozostawionych numerach zachowują swoje ilości oraz etykiety
}

void SET_AS()
{
    int wb, rb, Se, Pe;
    cin >> wb >> rb >> Se >> Pe;
    //!\todo Ustaw ilość półek wynoszącą Se w magazynie o numerze wb, w regale o numerze rb
    // Nowo powstałe półki przyjmują ilość miejsc wynoszącą Pe, z każdym miejscem posiadającym zerową ilość towaru i pustą etykietę
    // Dotychczasowe półki niemieszczące się w zakresie wartości Se znikają
    // Dotychczasowe półki o pozostawionych numerach ustalają swoje parametry z uwzględnieniem parametru Pe jak dla operacji SET-AP wywołanej z parametrami wb rb S Pe
}

void SET_AR()
{
    int wb, Re, Se, Pe;
    cin >> wb >> Re >> Se >> Pe;
    //!\todo Ustaw ilość regałów wynoszącą Re w magazynie o numerze wb
    // Nowo powstałe regały przyjmują ilość półek wynoszącą Se, z każdą półką obejmującą Pe miejsc, z każdym miejscem przechowującym zerową ilość towaru i pustą etykietę
    // Dotychczasowe regały niemieszczące się w zakresie wartości Re znikają
    // Dotychczasowe regały o pozostawionych numerach ustalają swoje parametry z uwzględnieniem wartości Se oraz Pe jak dla operacji SET-AS wywołanej z parametrami wb R Se Pe
}

void SET_AW()
{
    int We, Re, Se, Pe;
    cin >> We >> Re >> Se >> Pe;
    //!\todo Ustaw ilość magazynów w składzie wynoszącą We
    // Nowo powstałe magazyny przyjmują ilość regałów wynoszącą Re, z każdym regałem obejmującym ilość półek wynoszącą Se, z każdą półką obejmującą Pe miejsc, z każdym miejscem przechowującym zerową ilość towaru i pustą etykietę
    // Magazyny niemieszczące się w zakresie wartości We znikają
    // Magazyny o pozostawionych numerach zmieniają parametry z uwzględnieniem wartości Re, Se oraz Pe jak dla operacji SET-AR wywołanej z parametrami W Re Se Pe
}

void SET_HW()
{
    int w, P;
    cin >> w >> P;
    //!\todo Ustaw ilość miejsc na wartość P w magazynie o numerze w, w podręcznej półce
    // Nowo powstałe miejsca przyjmują zerowe ilości towarów i puste etykiety
    // Dotychczasowe miejsca niemieszczące się w zakresie wartości P znikają
    // Miejsca o pozostawionych numerach zachowują swoje ilości oraz etykiety
}

void SET_HR()
{
    int S, P;
    cin >> S >> P;
    //!\todo Ustaw ilość półek wynoszącą S w regale podręcznym składu
    // Nowo powstałe półki przyjmują ilość miejsc wynoszącą P, z każdym miejscem posiadającym zerową ilość towaru i pustą etykietę
    // Półki niemieszczące się w zakresie wartości S znikają, zaś półki o pozostawionych numerach zmieniają ilość miejsc na P z uwzględnieniem wpływu zmian jak dla operacji SET-AP
}

void SET_HS()
{
    int P;
    cin >> P;
    //!\todo Dla podręcznej półki składu ustanawia ilość miejsc na wartość P
    // Nowo powstałe miejsca przyjmują zerowe ilości towarów i puste etykiety
    // Miejsca niemieszczące się w zakresie wartości P znikają
    // Miejsca o pozostawionych numerach zachowują swoje ilości oraz etykiety
}

// Polecenia dodające towary

void PUT_W()
{
    int w, r, s, p, A;
    cin >> w >> r >> s >> p >> A;
    //!\todo Dodać ilość towaru wynoszącą A do miejsca o numerze p na półce o numerze s w regale o numerze r w magazynie o numerze w
}

void PUT_H()
{
    int w, p, A;
    cin >> w >> p >> A;
    //!\todo Dodać ilość towaru wynoszącą A do miejsca o numerze p na podręcznej półce w magazynie o numerze w
}

void PUT_R()
{
    int s, p, A;
    cin >> s >> p >> A;
    //!\todo Dodać ilość towaru wynoszącą A do miejsca o numerze p na półce o numerze s w podręcznym regale składu
}

void PUT_S()
{
    int p, A;
    cin >> p >> A;
    //!\todo Dodać ilość towaru wynoszącą A do miejsca o numerze p w podręcznej półce składu
}

// Polecenie odejmujące towar

void POP_W()
{
    int w, r, s, p, A;
    cin >> w >> r >> s >> p >> A;
    //!\todo Odejmij ilość towaru wynoszącą A od miejsca o numerze p na półce o numerze s w regale o numerze r w magazynie o numerze w
}

void POP_H()
{
    int w, p, A;
    cin >> w >> p >> A;
    //!\todo Odejmij ilość towaru wynoszącą A od miejsca o numerze p na podręcznej półce w magazynie o numerze w
}

void POP_R()
{
    int s, p, A;
    cin >> s >> p >> A;
    //!\todo Odejmij ilość towaru wynoszącą A od miejsca o numerze p na półce o numerze s w podręcznym regale składu
}

void POP_S()
{
    int p, A;
    cin >> p >> A;
    //!\todo Odejmij ilość towaru wynoszącą A od miejsca o numerze p w podręcznej półce składu
}

// Polecenie przenoszące towar

void MOV_W()
{
    int wb, rb, sb, we, re, se, p, A;
    cin >> wb >> rb >> sb >> we >> re >> se >> p >> A;
    //!\todo Przenieś ilość towaru wynoszącą A z magazynu o numerze wb, z regału o numerze rb, z półki o numerze sb
    // do magazynu o numerze we, do regału o numerze rb, na półkę o numerze se między miejscami o numerach p
}

void MOV_H()
{
    int w, r, s, p, A;
    cin >> w >> r >> s >> p >> A;
    //!\todo Przenieś ilość towaru wynoszącą A z magazynu o numerze w, z regału o numerze r, z półki o numerze s
    // do własnej magazynowej półki podręcznej między miejscami o numerach p
}

void MOV_R()
{
    int w, r, sb, se, p, A;
    cin >> w >> r >> sb >> se >> p >> A;
    //!\todo Przenieś ilość towaru wynoszącą A z magazynu o numerze w, z regału o numerze r, z półki o numerze sb
    // do podręcznego regału składu na półkę o numerze se między miejscami o numerach p
}

void MOV_S()
{
    int s, p, A;
    cin >> s >> p >> A;
    //!\todo Przenieś ilość towaru wynoszącą A z podręcznego regału składu z półki o numerze s
    // do podręcznej półki składu między miejscami o numerach p
}

// Polecenia wyświetlające informacje

void GET_E()
{
    //!\todo Wyświetl sumaryczną ilość towaru w całym składzie
}

void GET_W()
{
    int w;
    cin >> w;
    //!\todo Wyświetl ilość towaru w magazynie o numerze w
}

void GET_RW()
{
    int w, r;
    cin >> w >> r;
    //!\todo Wyświetl ilość towaru w magazynie o numerze w, na regale o numerze r
}

void GET_RH()
{
    //!\todo Wyświetl ilość towaru w podręcznym regale składu
}

void GET_SW()
{
    int w, r, s;
    cin >> w >> r >> s;
    //!\todo Wyświetl ilość towaru w magazynie o numerze w, na regale o numerze r, na półce o numerze s
}

void GET_SH()
{
    int w;
    cin >> w;
    //!\todo Wyświetl ilość towaru w magazynie o numerze w na podręcznej półce
}

void GET_SR()
{
    int s;
    cin >> s;
    //!\todo Wyświetl ilość towaru w podręcznym regale na półce o numerze s
}

void GET_S()
{
    //!\todo Wyświetl ilość towaru na podręcznej półce składu
}
// Polecenia etykietowe

void SET_LW()
{   //w magazynie w, w regale o numerze r, na półce o numerze s, miejscu o numerze p nadaje etykietę dd.
    int w, r, s, p, dd;
    cin >> w >> r >> s >> p >> dd;
}

void SET_LH()
{   // w magazynie w, w podręcznej półce, miejscu o numerze p nadaje etykietę wynoszącą dd.
    int w, p, dd;
    cin >> w >> p >> dd;

}

void SET_LR()
{   // W podręcznym regale składu, na półce o numerze s, miejscu o numerze p nadaje etykietę dd
    int s, p, dd;
    cin >> s >> p >> dd;

}

void SET_LS()
{   // W podręcznej półce składu, miejscu o numerze p nadaje etykietę dd
    int p, dd;
    cin >> p >> dd;

}

void GET_LW()
{    // Wyświetl etykietę miejsca o numerze p w magazynie o numerze w, w regale o numerze r, na półce o numerze s
    int w, r, s, p;
    cin >> w >> r >> s >> p;

}

void GET_LH()
{
    // Wyświetl etykietę miejsca o numerze p w magazynie o numerze w, w podręcznej półce
    int w, p;
    cin >> w >> p;
}

void GET_LR()
{
    // Wyświetl etykietę miejsca o numerze p w podręcznym regale składu, na półce o numerze s
    int s, p;
    cin >> s >> p;
}

void GET_LS()
{
    // Wyświetl etykietę miejsce w podręcznej półce składu, o numerze p
    int p;
    cin >> p;
}