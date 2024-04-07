//kamil gieras
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
using FunctionMap = map<string,function<void()>>;



//###############################################################################################################################//
//                                              ####    ### CLASS DECLARATIONS###  ####                                          //
//###############################################################################################################################//


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

    vector<Place>&getPlaces() ;
    size_t  getPlacesAmount() ;

    bool validIndex(const int &indeks);
};


class Rack
{
private:
    vector<Shelf> shelfs_;

public:
    Rack(int ShelfCount, int placeCount, int amount, int label=0);

    vector<Shelf>& getShelfs() ;
    size_t   getPlacesAmount() ;

    bool validIndex(const int &indeks);
};


class Warehouse
{
private:
    vector<Rack> racks_;
    Shelf handyShelf_;

public:
    Warehouse(int RackCount, int ShelfCount, int placeCount, int amount, int label=0);

    vector<Rack> & getRacks() ;
    Shelf&  getHandyShelf();
    size_t getPlacesAmount() ;

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

    vector<Warehouse>&  getWarehouses() ;
    Rack&  getHandyRack() ;
    Shelf&  getHandyShelf();
    size_t getPlacesAmount();

    bool validIndex(const int &indeks);


    //SET methods
    void FILL(int w, int r, int s, int p, int a);
    void SET_AP(int wb, int rb, int sb, int Pe);
    void SET_AS(int wb, int rb, int Se, int Pe);
    void SET_AR(int wb, int Re, int Se, int Pe);
    void SET_AW(int We, int Re, int Se, int Pe);
    void SET_HW(int w, int P);
    void SET_HR(int S, int P);
    void SET_HS(int P);

    // PUT METHODS
    void PUT_W(int w, int r, int s, int p, int A);
    void PUT_H(int w, int p, int A);
    void PUT_R(int s, int p, int A);
    void PUT_S(int p, int A);

    // POP methods
    void POP_W(int w, int r, int s, int p, int A);
    void POP_H(int w, int p, int A);
    void POP_R(int s, int p, int A);
    void POP_S(int p, int A);

    // MOV methods
    void MOV_W(int wb, int rb, int sb, int we, int re, int se, int p, int A);
    void MOV_H(int w, int r, int s, int p, int A);
    void MOV_R(int w, int r, int sb, int se, int p, int A);
    void MOV_S(int s, int p, int A);

    //  GET Methods
    void GET_E();
    void GET_W(int w);
    void GET_RW(int w, int r);
    void GET_RH();
    void GET_SW(int w, int r, int s);
    void GET_SH(int w);
    void GET_SR(int s);
    void GET_S();

    // Label Methods 
    void SET_LW(int w, int r, int s, int p, int dd);
    void SET_LH(int w, int p, int dd);
    void SET_LR(int s, int p, int dd);
    void SET_LS(int p, int dd);
    void GET_LW(int w, int r, int s, int p);
    void GET_LH(int w, int p);
    void GET_LR(int s, int p);
    void GET_LS(int p);
};









//###############################################################################################################################//
//                                           ####    ### CLASS DEFINITIONS###  ####                                              //
//###############################################################################################################################//


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







//###############################################################################################################################//
//                                                    ####    ### SOURCE ###  ####                                               //
//###############################################################################################################################//



FunctionMap INIT_MethodExecutorMap(Depot &D){

    FunctionMap res;

    //name                    arguemts                     cin                                  execute method
    res["FILL"]   = [&D]() { int W, R, S, P, A;            cin>>W>>R>>S>>P>>A;                  D.FILL(W,R,S,P,A);};
    res["SET-AP"] = [&D]() { int wb, rb, sb, Pe;           cin>>wb>>rb>>sb>>Pe;                 D.SET_AP(wb,rb,sb,Pe);};
    res["SET-AR"] = [&D]() { int wb, Re, Se, Pe;           cin>>wb>>Re>>Se>>Pe;                 D.SET_AR(wb,Re,Se,Pe);};
    res["SET-AW"] = [&D]() { int We, Re, Se, Pe;           cin>>We>>Re>>Se>>Pe;                 D.SET_AW(We,Re,Se,Pe);};
    res["SET-HW"] = [&D]() { int w, P;                     cin>>w>>P;                           D.SET_HW(w,P);};
    res["SET-HR"] = [&D]() { int S, P;                     cin>>S>>P;                           D.SET_HR(S,P);};
    res["SET-HS"] = [&D]() { int P;                        cin>>P;                              D.SET_HS(P);};
    res["PUT-W"]  = [&D]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  D.PUT_W(w,r,s,p,A);};
    res["PUT-H"]  = [&D]() { int w, p, A;                  cin>>w>>p>>A;                        D.PUT_H(w, p, A);};
    res["PUT-R"]  = [&D]() { int s, p, A;                  cin>>s>>p>>A;                        D.PUT_R(s, p, A);};
    res["PUT-S"]  = [&D]() { int p, A;                     cin>>p>>A;                           D.PUT_S(p, A);};
    res["POP-W"]  = [&D]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  D.POP_W(w, r, s, p, A);};
    res["POP-H"]  = [&D]() { int w, p, A;                  cin>>w>>p>>A;                        D.POP_H(w, p, A);};
    res["POP-R"]  = [&D]() { int s, p, A;                  cin>>s>>p>>A;                        D.POP_R(s, p, A);};
    res["POP-S"]  = [&D]() { int p, A;                     cin>>p>>A;                           D.POP_S(p,A);};
    res["MOV-W"]  = [&D]() { int wb,rb,sb,we,re,se,p,A;    cin>>wb>>rb>>sb>>we>>re>>se>>p>>A;   D.MOV_W(wb,rb,sb,we,re,se,p,A);};
    res["MOV-H"]  = [&D]() { int w, r, s, p, A;            cin>>w>>r>>s>>p>>A;                  D.MOV_H(w, r, s, p, A);};
    res["MOV-R"]  = [&D]() { int w, r, sb, se, p, A;       cin>>w>>r>>sb>>se>>p>>A;             D.MOV_R(w, r, sb, se, p, A);};
    res["MOV-S"]  = [&D]() { int s, p, A;                  cin>>s>>p>>A;                        D.MOV_S(s, p, A); };
    res["GET-E"]  = [&D]() {                                                                    D.GET_E();};
    res["GET-W"]  = [&D]() { int w;                        cin>>w;                              D.GET_W(w);};
    res["GET-RW"] = [&D]() { int w, r;                     cin>>w>>r;                           D.GET_RW(w, r);};
    res["GET-RH"] = [&D]() {                                                                    D.GET_RH();};
    res["GET-SW"] = [&D]() { int w, r, s;                  cin>>w>>r>>s;                        D.GET_SW(w, r, s);};
    res["GET-SH"] = [&D]() { int w;                        cin>>w;                              D.GET_SH(w);};
    res["GET-SR"] = [&D]() { int s;                        cin>>s;                              D.GET_SR(s);};
    res["GET-S"]  = [&D]() {                                                                    D.GET_S();};
    res["SET-LW"] = [&D]() { int w, r, s, p, dd;           cin>>w>>r>>s>>p>>dd;                 D.SET_LW(w, r, s, p, dd);};
    res["SET-LH"] = [&D]() { int w, p, dd;                 cin>>w>>p>>dd;                       D.SET_LH(w, p, dd);};
    res["SET-LR"] = [&D]() { int s, p, dd;                 cin>>s>>p>>dd;                       D.SET_LR(s, p, dd);};
    res["SET-LS"] = [&D]() { int p, dd;                    cin>>p>>dd;                          D.SET_LS(p, dd);};
    res["GET-LW"] = [&D]() { int w, r, s, p;               cin>>w>>r>>s>>p;                     D.GET_LW(w, r, s, p);};
    res["GET-LH"] = [&D]() { int w, p;                     cin>>w>>p;                           D.GET_LH(w, p);};
    res["GET-LR"] = [&D]() { int s, p;                     cin>>s>>p;                           D.GET_LR(s, p);};
    res["GET-LS"] = [&D]() { int p;                        cin>>p;                              D.GET_LS(p);};

    return res;
}
    

int main(){
    
    Depot D;
    FunctionMap  methodExecutor=INIT_MethodExecutorMap(D);

    string command;
    do
    {   
        cin>>command;
        if (methodExecutor.find(command) != methodExecutor.end()) { methodExecutor[command](); }

    } while(command!="END");

}