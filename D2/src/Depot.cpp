#include "Depot.hpp"
#include <iostream>

// Operators

Place::operator int() const { return amount_; }



// set

void Place::setLabel(const int NewLabel) { label_ = NewLabel; }
void Place::setAmount(const int NewAmount) { amount_ = NewAmount; }



// get

int Place::getAmount() const { return amount_; }
string Place::getLabel() const { return label_ == 0 ? "--" : to_string(label_); }

vector<Place> Shelf::getPlaces() const { return places_; }

vector<Shelf> Rack::getShelfs() const { return shelfs_; }

vector<Rack> Warehouse::getRacks() const { return racks_; }
Shelf Warehouse::getHandyShelf_() const { return handyShelf_; }

vector<Warehouse> Depot::getWarehouses() const { return warehouses_; }
Rack Depot::getHandyRack_() const { return handyRack_; }
Shelf Depot::getHandyShelf_() const { return handyShelf_; }

size_t Shelf::getPlacesAmount() const
{
    size_t res = 0;
    for (auto &place : places_)
    {
        res += place;
    }
    return res;
}

size_t Rack::getPlacesAmount() const
{
    size_t res = 0;
    for (auto &shelf : shelfs_)
    {
        res += shelf.getPlacesAmount();
    }
    return res;
}

size_t Warehouse::getPlacesAmount() const
{
    size_t res = 0;
    for (auto &rack : racks_)
    {
        res += rack.getPlacesAmount();
    }
    res += getHandyShelf_().getPlacesAmount();
    return res;
}

size_t Depot::getPlacesAmount() const
{
    size_t res = 0;
    for (auto &warehouse : warehouses_)
    {
        res += warehouse.getPlacesAmount();
    }
    res += getHandyRack_().getPlacesAmount();
    res += getHandyShelf_().getPlacesAmount();
    return res;
}



// constructors

Place::Place(int amount, int label)
    : amount_(amount), label_(label) {}

Shelf::Shelf(int placeCount, int amount, int label)
    : places_(placeCount, Place(amount, label)) {}

Rack::Rack(int ShelfCount, int placeCount, int amount, int label)
    : shelfs_(ShelfCount, Shelf(placeCount, amount, label)) {}

Warehouse::Warehouse(int RackCount, int ShelfCount, int placeCount, int amount, int label)
    : racks_(RackCount, Rack(ShelfCount, placeCount, amount, label)), handyShelf_(placeCount, amount, label) {}

Depot::Depot(int warehouseCount, int RackCount, int ShelfCount, int placeCount, int amount, int label)
    : warehouses_(warehouseCount, Warehouse(RackCount, ShelfCount, placeCount, amount, label)), handyRack_(ShelfCount, placeCount, amount, label), handyShelf_(placeCount, amount, label) {}



// validIndex

bool Shelf::validIndex(const int &indeks) { return indeks >= 0 && indeks < places_.size(); }

bool Rack::validIndex(const int &indeks) { return indeks >= 0 && indeks < shelfs_.size(); }

bool Warehouse::validIndex(const int &indeks) { return indeks >= 0 && indeks < racks_.size(); }

bool Depot::validIndex(const int &indeks) { return indeks >= 0 && indeks < warehouses_.size(); }



// other

void error() { cout << "error" << endl; }



// methods

void Depot::FILL(int W, int R, int S, int P, int A)
{
    warehouses_ = vector<Warehouse>(W, Warehouse(R, S, P, A));
    handyRack_ = Rack(S, P, A);
    handyShelf_ = Shelf(P,A);
}

void Depot::SET_AP(int wb, int rb, int sb, int Pe)
{
    // Implementacja
}

void Depot::SET_AS(int wb, int rb, int Se, int Pe)
{
    // Implementacja
}

void Depot::SET_AR(int wb, int Re, int Se, int Pe)
{
    // Implementacja
}

void Depot::SET_AW(int We, int Re, int Se, int Pe)
{
    // Implementacja
}

void Depot::SET_HW(int w, int P)
{
    // Implementacja
}

void Depot::SET_HR(int S, int P)
{
    // Implementacja
}

void Depot::SET_HS(int P)
{
    // Implementacja
}



// Operacje dodawania towarów

void Depot::PUT_W(int w, int r, int s, int p, int A)
{
    // Implementacja
}

void Depot::PUT_H(int w, int p, int A)
{
    // Implementacja
}

void Depot::PUT_R(int s, int p, int A)
{
    // Implementacja
}

void Depot::PUT_S(int p, int A)
{
    // Implementacja
}



// Operacje odejmowania towarów

void Depot::POP_W(int w, int r, int s, int p, int A)
{
    // Implementacja
}

void Depot::POP_H(int w, int p, int A)
{
    // Implementacja
}

void Depot::POP_R(int s, int p, int A)
{
    // Implementacja
}

void Depot::POP_S(int p, int A)
{
    // Implementacja
}



// Operacje przenoszenia towarów

void Depot::MOV_W(int wb, int rb, int sb, int we, int re, int se, int p, int A)
{
    // Implementacja
}

void Depot::MOV_H(int w, int r, int s, int p, int A)
{
    // Implementacja
}

void Depot::MOV_R(int w, int r, int sb, int se, int p, int A)
{
    // Implementacja
}

void Depot::MOV_S(int s, int p, int A)
{
    // Implementacja
}



// Operacje wyświetlania informacji

void Depot::GET_E() { cout << getPlacesAmount() << endl; }

void Depot::GET_RH() { cout << getHandyRack_().getPlacesAmount() << endl; }

void Depot::GET_S() { cout << handyShelf_.getPlacesAmount() << endl; }

void Depot::GET_W(int w)
{
    if (!validIndex(w))
    {
        error();
        return;
    }

    cout << getWarehouses()[w].getPlacesAmount() << endl;
}

void Depot::GET_RW(int w, int r)
{
    if (!(validIndex(w) && getWarehouses()[w].validIndex(r)))
    {
        error();
        return;
    }

    cout << getWarehouses()[w].getRacks()[r].getPlacesAmount() << endl;
}

void Depot::GET_SW(int w, int r, int s)
{
    if (!(validIndex(w) && getWarehouses()[w].validIndex(r) && getWarehouses()[w].getRacks()[r].validIndex(s)))
    {
        error();
        return;
    }

    cout << getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlacesAmount() << endl;
}

void Depot::GET_SH(int w)
{
    if (!validIndex(w))
    {
        error();
        return;
    }

    cout << getWarehouses()[w].getHandyShelf_().getPlacesAmount() << endl;
}

void Depot::GET_SR(int s)
{
    if (!handyRack_.validIndex(s))
    {
        error();
        return;
    }

    cout << handyRack_.getShelfs()[s].getPlacesAmount() << endl;
}

// Operacje etykietowe

void Depot::SET_LW(int w, int r, int s, int p, int dd)
{
    // Implementacja
}

void Depot::SET_LH(int w, int p, int dd)
{
    // Implementacja
}

void Depot::SET_LR(int s, int p, int dd)
{
    // Implementacja
}

void Depot::SET_LS(int p, int dd)
{
    // Implementacja
}

void Depot::GET_LW(int w, int r, int s, int p)
{
    // Implementacja
}

void Depot::GET_LH(int w, int p)
{
    // Implementacja
}

void Depot::GET_LR(int s, int p)
{
    // Implementacja
}

void Depot::GET_LS(int p)
{
    // Implementacja
}