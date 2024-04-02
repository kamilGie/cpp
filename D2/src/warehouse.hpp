#pragma once 
#include <string>
class Warehouse {

private:

public:
    void FILL(int w, int r, int s, int p, int a);
    // Operacje ustawiania parametrów
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