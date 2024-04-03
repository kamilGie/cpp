#include "Depot.hpp"

    // set
void   Place::setLabel (const int NewLabel)  { label_=NewLabel;}  
void   Place::setAmount(const int NewAmount) { amount_=NewAmount;}

    // get
int    Place::getAmount() const { return amount_; }
string Place::getLabel()  const { return label_==0?"--":to_string(label_); }

    // constructors 
Place::Place(int amount, int label)
    : amount_(amount), label_(label) {}

Shelf::Shelf(int placeCount,int amount, int label)
    : place_(placeCount, Place(amount,label)) {}

Rack::Rack(int ShelfCount,int placeCount, int amount, int label)
    : shelf_(ShelfCount, Shelf(placeCount,amount,label)) {}

Warehouse::Warehouse(int RackCount,int ShelfCount,int placeCount, int amount, int label)
    : rack_(RackCount, Rack(ShelfCount,placeCount,amount,label)) 
    , handyShelf_(placeCount,amount,label) {}

Depot::Depot(int warehouseCount,int RackCount,int ShelfCount,int placeCount, int amount, int label)
    : warehouse_ (warehouseCount, Warehouse(RackCount,ShelfCount,placeCount,amount,label))
    , handyRack_ (ShelfCount,placeCount,amount,label)
    , handyShelf_(placeCount,amount,label) {}


    // methods 
void Depot::FILL(int W, int R, int S, int P, int A){
    warehouse_ = vector<Warehouse>(W, Warehouse(R,S,P,A));
    handyRack_ = Rack(S,P,A);
    handyShelf_= Shelf(S,P);
}

void Depot::SET_AP(int wb, int rb, int sb, int Pe) {
    // Implementacja
}

void Depot::SET_AS(int wb, int rb, int Se, int Pe) {
    // Implementacja
}

void Depot::SET_AR(int wb, int Re, int Se, int Pe) {
    // Implementacja
}

void Depot::SET_AW(int We, int Re, int Se, int Pe) {
    // Implementacja
}

void Depot::SET_HW(int w, int P) {
    // Implementacja
}

void Depot::SET_HR(int S, int P) {
    // Implementacja
}

void Depot::SET_HS(int P) {
    // Implementacja
}

// Operacje dodawania towarów
void Depot::PUT_W(int w, int r, int s, int p, int A) {
    // Implementacja
}

void Depot::PUT_H(int w, int p, int A) {
    // Implementacja
}

void Depot::PUT_R(int s, int p, int A) {
    // Implementacja
}

void Depot::PUT_S(int p, int A) {
    // Implementacja
}

// Operacje odejmowania towarów
void Depot::POP_W(int w, int r, int s, int p, int A) {
    // Implementacja
}

void Depot::POP_H(int w, int p, int A) {
    // Implementacja
}

void Depot::POP_R(int s, int p, int A) {
    // Implementacja
}

void Depot::POP_S(int p, int A) {
    // Implementacja
}

// Operacje przenoszenia towarów
void Depot::MOV_W(int wb, int rb, int sb, int we, int re, int se, int p, int A) {
    // Implementacja
}

void Depot::MOV_H(int w, int r, int s, int p, int A) {
    // Implementacja
}

void Depot::MOV_R(int w, int r, int sb, int se, int p, int A) {
    // Implementacja
}

void Depot::MOV_S(int s, int p, int A) {
    // Implementacja
}

// Operacje wyświetlania informacji
void Depot::GET_E() {
    // Implementacja
}

void Depot::GET_W(int w) {
    // Implementacja
}

void Depot::GET_RW(int w, int r) {
    // Implementacja
}

void Depot::GET_RH() {
    // Implementacja
}

void Depot::GET_SW(int w, int r, int s) {
    // Implementacja
}

void Depot::GET_SH(int w) {
    // Implementacja
}

void Depot::GET_SR(int s) {
    // Implementacja
}

void Depot::GET_S() {
    // Implementacja
}

// Operacje etykietowe
void Depot::SET_LW(int w, int r, int s, int p, int dd) {
    // Implementacja
}

void Depot::SET_LH(int w, int p, int dd) {
    // Implementacja
}

void Depot::SET_LR(int s, int p, int dd) {
    // Implementacja
}

void Depot::SET_LS(int p, int dd) {
    // Implementacja
}

void Depot::GET_LW(int w, int r, int s, int p) {
    // Implementacja
}

void Depot::GET_LH(int w, int p) {
    // Implementacja
}

void Depot::GET_LR(int s, int p) {
    // Implementacja
}

void Depot::GET_LS(int p) {
    // Implementacja
}