#pragma once
#include <string>
#include <vector>
using namespace std;




class Place
{
private:
    int amount_;
    int label_;

public:
    Place(int amount, int label=0);
    
    string getLabel () const;
    int    getAmount() const;
    void   setLabel (const int NewLabel);
    void   setAmount(const int NewAmount);

    operator int() const;
};





class Shelf
{
private:
    vector<Place> places_;

public:
    Shelf(int placeCount, int amount, int label=0);

    vector<Place> getPlaces() const ;
    size_t getPlacesAmount() const;

    bool validIndex(const int &indeks);
};





class Rack
{
private:
    vector<Shelf> shelfs_;

public:
    Rack(int ShelfCount, int placeCount, int amount, int label=0);

    vector<Shelf> getShelfs() const ;

    bool validIndex(const int &indeks);
};





class Warehouse
{
private:
    vector<Rack> racks_;
    Shelf handyShelf_;

public:
    Warehouse(int RackCount, int ShelfCount, int placeCount, int amount, int label=0);

    vector<Rack> getRacks() const ;
    Shelf getHandyShelf_() const;

    bool validIndex(const int &indeks);
};





class Depot
{
private:
    vector<Warehouse> warehouses_;
    Rack handyRack_;
    Shelf handyShelf_;

public:
    Depot(int warehouseCount=0, int RackCount=0, int ShelfCount=0, int placeCount=0, int amount=0, int label = 0);

    vector<Warehouse> getWarehouses() const ;
    Rack  getHandyRack_() const ;
    Shelf getHandyShelf_() const;

    bool validIndex(const int &indeks);


    // Operacje ustawiania parametrów
    void FILL(int w, int r, int s, int p, int a);
    void SET_AP(int wb, int rb, int sb, int Pe);
    void SET_AS(int wb, int rb, int Se, int Pe);
    void SET_AR(int wb, int Re, int Se, int Pe);
    void SET_AW(int We, int Re, int Se, int Pe);
    void SET_HW(int w, int P);
    void SET_HR(int S, int P);
    void SET_HS(int P);

    // Operacje dodawania towarów
    void PUT_W(int w, int r, int s, int p, int A);
    void PUT_H(int w, int p, int A);
    void PUT_R(int s, int p, int A);
    void PUT_S(int p, int A);

    // Operacje odejmowania towarów
    void POP_W(int w, int r, int s, int p, int A);
    void POP_H(int w, int p, int A);
    void POP_R(int s, int p, int A);
    void POP_S(int p, int A);

    // Operacje przenoszenia towarów
    void MOV_W(int wb, int rb, int sb, int we, int re, int se, int p, int A);
    void MOV_H(int w, int r, int s, int p, int A);
    void MOV_R(int w, int r, int sb, int se, int p, int A);
    void MOV_S(int s, int p, int A);

    // Operacje wyświetlania informacji
    void GET_E();
    void GET_W(int w);
    void GET_RW(int w, int r);
    void GET_RH();
    void GET_SW(int w, int r, int s);
    void GET_SH(int w);
    void GET_SR(int s);
    void GET_S();

    // Operacje etykietowe
    void SET_LW(int w, int r, int s, int p, int dd);
    void SET_LH(int w, int p, int dd);
    void SET_LR(int s, int p, int dd);
    void SET_LS(int p, int dd);
    void GET_LW(int w, int r, int s, int p);
    void GET_LH(int w, int p);
    void GET_LR(int s, int p);
    void GET_LS(int p);
};