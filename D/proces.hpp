// kamil gieras
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class miejsceNaTowar 
{
public:
    unsigned short towar;
    int etykieta_towaru;

    miejsceNaTowar(unsigned short towar, int etykieta_towaru)
    {
        this->towar = towar;
        this->etykieta_towaru = etykieta_towaru;
    }
};

class polka
{
public:
    vector<miejsceNaTowar> miejscaNaTowar;

    polka(int liczbaMiejscNaTowar,unsigned short towar, int etykieta_towaru) :
    miejscaNaTowar(liczbaMiejscNaTowar, miejsceNaTowar(towar,etykieta_towaru))
    {};
    
};

class regal
{
public:
    vector<polka> polki;

    regal(int liczbaPolek,int liczbaMiejscNaTowar,unsigned short towar, int etykieta_towaru) :
    polki(liczbaPolek,polka(liczbaMiejscNaTowar,towar,etykieta_towaru))
    {};
};

class magazyn
{
public:
    vector<regal> regaly;
    polka podrecznaPolka;

    magazyn(int liczbaRegalow, int liczbaPolek, int liczbaMiejscNaTowar, unsigned short towar, int etykieta_towaru) :
        podrecznaPolka(liczbaMiejscNaTowar, towar, etykieta_towaru),
        regaly(liczbaRegalow, regal(liczbaPolek, liczbaMiejscNaTowar, towar, etykieta_towaru))     
    {};
};

class sklad
{
public:
    vector<magazyn> magazyny;
    regal podrecznyRegal;
    polka podrecznaPolka;

    sklad(int ilosciMagazynow, int liczbaRegalow, int liczbaPolek, int liczbaMiejscNaTowar, unsigned short towar, int etykieta_towaru) :
    magazyny(ilosciMagazynow, magazyn(liczbaRegalow, liczbaPolek, liczbaMiejscNaTowar, towar, etykieta_towaru)),
    podrecznaPolka(liczbaMiejscNaTowar, towar, etykieta_towaru),
    podrecznyRegal(liczbaPolek, liczbaMiejscNaTowar, towar, etykieta_towaru)
    {};
};

void FILL();
void SET_AP();
void SET_AS();
void SET_AR();
void SET_AW();
void SET_HW();
void SET_HR();
void SET_HS();
void PUT_W();
void PUT_H();
void PUT_R();
void PUT_S();
void POP_W();
void POP_H();
void POP_R();
void POP_S();
void MOV_W();
void MOV_H();
void MOV_R();
void MOV_S();
void GET_E();
void GET_W();
void GET_RW();
void GET_RH();
void GET_SW();
void GET_SH();
void GET_SR();
void GET_S();
void SET_LW();
void SET_LH();
void SET_LR();
void SET_LS();
void GET_LW();
void GET_LH();
void GET_LR();
void GET_LS();

map<string,function<void()>> listaPoleceni = {
    {"FILL", FILL},
    {"SET-AP", SET_AP},
    {"SET-AS", SET_AS},
    {"SET-AR", SET_AR},
    {"SET-AW", SET_AW},
    {"SET-HW", SET_HW},
    {"SET-HR", SET_HR},
    {"SET-HS", SET_HS},
    {"PUT-W", PUT_W},
    {"PUT-H", PUT_H},
    {"PUT-R", PUT_R},
    {"PUT-S", PUT_S},
    {"POP-W", POP_W},
    {"POP-H", POP_H},
    {"POP-R", POP_R},
    {"POP-S", POP_S},
    {"MOV-W", MOV_W},
    {"MOV-H", MOV_H},
    {"MOV-R", MOV_R},
    {"MOV-S", MOV_S},
    {"GET-E", GET_E},
    {"GET-W", GET_W},
    {"GET-RW", GET_RW},
    {"GET-RH", GET_RH},
    {"GET-SW", GET_SW},
    {"GET-SH", GET_SH},
    {"GET-SR", GET_SR},
    {"GET-S", GET_S},
    {"SET-LW", SET_LW},
    {"SET-LH", SET_LH},
    {"SET-LR", SET_LR},
    {"SET-LS", SET_LS},
    {"GET-LW", GET_LW},
    {"GET-LH", GET_LH},
    {"GET-LR", GET_LR},
    {"GET-LS", GET_LS}
};
