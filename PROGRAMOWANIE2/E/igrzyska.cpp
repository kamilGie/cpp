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
    health -= damageTaken;
    if (health <= 0) die();
}

void PLAYER_CLASS::applyWinnerReward() {
    damage+=2;
    agility+=2;
    cure();
}

void PLAYER_CLASS::cure() {
    health = maxHealth;
}

void PLAYER_CLASS::printParams() {
    std::cout << maxHealth << " " << health << " " << damage << " " << agility << "\n";
}

void PLAYER_CLASS::die() {
    health = 0;
}

void CAESAR_CLASS::judgeDeathOrLife(PLAYER_CLASS* player) {
    // todo
}

void ARENA_CLASS::fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2) {
    if (!p1->health || !p2->health) { return; }
    if (p2->getAgility() > p1->getAgility()) {
        fight(p2, p1);
        return;
    }

    p1->printParams();
    p2->printParams();

    int atacks = 0;
    do {
        p2->takeDamage(p1->getDamage());
        p2->printParams();
        atacks++;
        if (p2->health == 0) { break; }

        p1->takeDamage(p2->getDamage());
        p1->printParams();
        atacks++;
        if (p1->health == 0) { break; }
    } while (p1->health >= 10 || p2->health >= 10 || atacks != 40);

    caesar.judgeDeathOrLife(p1);
    p1->printParams();
    if(p1->health) {p1->applyWinnerReward();}
    p1->printParams();

    caesar.judgeDeathOrLife(p2);
    p2->printParams();
    if(p2->health) {p2->applyWinnerReward();}
    p2->printParams();

}
