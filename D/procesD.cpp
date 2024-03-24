// kamil gieras
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class miejsceNaTowar
{
    unsigned short towar;
    int etykieta_towaru;

public:
    miejsceNaTowar(unsigned short towar, int etykieta_towaru)
    {
        this->towar = towar;
        this->etykieta_towaru = etykieta_towaru;
    }

    // Gettery
    bool getTowar(unsigned short *wartosciTowaru) const
    {
        *wartosciTowaru = towar;
        return true;
    }

    int getEtykietaTowaru(int *wartoscEtykiety) const
    {
        *wartoscEtykiety = etykieta_towaru;
        return true;
    }

    // Settery
    bool setTowar(unsigned short newTowar)
    {
        towar = newTowar;
        return true;
    }

    bool setEtykietaTowaru(int newEtykietaTowaru)
    {
        if (poprawnaEtykieta(newEtykietaTowaru))
        {
            etykieta_towaru = newEtykietaTowaru;
            return true;
        }
        else
            return false;
    }

    bool poprawnaEtykieta(int etykieta) const
    {
        return ((etykieta >= 10 && etykieta < 100) || etykieta == 0);
    }

    friend class polka;
};

class polka
{
    vector<miejsceNaTowar> miejscaNaTowar;

public:
    polka(int liczbaMiejscNaTowar, unsigned short towar, int etykieta_towaru) : miejscaNaTowar(liczbaMiejscNaTowar, miejsceNaTowar(towar, etykieta_towaru)){};

    bool getTowar(int numerMiejsca, unsigned short *wartosciTowaru) const
    {
        if (poprawnyNumerMiejsca(numerMiejsca))
        {
            return miejscaNaTowar[numerMiejsca].getTowar(wartosciTowaru);
        }
        else
            return false;
    }

    int getEtykietaTowaru(int numerMiejsca, int *wartoscEtykiety) const
    {
        if (poprawnyNumerMiejsca(numerMiejsca))
        {
            return miejscaNaTowar[numerMiejsca].getEtykietaTowaru(wartoscEtykiety);
        }
        else
            return false;
    }

    // Settery
    bool setTowar(int numerMiejsca, unsigned short wartosciTowaru)
    {
        if (poprawnyNumerMiejsca(numerMiejsca))
        {
            return miejscaNaTowar[numerMiejsca].setTowar(wartosciTowaru);
        }
        else
            return false;
    }

    bool setEtykietaTowaru(int numerMiejsca, int newEtykietaTowaru)
    {
        if (poprawnyNumerMiejsca(numerMiejsca))
        {
            return miejscaNaTowar[numerMiejsca].setEtykietaTowaru(newEtykietaTowaru);
        }
        else
            return false;
    }

    bool poprawnyNumerMiejsca(int numerMiejsca) const
    {
        return (numerMiejsca >= 0 && numerMiejsca < miejscaNaTowar.size());
    }

    bool GetTowarSumaryczniePolki(int *towarSumarycznie)
    {
        unsigned short towarNaMiejsce;
        for (int i = 0; i < miejscaNaTowar.size(); i++)
        {
            getTowar(i, &towarNaMiejsce);
            *towarSumarycznie += towarNaMiejsce;
        }
        return true;
    }

    friend class regal;
};

class regal
{
public:
    vector<polka> polki;
    regal(int liczbaPolek, int liczbaMiejscNaTowar, unsigned short towar, int etykieta_towaru) : polki(liczbaPolek, polka(liczbaMiejscNaTowar, towar, etykieta_towaru)){};

    bool getTowar(int numerPolki, int numerMiejsca, unsigned short *wartosciTowaru) const
    {
        if (poprawnyNumerMiejsca(numerPolki))
        {
            return polki[numerPolki].getTowar(numerMiejsca, wartosciTowaru);
        }
        else
            return false;
    }

    int getEtykietaTowaru(int numerPolki, int numerMiejsca, int *wartoscEtykiety) const
    {
        if (poprawnyNumerMiejsca(numerPolki))
        {
            return polki[numerPolki].getEtykietaTowaru(numerMiejsca, wartoscEtykiety);
        }
        else
            return false;
    }

    // Settery
    bool setTowar(int numerPolki, int numerMiejsca, unsigned short wartosciTowaru)
    {
        if (poprawnyNumerMiejsca(numerPolki))
        {
            return polki[numerPolki].setTowar(numerMiejsca, wartosciTowaru);
        }
        else
            return false;
    }

    bool setEtykietaTowaru(int numerPolki, int numerMiejsca, int newEtykietaTowaru)
    {
        if (poprawnyNumerMiejsca(numerPolki))
        {
            return polki[numerPolki].setEtykietaTowaru(numerMiejsca, newEtykietaTowaru);
        }
        else
            return false;
    }

    bool poprawnyNumerMiejsca(int numerPolki) const
    {
        return (numerPolki >= 0 && numerPolki < polki.size());
    }

    bool GetTowarSumaryczniePolki(int numerPolki, int *towarSumarycznie)
    {
        *towarSumarycznie = 0;
        if (poprawnyNumerMiejsca(numerPolki))
        {
            polki[numerPolki].GetTowarSumaryczniePolki(towarSumarycznie);
            return true;
        }
        return false;
    }
    friend class magazyn;
};

class magazyn
{
    vector<regal> regaly;
    polka podrecznaPolka;

public:
    magazyn(int liczbaRegalow, int liczbaPolek, int liczbaMiejscNaTowar, unsigned short towar, int etykieta_towaru) : podrecznaPolka(liczbaMiejscNaTowar, towar, etykieta_towaru),
                                                                                                                      regaly(liczbaRegalow, regal(liczbaPolek, liczbaMiejscNaTowar, towar, etykieta_towaru)){};

    bool getTowar(int numerRegalu, int numerPolki, int numerMiejsca, unsigned short *wartosciTowaru) const
    {
        if (poprawnyNumerMiejsca(numerRegalu))
        {
            return regaly[numerRegalu].getTowar(numerPolki, numerMiejsca, wartosciTowaru);
        }
        else
            return false;
    }

    int getEtykietaTowaru(int numerRegalu, int numerPolki, int numerMiejsca, int *wartoscEtykiety) const
    {
        if (poprawnyNumerMiejsca(numerRegalu))
        {
            return regaly[numerRegalu].getEtykietaTowaru(numerPolki, numerMiejsca, wartoscEtykiety);
        }
        else
            return false;
    }

    // Settery
    bool setTowar(int numerRegalu, int numerPolki, int numerMiejsca, unsigned short wartosciTowaru)
    {
        if (poprawnyNumerMiejsca(numerRegalu))
        {
            return regaly[numerRegalu].setTowar(numerPolki, numerMiejsca, wartosciTowaru);
        }
        else
            return false;
    }

    bool setEtykietaTowaru(int numerRegalu, int numerPolki, int numerMiejsca, int newEtykietaTowaru)
    {
        if (poprawnyNumerMiejsca(numerRegalu))
        {
            return regaly[numerRegalu].setEtykietaTowaru(numerPolki, numerMiejsca, newEtykietaTowaru);
        }
        else
            return false;
    }

    bool poprawnyNumerMiejsca(int numerRegalu) const
    {
        return (numerRegalu >= 0 && numerRegalu < regaly.size());
    }

    friend class sklad;
};

class sklad
{
    vector<magazyn> magazyny;
    regal podrecznyRegal;
    polka podrecznaPolka;

public:
    sklad(int ilosciMagazynow, int liczbaRegalow, int liczbaPolek, int liczbaMiejscNaTowar, unsigned short towar, int etykieta_towaru) : magazyny(ilosciMagazynow, magazyn(liczbaRegalow, liczbaPolek, liczbaMiejscNaTowar, towar, etykieta_towaru)),
                                                                                                                                         podrecznaPolka(liczbaMiejscNaTowar, towar, etykieta_towaru),
                                                                                                                                         podrecznyRegal(liczbaPolek, liczbaMiejscNaTowar, towar, etykieta_towaru){};

    map<string, void (sklad::*)()> listaPoleceni = {
        {"FILL", &sklad::FILL},
        {"SET-AP", &sklad::SET_AP},
        {"SET-AS", &sklad::SET_AS},
        {"SET-AR", &sklad::SET_AR},
        {"SET-AW", &sklad::SET_AW},
        {"SET-HW", &sklad::SET_HW},
        {"SET-HR", &sklad::SET_HR},
        {"SET-HS", &sklad::SET_HS},
        {"PUT-W", &sklad::PUT_W},
        {"PUT-H", &sklad::PUT_H},
        {"PUT-R", &sklad::PUT_R},
        {"PUT-S", &sklad::PUT_S},
        {"POP-W", &sklad::POP_W},
        {"POP-H", &sklad::POP_H},
        {"POP-R", &sklad::POP_R},
        {"POP-S", &sklad::POP_S},
        {"MOV-W", &sklad::MOV_W},
        {"MOV-H", &sklad::MOV_H},
        {"MOV-R", &sklad::MOV_R},
        {"MOV-S", &sklad::MOV_S},
        {"GET-E", &sklad::GET_E},
        {"GET-W", &sklad::GET_W},
        {"GET-RW", &sklad::GET_RW},
        {"GET-RH", &sklad::GET_RH},
        {"GET-SW", &sklad::GET_SW},
        {"GET-SH", &sklad::GET_SH},
        {"GET-SR", &sklad::GET_SR},
        {"GET-S", &sklad::GET_S},
        {"SET-LW", &sklad::SET_LW},
        {"SET-LH", &sklad::SET_LH},
        {"SET-LR", &sklad::SET_LR},
        {"SET-LS", &sklad::SET_LS},
        {"GET-LW", &sklad::GET_LW},
        {"GET-LH", &sklad::GET_LH},
        {"GET-LR", &sklad::GET_LR},
        {"GET-LS", &sklad::GET_LS}};

    void modyfikujSklad()
    {
        string polecenie;
        while (true)
        {
            cin >> polecenie;
            if (polecenie == "END")
                return;

            (this->*listaPoleceni[polecenie])();
        }
    }

    bool getTowar(int numerMagazynu, int numerRegalu, int numerPolki, int numerMiejsca, unsigned short *wartosciTowaru) const
    {
        if (poprawnyNumerMiejsca(numerRegalu))
        {
            return magazyny[numerMagazynu].getTowar(numerRegalu, numerPolki, numerMiejsca, wartosciTowaru);
        }
        else
            return false;
    }

    int getEtykietaTowaru(int numerMagazynu, int numerRegalu, int numerPolki, int numerMiejsca, int *wartoscEtykiety) const
    {
        if (poprawnyNumerMiejsca(numerMagazynu))
        {
            return magazyny[numerMagazynu].getEtykietaTowaru(numerRegalu, numerPolki, numerMiejsca, wartoscEtykiety);
        }
        else
            return false;
    }

    // Settery
    bool setTowar(int numerMagazynu, int numerRegalu, int numerPolki, int numerMiejsca, unsigned short wartosciTowaru)
    {
        if (poprawnyNumerMiejsca(numerMagazynu))
        {
            return magazyny[numerMagazynu].setTowar(numerRegalu, numerPolki, numerMiejsca, wartosciTowaru);
        }
        else
            return false;
    }

    bool setEtykietaTowaru(int numerMagazynu, int numerRegalu, int numerPolki, int numerMiejsca, int newEtykietaTowaru)
    {
        if (poprawnyNumerMiejsca(numerMagazynu))
        {
            return magazyny[numerMagazynu].setEtykietaTowaru(numerRegalu, numerPolki, numerMiejsca, newEtykietaTowaru);
        }
        else
            return false;
    }

    bool poprawnyNumerMiejsca(int numerMagazynu) const
    {
        return (numerMagazynu >= 0 && numerMagazynu < magazyny.size());
    }

    void FILL()
    {
        int ilosciMagazynow, ilosciRegalow, ilosciPolek, ilosciMiejscNaTowar;
        unsigned short ilosciTowaru;
        cin >> ilosciMagazynow >> ilosciRegalow >> ilosciPolek >> ilosciMiejscNaTowar >> ilosciTowaru;

        magazyny = vector<magazyn>(ilosciMagazynow, magazyn(ilosciRegalow, ilosciPolek, ilosciMiejscNaTowar, ilosciTowaru, 0));
        podrecznaPolka = polka(ilosciMiejscNaTowar, ilosciTowaru, 0);
        podrecznyRegal = regal(ilosciPolek, ilosciMiejscNaTowar, ilosciTowaru, 0);
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
        if (poprawnyNumerMiejsca(w))
        {
            cout<<"poprawny";
            int towarNaPolke;
            long towarSumarycznie = 0;
            for (int r = 0; r < magazyny[w].regaly.size(); r++)
            {
                for (int i = 0; i < magazyny[w].regaly[r].polki.size(); i++)
                {
                    magazyny[w].regaly[r].GetTowarSumaryczniePolki(i, &towarNaPolke);
                    towarSumarycznie += towarNaPolke;
                }
            }

            wypiszTowar(towarSumarycznie);
        }
        else
            error();
    }

    void GET_RW()
    { //!\todo Wyświetl ilość towaru w magazynie o numerze w, na regale o numerze r
        int w, r;
        cin >> w >> r;
        if (poprawnyNumerMiejsca(w) && magazyny[w].poprawnyNumerMiejsca(r))
        {

            int towarNaPolke;
            long towarSumarycznie = 0;
            for (int i = 0; i < magazyny[w].regaly[r].polki.size(); i++)
            {
                magazyny[w].regaly[r].GetTowarSumaryczniePolki(i, &towarNaPolke);
                towarSumarycznie += towarNaPolke;
            }
            wypiszTowar(towarSumarycznie);
        }
        else
            error();
    }

    void GET_RH()
    { //!\todo Wyświetl ilość towaru w podręcznym regale składu
        int towarNaPolke;
        long towarSumarycznie = 0;
        for (int i = 0; i < podrecznyRegal.polki.size(); i++)
        {
            podrecznyRegal.GetTowarSumaryczniePolki(i, &towarNaPolke);
            towarSumarycznie += towarNaPolke;
        }
        wypiszTowar(towarSumarycznie);
    }

    void GET_SW()
    { //!\todo Wyświetl ilość towaru w magazynie o numerze w, na regale o numerze r, na półce o numerze s
        int w, r, s, towarSumarycznie;
        cin >> w >> r >> s;
        if (poprawnyNumerMiejsca(w) && magazyny[w].poprawnyNumerMiejsca(r) && s<magazyny[w].regaly[r].polki.size())
        {
            magazyny[w].regaly[r].GetTowarSumaryczniePolki(s, &towarSumarycznie);
            wypiszTowar(towarSumarycznie);
        }
        else

            error();
    }

    void GET_SH()
    { //!\todo Wyświetl ilość towaru w magazynie o numerze w na podręcznej półce
        int w, towarSumarycznie;
        cin >> w;

        if (poprawnyNumerMiejsca(w))
        {
            magazyny[w].podrecznaPolka.GetTowarSumaryczniePolki(&towarSumarycznie);
            wypiszTowar(towarSumarycznie);
        }
        else
            error();
    }

    void GET_SR()
    { //!\todo Wyświetl ilość towaru w podręcznym regale na półce o numerze s
        int s, towarSumarycznie;
        cin >> s;
        podrecznyRegal.GetTowarSumaryczniePolki(s, &towarSumarycznie) ? wypiszTowar(towarSumarycznie) : error();
    }

    void GET_S()
    { //!\todo Wyświetl ilość towaru na podręcznej półce składu
        int towarSumaryczny;
        podrecznaPolka.GetTowarSumaryczniePolki(&towarSumaryczny);
        cout << towarSumaryczny << endl;
    }

    void wypiszTowar(long towar)
    {
        cout << towar << endl;
    }

    // Polecenia etykietowe

    void SET_LW()
    { // w magazynie w, w regale o numerze r, na półce o numerze s, miejscu o numerze p nadaje etykietę dd.
        int w, r, s, p, dd;
        cin >> w >> r >> s >> p >> dd;
        if (!setEtykietaTowaru(w, r, s, p, dd))
            error();
    }

    void SET_LH()
    { // w magazynie w, w podręcznej półce, miejscu o numerze p nadaje etykietę wynoszącą dd.
        int w, p, dd;
        cin >> w >> p >> dd;

        if (!poprawnyNumerMiejsca(w) || !magazyny[w].podrecznaPolka.setEtykietaTowaru(p, dd))
            error();
    }

    void SET_LR()
    { // W podręcznym regale składu, na półce o numerze s, miejscu o numerze p nadaje etykietę dd
        int s, p, dd;
        cin >> s >> p >> dd;
        if (!podrecznyRegal.setEtykietaTowaru(s, p, dd))
            error();
    }

    void SET_LS()
    { // W podręcznej półce składu, miejscu o numerze p nadaje etykietę dd
        int p, dd;
        cin >> p >> dd;

        if (!podrecznaPolka.setEtykietaTowaru(p, dd))
            error();
    }

    void GET_LW()
    { // Wyświetl etykietę miejsca o numerze p w magazynie o numerze w, w regale o numerze r, na półce o numerze s
        int w, r, s, p, etykieta;
        cin >> w >> r >> s >> p;
        getEtykietaTowaru(w, r, s, p, &etykieta) ? wyswietlEtykiete(etykieta) : error();
    }

    void GET_LH()
    { //! \todo Wyświetl etykietę miejsca o numerze p w magazynie o numerze w, w podręcznej półce
        int w, p, etykieta;
        cin >> w >> p;
        poprawnyNumerMiejsca(w) && magazyny[w].podrecznaPolka.getEtykietaTowaru(p, &etykieta) ? wyswietlEtykiete(etykieta) : error();
    }

    void GET_LR()
    { // Wyświetl etykietę miejsca o numerze p w podręcznym regale składu, na półce o numerze s
        int s, p, etykieta;
        cin >> s >> p;
        podrecznyRegal.getEtykietaTowaru(s, p, &etykieta) ? wyswietlEtykiete(etykieta) : error();
    }

    void GET_LS()
    { // Wyświetl etykietę miejsce w podręcznej półce składu, o numerze p
        int p, etykieta;
        cin >> p;
        podrecznaPolka.getEtykietaTowaru(p, &etykieta) ? wyswietlEtykiete(etykieta) : error();
    }

    void wyswietlEtykiete(int etykieta)
    {
        cout << (etykieta > 0 ? to_string(etykieta) : "--") << endl;
    }

    void error()
    {
        cout << "error" << endl;
    }
};

int main()
{
    sklad SKLAD(0, 0, 0, 0, 0, 0);
    SKLAD.modyfikujSklad();
}