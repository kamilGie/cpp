#include "igrzyska.hpp"

unsigned int PLAYER_CLASS::getRemainingHealth() {
    return static_cast<unsigned int>(float(health) / float(maxHealth) * 100.0f);
}

unsigned int PLAYER_CLASS::getDamage() {
    return damage;
}

unsigned int PLAYER_CLASS::getAgility() {
    return agility;
}

void PLAYER_CLASS::takeDamage(unsigned int damageTaken) {
    health-=damageTaken;
}

void PLAYER_CLASS::applyWinnerReward() {
    //wygral cos mam robic xddd
}

void PLAYER_CLASS::cure() {
    health=maxHealth;
}

void PLAYER_CLASS::printParams() {
    std::cout<<maxHealth<<" "<<health<<" "<<damage<<" "<<agility<<"\n";
}

void PLAYER_CLASS::die() {
    health=0;
}
