#include "Depot.hpp"
#include <iostream>

// get

int Place::getAmount() const { return amount_; }
string Place::getLabel() const { return (label_ == 0 ? "--" : to_string(label_)); }

vector<Place> &Shelf::getPlaces() { return places_; }

vector<Shelf> &Rack::getShelfs() { return shelfs_; }

vector<Rack> &Warehouse::getRacks() { return racks_; }
Shelf &Warehouse::getHandyShelf() { return handyShelf_; }

vector<Warehouse> &Depot::getWarehouses() { return warehouses_; }
Rack &Depot::getHandyRack() { return handyRack_; }
Shelf &Depot::getHandyShelf() { return handyShelf_; }

size_t Shelf::getPlacesAmount()
{
    size_t res = 0;
    for (auto &place : places_)
    {
        res += place;
    }
    return res;
}

size_t Rack::getPlacesAmount()
{
    size_t res = 0;
    for (auto &shelf : shelfs_)
    {
        res += shelf.getPlacesAmount();
    }
    return res;
}

size_t Warehouse::getPlacesAmount()
{
    size_t res = 0;
    for (auto &rack : racks_)
    {
        res += rack.getPlacesAmount();
    }
    res += getHandyShelf().getPlacesAmount();
    return res;
}

size_t Depot::getPlacesAmount()
{
    size_t res = 0;
    for (auto &warehouse : warehouses_)
    {
        res += warehouse.getPlacesAmount();
    }
    res += getHandyRack().getPlacesAmount();
    res += getHandyShelf().getPlacesAmount();
    return res;
}



// set

void Place::setLabel(const int NewLabel) { label_ = NewLabel; }

void Place::setAmount(const int NewAmount) { amount_ = NewAmount; }



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



// validCheck

bool Shelf::validIndex(const int &indeks) { return indeks >= 0 && indeks < places_.size(); }

bool Rack::validIndex(const int &indeks) { return indeks >= 0 && indeks < shelfs_.size(); }

bool Warehouse::validIndex(const int &indeks) { return indeks >= 0 && indeks < racks_.size(); }

bool Depot::validIndex(const int &indeks) { return indeks >= 0 && indeks < warehouses_.size(); }

bool validLabel(int Label) { return ((Label == 0) || (Label > 9 && Label < 100)); }

bool validSet(int set) { return (set>0&&set<129);}

bool validAmount(int amount) { return ( amount>=0 && amount<65536); }



// other

void error() { cout << "error" << endl; }

Place::operator int() const { return amount_; }



//SET methods

void Depot::FILL(int W, int R, int S, int P, int A)
{
    if(!(validSet(W) && validSet(R) && validSet(S) && validSet(P) && validAmount(A)))
    {
        error();
        return;
    }
    warehouses_ = vector<Warehouse>(W, Warehouse(R, S, P, A));
    handyRack_ = Rack(S, P, A);
    handyShelf_ = Shelf(P, A);
}


void Depot::SET_AP(int wb, int rb, int sb, int Pe)
{
    if (!(validIndex(wb) && getWarehouses()[wb].validIndex(rb) && getWarehouses()[wb].getRacks()[rb].validIndex(sb) && validAmount(Pe)))
    {
        error();
        return;
    }

    getWarehouses()[wb].getRacks()[rb].getShelfs()[sb].getPlaces().resize(Pe, Place(0));
}

void Depot::SET_AS(int wb, int rb, int Se, int Pe)
{
    if (!(validIndex(wb) && getWarehouses()[wb].validIndex(rb) && validAmount(Pe)))
    {
        error();
        return;
    }

    for (int i=0; i < getWarehouses()[wb].getRacks()[rb].getShelfs().size() && i<Se ; i++)
    {
        SET_AP(wb,rb,i,Pe);
    }

    getWarehouses()[wb].getRacks()[rb].getShelfs().resize(Se, Shelf(Pe,0));
}

void Depot::SET_AR(int wb, int Re, int Se, int Pe)
{
    if (!(validIndex(wb) && validAmount(Pe)))
    {
        error();
        return;
    }

    for (int i=0; i < getWarehouses()[wb].getRacks().size() && i<Re ; i++)
    {
        SET_AS(wb,i,Se,Pe);
    }

    getWarehouses()[wb].getRacks().resize(Re, Rack(Se,Pe,0));
}


void Depot::SET_AW(int We, int Re, int Se, int Pe)
{
    if (!validAmount(Pe))
    {
        error();
        return;
    }

    for (int i=0; i < getWarehouses().size() && i<We ; i++)
    {
        SET_AS(i,Re,Se,Pe);
    }

    getWarehouses().resize(We, Warehouse(Re,Se,Pe,0));
}

void Depot::SET_HW(int w, int P)
{
    if (!(validIndex(w) && validAmount(P)))
    {
        error();
        return;
    }

    getWarehouses()[w].getHandyShelf().getPlaces().resize(P, Place(0));
}


void Depot::SET_HR(int S, int P)
{
    if (!validAmount(P))
    {
        error();
        return;
    }

    for (int i=0; i <  getHandyRack().getShelfs().size() && i<S ; i++)
    {
        getHandyRack().getShelfs()[i].getPlaces().resize(S, Place(0));
    }

    getHandyRack().getShelfs().resize(S, Shelf(P,0));
}


void Depot::SET_HS(int P)
{
    if (!validAmount(P))
    {
        error();
        return;
    }

     getHandyShelf().getPlaces().resize(P,Place(0));
}


// PUT METHODS

void Depot::PUT_W(int w, int r, int s, int p, int A)
{
    if (!(validIndex(w) && getWarehouses()[w].validIndex(r) && getWarehouses()[w].getRacks()[r].validIndex(s) && getWarehouses()[w].getRacks()[r].getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }
    size_t amount = getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlaces()[p].getAmount();

    amount = amount+A>65535 ? 65535 : A+amount;
    getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlaces()[p].setAmount(amount);
}


void Depot::PUT_H(int w, int p, int A)
{
    if (!(validIndex(w) && getWarehouses()[w].getHandyShelf().validIndex(p) ))
    {
        error();
        return;
    }
    size_t amount = getWarehouses()[w].getHandyShelf().getPlaces()[p].getAmount();

    amount = amount+A>65535 ? 65535 : A+amount;
    getWarehouses()[w].getHandyShelf().getPlaces()[p].setAmount(amount);
}


void Depot::PUT_R(int s, int p, int A)
{
    if (!( getHandyRack().validIndex(s)&& getHandyRack().getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }
    size_t amount = getHandyRack().getShelfs()[s].getPlaces()[p].getAmount();

    amount = amount+A>65535 ? 65535 : A+amount;
    getHandyRack().getShelfs()[s].getPlaces()[p].setAmount(amount);
}


void Depot::PUT_S(int p, int A)
{
    if (!getHandyShelf().validIndex(p))
    {
        error();
        return;
    }
    size_t amount = getHandyShelf().getPlaces()[p].getAmount();

    amount = amount+A>65535 ? 65535 : A+amount;
    getHandyShelf().getPlaces()[p].setAmount(amount);
}


// POP methods

void Depot::POP_W(int w, int r, int s, int p, int A)
{
    if (!(validIndex(w) && getWarehouses()[w].validIndex(r) && getWarehouses()[w].getRacks()[r].validIndex(s) && getWarehouses()[w].getRacks()[r].getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }
    long amount = getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlaces()[p].getAmount();

    amount = amount-A<0 ? 0 : amount-A;
    getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlaces()[p].setAmount(amount);
}

void Depot::POP_H(int w, int p, int A)
{
    if (!(validIndex(w) && getWarehouses()[w].getHandyShelf().validIndex(p) ))
    {
        error();
        return;
    }
    long amount = getWarehouses()[w].getHandyShelf().getPlaces()[p].getAmount();

    amount = amount-A<0 ? 0 : amount-A;
    getWarehouses()[w].getHandyShelf().getPlaces()[p].setAmount(amount);
}

void Depot::POP_R(int s, int p, int A)
{
    if (!( getHandyRack().validIndex(s)&& getHandyRack().getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }
    long amount = getHandyRack().getShelfs()[s].getPlaces()[p].getAmount();

    amount = amount-A<0 ? 0 : amount-A;
    getHandyRack().getShelfs()[s].getPlaces()[p].setAmount(amount);
}

void Depot::POP_S(int p, int A)
{
    if (!getHandyShelf().validIndex(p))
    {
        error();
        return;
    }
    long amount = getHandyShelf().getPlaces()[p].getAmount();

    amount = amount-A<0 ? 0 : amount-A;
    getHandyShelf().getPlaces()[p].setAmount(amount);
}


// MOV methods

void Depot::MOV_W(int wb, int rb, int sb, int we, int re, int se, int p, int A)
{
    if (!(validIndex(wb) && getWarehouses()[wb].validIndex(rb) && getWarehouses()[wb].getRacks()[rb].validIndex(sb) && getWarehouses()[wb].getRacks()[rb].getShelfs()[sb].validIndex(p))
    || (!(validIndex(we) && getWarehouses()[we].validIndex(re) && getWarehouses()[we].getRacks()[re].validIndex(se) && getWarehouses()[we].getRacks()[re].getShelfs()[se].validIndex(p))))
    {
        error();
        return;
    }

    long amount = getWarehouses()[wb].getRacks()[rb].getShelfs()[sb].getPlaces()[p].getAmount();
    A = amount<A ? amount : A;
    amount = getWarehouses()[we].getRacks()[re].getShelfs()[se].getPlaces()[p].getAmount();
    A = amount+A>65535 ? 65535-amount : A;

    POP_W(wb,rb,sb,p,A);
    PUT_W(we,re,se,p,A);
}

void Depot::MOV_H(int w, int r, int s, int p, int A)
{
    if (!(validIndex(w) && getWarehouses()[w].validIndex(r) && getWarehouses()[w].getRacks()[r].validIndex(s)
    && getWarehouses()[w].getRacks()[r].getShelfs()[s].validIndex(p) && getWarehouses()[w].getHandyShelf().validIndex(p)))
    {
        error();
        return;
    }

    long amount = getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlaces()[p].getAmount();
    A = amount<A ? amount : A;
    amount = getWarehouses()[w].getHandyShelf().getPlaces()[p].getAmount();
    A = amount+A>65535 ? 65535-amount : A;

    POP_W(w,r,s,p,A);
    PUT_H(w,p,A);
}

void Depot::MOV_R(int w, int r, int sb, int se, int p, int A)
{
    if (!(validIndex(w) && getWarehouses()[w].validIndex(r) && getWarehouses()[w].getRacks()[r].validIndex(sb) && getHandyRack().validIndex(se) && getHandyRack().getShelfs()[se].validIndex(p)))
    {
        error();
        return;
    }

    long amount = getWarehouses()[w].getRacks()[r].getShelfs()[sb].getPlaces()[p].getAmount();
    A = amount<A ? amount : A;
    amount = getHandyRack().getShelfs()[se].getPlaces()[p].getAmount();
    A = amount+A>65535 ? 65535-amount : A;

    POP_W(w,r,sb,p,A);
    PUT_R(se,p,A);
}

void Depot::MOV_S(int s, int p, int A)
{
    if (!(getHandyRack().validIndex(s) && getHandyShelf().validIndex(p)))
    {
        error();
        return;
    }

    long amount = getHandyRack().getShelfs()[s].getPlaces()[p].getAmount();
    A = amount<A ? amount : A;
    amount = getHandyShelf().getPlaces()[p].getAmount();
    A = amount+A>65535 ? 65535-amount : A;

    POP_R(s,p,A);
    PUT_S(p,A);
}

//  GET Methods

void Depot::GET_E() { cout << getPlacesAmount() << endl; }

void Depot::GET_RH() { cout << getHandyRack().getPlacesAmount() << endl; }

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

    cout << getWarehouses()[w].getHandyShelf().getPlacesAmount() << endl;
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


// Label Methods 

void Depot::SET_LW(int w, int r, int s, int p, int dd)
{
    if (!(validLabel(dd) && validIndex(w) && getWarehouses()[w].validIndex(r) && getWarehouses()[w].getRacks()[r].validIndex(s) && getWarehouses()[w].getRacks()[r].getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }

    getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlaces()[p].setLabel(dd);
}

void Depot::SET_LH(int w, int p, int dd)
{
    if (!(validLabel(dd) && validIndex(w) && getWarehouses()[w].getHandyShelf().validIndex(p)))
    {
        error();
        return;
    }

    getWarehouses()[w].getHandyShelf().getPlaces()[p].setLabel(dd);
}

void Depot::SET_LR(int s, int p, int dd)
{
    if (!(validLabel(dd) && getHandyRack().validIndex(s) && getHandyRack().getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }

    getHandyRack().getShelfs()[s].getPlaces()[p].setLabel(dd);
}

void Depot::SET_LS(int p, int dd)
{
    if (!(validLabel(dd) && getHandyShelf().validIndex(p)))
    {
        error();
        return;
    }

    getHandyShelf().getPlaces()[p].setLabel(dd);
}

void Depot::GET_LW(int w, int r, int s, int p)
{
    if (!(validIndex(w) && getWarehouses()[w].validIndex(r) && getWarehouses()[w].getRacks()[r].validIndex(s) && getWarehouses()[w].getRacks()[r].getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }

    cout << getWarehouses()[w].getRacks()[r].getShelfs()[s].getPlaces()[p].getLabel() << endl;
}

void Depot::GET_LH(int w, int p)
{
    if (!(validIndex(w) && getWarehouses()[w].getHandyShelf().validIndex(p)))
    {
        error();
        return;
    }

    cout << getWarehouses()[w].getHandyShelf().getPlaces()[p].getLabel() << endl;
}

void Depot::GET_LR(int s, int p)
{
    if (!(getHandyRack().validIndex(s) && getHandyRack().getShelfs()[s].validIndex(p)))
    {
        error();
        return;
    }

    cout << getHandyRack().getShelfs()[s].getPlaces()[p].getLabel() << endl;
}

void Depot::GET_LS(int p)
{
    if (!getHandyShelf().validIndex(p))
    {
        error();
        return;
    }

    cout << getHandyShelf().getPlaces()[p].getLabel() << endl;
}