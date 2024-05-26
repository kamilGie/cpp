// kamil gieras
#include <iostream>
#include <string>

class PLAYER_CLASS {
   public:
    PLAYER_CLASS(){};
    virtual ~PLAYER_CLASS() = default;

    virtual void cure() { health = maxHealth; }
    virtual void deleteSquad(PLAYER_CLASS* p) {};
    virtual void deletePlayer(PLAYER_CLASS* p) {};
    virtual unsigned int getDamage() { return damage; }
    virtual unsigned int getAgility() { return agility; }
    virtual unsigned int getRemainingHealth() { return static_cast<unsigned int>(float(health) / float(maxHealth) * 100.0f); }

    virtual void applyWinnerReward();
    virtual void takeDamage(unsigned int damageTaken);

    virtual int getType() = 0;
    virtual void printParams() = 0;
    virtual std::string getId() = 0;

   public:
    unsigned int maxHealth;
    unsigned int health;
    unsigned int damage;
    unsigned int agility;

   public:
    friend class CAESAR_CLASS;
    friend class SQUAD_CLASS;

   private:
    virtual void die() { health = 0; }
};

class HUMAN_CLASS : virtual public PLAYER_CLASS {
   public:
    HUMAN_CLASS(std::string id) : id(id) {
        maxHealth = 200;
        health = 200;
        damage = 30;
        agility = 10;
        defance = 10;
    }

    int getType() override { return 1; }
    std::string getId() override { return id; }

    void printParams() override;
    void takeDamage(unsigned int damageTaken) override;

   public:
    unsigned int defance;

   public:
    friend class SQUAD_CLASS;

   private:
    std::string id;
};

class BEAST_CLASS : virtual public PLAYER_CLASS {
   public:
    BEAST_CLASS(std::string id) : id(id) {
        maxHealth = 150;
        health = 150;
        damage = 40;
        agility = 20;
    }

    int getType() override { return 2; }
    std::string getId() override { return id; }
    unsigned int getDamage() override { return getRemainingHealth() < 25 ? damage * 2 : damage; }

    void printParams() override;
    void takeDamage(unsigned int damageTaken) override;

   public:
    friend class SQUAD_CLASS;

   private:
    std::string id;
};

class BERSERKER_CLASS : public BEAST_CLASS, public HUMAN_CLASS {
   public:
    BERSERKER_CLASS(std::string HummanId, std::string BeastId) : BEAST_CLASS(BeastId), HUMAN_CLASS(HummanId) {
        maxHealth = 200;
        health = 200;
        damage = 35;
        agility = 5;
        defance = 15;
    }

    std::string getId() override { return (getType() == 1) ? HUMAN_CLASS::getId() : BEAST_CLASS::getId(); }
    void printParams() override { (getType() == 1) ? HUMAN_CLASS::printParams() : BEAST_CLASS::printParams(); }
    unsigned int getDamage() override { return (getType() == 1) ? HUMAN_CLASS::getDamage() : BEAST_CLASS::getDamage(); }
    unsigned int getAgility() override { return (getType() == 1) ? HUMAN_CLASS::getAgility() : BEAST_CLASS::getAgility(); }
    void takeDamage(unsigned int damageTaken) override { (getType() == 1) ? HUMAN_CLASS::takeDamage(damageTaken) : BEAST_CLASS::takeDamage(damageTaken); }

   public:
    friend class SQUAD_CLASS;

   private:
    int getType() override { return (getRemainingHealth() < 25 && getRemainingHealth() != 0) ? BEAST_CLASS::getType() : HUMAN_CLASS::getType(); }

   private:
    std::string HummanId;
    std::string BeastId;
};

class SQUAD_CLASS : public PLAYER_CLASS {
   public:
    SQUAD_CLASS(std::string id) : id(id){};
    ~SQUAD_CLASS() { deleteSquad(this); }

    int getType() override { return 3; };
    std::string getId() override { return id; }

    void printParams() override;
    void addPlayer(PLAYER_CLASS* p);
    void applyWinnerReward() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void deleteSquad(PLAYER_CLASS* p) override;
    unsigned int getRemainingHealth() override;
    void deletePlayer(PLAYER_CLASS* p) override;
    void takeDamage(unsigned int damageTaken) override;

   private:
    int getTeamSize();
    void UpdateSquad();
    bool isAlreadyInSquad(PLAYER_CLASS* p);
    bool isBigger(PLAYER_CLASS* bigger, PLAYER_CLASS* smaler);

   private:
    std::string id;
    struct Node {
        Node(PLAYER_CLASS* p) : p(p){};

        PLAYER_CLASS* p;
        Node* next = nullptr;
    };
    Node* head = nullptr;
};

class CAESAR_CLASS {
   public:
    CAESAR_CLASS(){};

    void judgeDeathOrLife(PLAYER_CLASS* player);

   public:
    bool isPairAttacksOnLastBattle;

   private:
    size_t battleCount = 0;
};

class ARENA_CLASS {
   public:
    ARENA_CLASS(CAESAR_CLASS* caesar) : caesar(*caesar){};

    void fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2);

   private:
    CAESAR_CLASS caesar;
};

// ###################/
// ### definitions ###/
// ###################/

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
    newNode->next = head;
    head = newNode;
}

int SQUAD_CLASS::getTeamSize() {
    UpdateSquad();
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
    return false;
}

unsigned int SQUAD_CLASS::getDamage() {
    UpdateSquad();
    unsigned int sumDamage = 0;
    for (Node* current = head; current; current = current->next) {
        sumDamage += current->p->getDamage();
    }
    return sumDamage;
}

unsigned int SQUAD_CLASS::getAgility() {
    UpdateSquad();
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

void SQUAD_CLASS::UpdateSquad() {
    for (Node* current = head; current;) {
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
    int teamSizeToPrint = getTeamSize();
    if (!teamSizeToPrint) {
        std::cout << id << ":nemo\n";
        return;
    }

    std::cout << id << ":" << teamSizeToPrint << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << getAgility() << "\n";
    PLAYER_CLASS* toPrint = nullptr;
    PLAYER_CLASS* printedBefore = nullptr;
    while (teamSizeToPrint--) {
        for (Node* current = head; current; current = current->next) {
            if ((!printedBefore || isBigger(current->p, printedBefore)) && (!toPrint || isBigger(toPrint, current->p))) toPrint = current->p;
        }
        toPrint->printParams();
        printedBefore = toPrint;
        toPrint = nullptr;
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
        attacks++;
        p2->takeDamage(p1->getDamage());
        p2->printParams();
        if (p2->getRemainingHealth() < 10) break;

        attacks++;
        p1->takeDamage(p2->getDamage());
        p1->printParams();
        if (p1->getRemainingHealth() < 10) break;
    }

    caesar.isPairAttacksOnLastBattle = (attacks % 2 == 0);

    if (p1->getRemainingHealth() > 0) {
        caesar.judgeDeathOrLife(p1);
        p1->printParams();
        if (p1->getRemainingHealth()) p1->applyWinnerReward();
    }
    if (p2->getRemainingHealth() > 0) {
        caesar.judgeDeathOrLife(p2);
        p2->printParams();
        if (p2->getRemainingHealth()) p2->applyWinnerReward();
    }

    p1->printParams();
    p2->printParams();
}