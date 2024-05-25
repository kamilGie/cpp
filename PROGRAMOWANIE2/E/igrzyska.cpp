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
    if( health > damageTaken ){
        health -= damageTaken;
    } else{
        die();
    }
}

void PLAYER_CLASS::applyWinnerReward() {
    damage+=2;
    agility+=2;
    cure();
}

void PLAYER_CLASS::cure() {
    health = maxHealth;
}

void PLAYER_CLASS::die() {
    health = 0;
}

void CAESAR_CLASS::judgeDeathOrLife(PLAYER_CLASS* player) {
    battleCount++;
    if( battleCount%3==0 && isPairAttacksOnLastBattle ) { 
        player->die(); 
        if(player->getType()==3){
            player->deleteSquad(player);
        }
    }
}

void ARENA_CLASS::fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2) {
    if (p1->health==0 || p2->health==0) { return; }
    if (p2->getAgility() > p1->getAgility()) {
        fight(p2, p1);
        return;
    }

    p1->printParams();
    p2->printParams();

    int attacks = 0;
    while (p1->health >= 10 && p2->health >= 10 && attacks != 40){
        p2->takeDamage(p1->getDamage());
        p2->printParams();
        attacks++;
        if (p2->health == 0) { break; }

        p1->takeDamage(p2->getDamage());
        p1->printParams();
        attacks++;
        if (p1->health == 0) { break; }
    } 

    caesar.isPairAttacksOnLastBattle = (attacks % 2 == 0);

    if(p1->health>0){
        caesar.judgeDeathOrLife(p1);
        p1->printParams();
    }
    if(p2->health>0){
        caesar.judgeDeathOrLife(p2);
        p2->printParams();
    }

    if(p1->health) { p1->applyWinnerReward(); }
    if(p2->health) { p2->applyWinnerReward(); }
    p1->printParams();
    p2->printParams();
}

int HUMAN_CLASS::getType() {
    return 1;
}

std::string HUMAN_CLASS::getId() {
    return id;
}

std::string BEAST_CLASS::getId() {
    return id;
}

std::string BERSERKER_CLASS::getId() {
    return ( getType()==1 ) ? HUMAN_CLASS::getId() 
                            : BEAST_CLASS::getId();
}

std::string SQUAD_CLASS::getId() {
    return id;
}

void SQUAD_CLASS::deletePlayer(PLAYER_CLASS* p) {
        if (!head) return;

        // If the node to be deleted is the head node
        if (head->p == p) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse the list to find the node to be deleted
        Node* current = head;
        while (current->next && current->next->p != p) {
            current = current->next;
        }

        // If the p is found, delete the node
        if (current->next && current->next->p == p) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
}

void SQUAD_CLASS::deleteSquad(PLAYER_CLASS* p) {
    // Sprawdzenie, czy lista nie jest pusta
    if (!head) { return; }

    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next; 
        deletePlayer(current->p); 
        current = nextNode;
    }
    head = nullptr;
}

int HUMAN_CLASS::sumOfAgilityAndDefance() {
    return agility+defance;
}

void HUMAN_CLASS::takeDamage(unsigned int damageTaken) {
    if(damageTaken>defance+agility) { PLAYER_CLASS::takeDamage(damageTaken-defance-agility); }
}

void HUMAN_CLASS::printParams() {
    ( health>0 ) ? std::cout<<id<<":"<<maxHealth<<":"<<health<<":"<<getRemainingHealth()<<"%:"<<damage<<":"<<agility<<":"<<defance<<"\n"
                 : std::cout<<id<<":R.I.P.\n";
}

unsigned int BEAST_CLASS::getDamage() {
    return ( getRemainingHealth()<25 ) ? damage*2 
                                       : damage;

}

void BEAST_CLASS::takeDamage(unsigned int damageTaken) {
    if(damageTaken>agility/2) { PLAYER_CLASS::takeDamage(damageTaken-agility/2); }
}

void BEAST_CLASS::printParams() {
    ( health>0 ) ? std::cout<<id<<":"<<maxHealth<<":"<<health<<":"<<getRemainingHealth()<<"%:"<<getDamage()<<":"<<agility<<"\n"
                 : std::cout<<id<<":R.I.P.\n";
}

int BEAST_CLASS::getType() {
    return 2;
}

int BEAST_CLASS::sumOfAgilityAndDefance() {
    return agility;
}

int BERSERKER_CLASS::getType() {
    return  ( getRemainingHealth() < 25  && getRemainingHealth()!=0 ) ? BEAST_CLASS::getType()
                                                                      : HUMAN_CLASS::getType();
}

int BERSERKER_CLASS::sumOfAgilityAndDefance() {
    return agility+defance;
}

unsigned int BERSERKER_CLASS::getDamage() {
    return ( getType()==1 ) ? HUMAN_CLASS::getDamage() 
                            : BEAST_CLASS::getDamage();
}

unsigned int BERSERKER_CLASS::getAgility() {
     return ( getType()==1 ) ? HUMAN_CLASS::getAgility() 
                             : BEAST_CLASS::getAgility();
}

void BERSERKER_CLASS::takeDamage(unsigned int damageTaken) {
    ( getType()==1 ) ? HUMAN_CLASS::takeDamage(damageTaken) 
                     : BEAST_CLASS::takeDamage(damageTaken);
}

void BERSERKER_CLASS::printParams() {
    ( getType()==1 ) ? HUMAN_CLASS::printParams() 
                     : BEAST_CLASS::printParams();
}

void SQUAD_CLASS::addPlayer(PLAYER_CLASS* p) {
    if(p->health==0 || isAlreadyInSquad(p)) { return; }

    Node* newNode = new Node(p);
        if (!head) {
            head = newNode;
        } else if(isBigger(head->p,newNode->p)){
            newNode->next = head;
            head = newNode;
        }else {
            Node* temp = head;

            while(temp->next && isBigger(newNode->p,temp->next->p)) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
}

int SQUAD_CLASS::sumOfAgilityAndDefance() {
    return agility;
}

int SQUAD_CLASS::getTeamSize() {
    size_t teamSize=0;
    Node* current = head;
    while (current) {
        teamSize++;
        current = current->next;
    }
    return teamSize;
}


bool SQUAD_CLASS::isAlreadyInSquad(PLAYER_CLASS* p){
    Node* current = head;
    while (current) {
        if(current->p == p) { return true; }
        current = current->next;
    }
    return false;
}

bool SQUAD_CLASS::isBigger(PLAYER_CLASS* bigger, PLAYER_CLASS* smaler) {
    if(bigger->getId() !=  smaler->getId()) {  return bigger->getId() > smaler->getId(); }
    if(bigger->maxHealth !=  smaler->maxHealth) {  return bigger->maxHealth > smaler->maxHealth; }
    if(bigger->getRemainingHealth() !=  smaler->getRemainingHealth()) {  return bigger->getRemainingHealth() > smaler->getRemainingHealth(); }
    if(bigger->damage !=  smaler->damage) {  return bigger->damage > smaler->damage; }
    if(bigger->agility !=  smaler->agility) {  return bigger->agility > smaler->agility; }
    return true;
}

unsigned int SQUAD_CLASS::getDamage() {
    unsigned int sumDamage=0;
    Node* current = head;
    while (current) {
        sumDamage += current->p->getDamage(); 
        current = current->next;
    }
    return sumDamage;
}

unsigned int SQUAD_CLASS::getAgility() {
    unsigned int minAgility=UINT_MAX;
    Node* current = head;
    while (current) {
        if(current->p->getAgility()<minAgility ){ minAgility = current->p->getAgility(); }
        current = current->next;
    }
    return minAgility;
}

void SQUAD_CLASS::takeDamage(unsigned int damageTaken) {
    damageTaken = damageTaken/getTeamSize();
    Node* current = head;
    while (current) {
       if( current->p->sumOfAgilityAndDefance() < damageTaken){ current->p->takeDamage(damageTaken-current->p->sumOfAgilityAndDefance()); }
       if(current->p->health==0) {
            Node* next= current->next;  
            deletePlayer(current->p); 
            current = next; 
         }else{
            current = current->next;  
         }
    }
}

void SQUAD_CLASS::printParams() {
    if(getTeamSize()==0){ 
        std::cout<<id<<":nemo\n"; 
        return;
    }

    std::cout<<id<<":"<<getTeamSize()<<":"<<getRemainingHealth()<<"%:"<<getDamage()<<":"<<getAgility()<<":\n";
    Node* current = head;
    while (current) {
        current->p->printParams();
        current = current->next;
    }
}

int SQUAD_CLASS::getType() {
    return 3;
}

unsigned int SQUAD_CLASS::getRemainingHealth(){
    unsigned int theBihestHealth=0;
    Node* current = head;
    while (current) {
        if(current->p->getRemainingHealth()>theBihestHealth ){ theBihestHealth = current->p->getRemainingHealth(); }
        current = current->next;
    }
    return theBihestHealth;
}
