#include "igrzyska.hpp"

void PLAYER_CLASS::takeDamage(unsigned int damageTaken) {
    if (health > damageTaken) {
        health -= damageTaken;
    } else {
        die();
    }
}

void PLAYER_CLASS::applyWinnerReward() {
    damage += 2;
    agility += 2;
    cure();
}

void HUMAN_CLASS::takeDamage(unsigned int damageTaken) {
    if (damageTaken > defance + agility) PLAYER_CLASS::takeDamage(damageTaken - defance - agility);
}

void HUMAN_CLASS::printParams() {
    (health > 0) ? std::cout << id << ":" << maxHealth << ":" << health << ":" << getRemainingHealth() << "%:" << damage << ":" << agility << ":" << defance << "\n"
                 : std::cout << id << ":R.I.P.\n";
}

void BEAST_CLASS::takeDamage(unsigned int damageTaken) {
    if (damageTaken > agility / 2) PLAYER_CLASS::takeDamage(damageTaken - agility / 2);
}

void BEAST_CLASS::printParams() {
    (health > 0) ? std::cout << id << ":" << maxHealth << ":" << health << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << agility << "\n"
                 : std::cout << id << ":R.I.P.\n";
}

void SQUAD_CLASS::deletePlayer(PLAYER_CLASS* p) {
    if (!head) return;

    if (head->p == p) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next && current->next->p != p) {
        current = current->next;
    }

    if (current->next && current->next->p == p) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void SQUAD_CLASS::applyWinnerReward() {
    for (Node* current = head; current; current = current->next) {
        current->p->applyWinnerReward();
    }
}

void SQUAD_CLASS::deleteSquad(PLAYER_CLASS* p) {
    Node* current = head;
    Node* nextNode = nullptr;
    while (current) {
        nextNode = current->next;
        deletePlayer(current->p);
        current = nextNode;
    }
    head = nullptr;
}

void SQUAD_CLASS::addPlayer(PLAYER_CLASS* p) {
    if (p->getRemainingHealth() == 0 || isAlreadyInSquad(p)) return;

    Node* newNode = new Node(p);
    if (!head) {
        head = newNode;
    } else if (isBigger(head->p, newNode->p)) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next && isBigger(newNode->p, temp->next->p)) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int SQUAD_CLASS::getTeamSize() {
    size_t teamSize = 0;
    for (Node* current = head; current; current = current->next) {
        teamSize++;
    }
    return teamSize;
}

bool SQUAD_CLASS::isAlreadyInSquad(PLAYER_CLASS* p) {
    for (Node* current = head; current; current = current->next) {
        if (current->p == p) return true;
    }
    return false;
}

bool SQUAD_CLASS::isBigger(PLAYER_CLASS* bigger, PLAYER_CLASS* smaler) {
    if (bigger->getId() != smaler->getId()) return bigger->getId() > smaler->getId();
    if (bigger->maxHealth != smaler->maxHealth) return bigger->maxHealth > smaler->maxHealth;
    if (bigger->getRemainingHealth() != smaler->getRemainingHealth()) return bigger->getRemainingHealth() > smaler->getRemainingHealth();
    if (bigger->damage != smaler->damage) return bigger->damage > smaler->damage;
    if (bigger->agility != smaler->agility) return bigger->agility > smaler->agility;
    return true;
}

unsigned int SQUAD_CLASS::getDamage() {
    unsigned int sumDamage = 0;
    for (Node* current = head; current; current = current->next) {
        sumDamage += current->p->getDamage();
    }
    return sumDamage;
}

unsigned int SQUAD_CLASS::getAgility() {
    unsigned int minAgility = UINT_MAX;
    for (Node* current = head; current; current = current->next) {
        if (current->p->getAgility() < minAgility) minAgility = current->p->getAgility();
    }
    return minAgility;
}

void SQUAD_CLASS::takeDamage(unsigned int damageTaken) {
    damageTaken /= getTeamSize();
    for (Node* current = head; current;) {
        current->p->takeDamage(damageTaken);

        if (current->p->getRemainingHealth() == 0) {
            Node* toDelete = current;
            current = current->next;
            deletePlayer(toDelete->p);
        } else {
            current = current->next;
        }
    }
}

void SQUAD_CLASS::printParams() {
    if (getTeamSize() == 0) {
        std::cout << id << ":nemo\n";
        return;
    }
    std::cout << id << ":" << getTeamSize() << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << getAgility() << "\n";
    for (Node* current = head; current; current = current->next) {
        current->p->printParams();
    }
}

unsigned int SQUAD_CLASS::getRemainingHealth() {
    unsigned int theBiggestHealth = 0;
    for (Node* current = head; current; current = current->next) {
        if (current->p->getRemainingHealth() > theBiggestHealth) theBiggestHealth = current->p->getRemainingHealth();
    }
    return theBiggestHealth;
}

void CAESAR_CLASS::judgeDeathOrLife(PLAYER_CLASS* player) {
    battleCount++;
    if (battleCount % 3 == 0 && isPairAttacksOnLastBattle) {
        player->die();
        if (player->getType() == 3) player->deleteSquad(player);
    }
}

void ARENA_CLASS::fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2) {
    if (p1->getRemainingHealth() == 0 || p2->getRemainingHealth() == 0) return;
    if (p2->getAgility() > p1->getAgility()) {
        fight(p2, p1);
        return;
    }

    p1->printParams();
    p2->printParams();

    unsigned short attacks = 0;
    while (attacks != 40) {
        p2->takeDamage(p1->getDamage());
        p2->printParams();
        attacks++;
        if (p2->getRemainingHealth() < 10) break;

        p1->takeDamage(p2->getDamage());
        p1->printParams();
        attacks++;
        if (p1->getRemainingHealth() < 10) break;
    }

    caesar.isPairAttacksOnLastBattle = (attacks % 2 == 0);

    if (p1->getRemainingHealth() > 0) {
        // caesar.judgeDeathOrLife(p1);
        p1->printParams();
        if (p1->getRemainingHealth()) p1->applyWinnerReward();
    }
    if (p2->getRemainingHealth() > 0) {
        // caesar.judgeDeathOrLife(p2);
        p2->printParams();
        if (p2->getRemainingHealth()) p2->applyWinnerReward();
    }

    p1->printParams();
    p2->printParams();
}
