#pragma once
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