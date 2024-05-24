#pragma once
#include <iostream>
#include <string>

class PLAYER_CLASS {
   public:
    PLAYER_CLASS(){};
    virtual ~PLAYER_CLASS() = default;

    virtual unsigned int getRemainingHealth();
    virtual unsigned int getDamage();
    virtual unsigned int getAgility();
    virtual void takeDamage(unsigned int damageTaken);
    virtual void applyWinnerReward();
    virtual void cure();
    virtual void printParams() = 0;

   public:
    unsigned int maxHealth;
    unsigned int health;
    unsigned int damage;
    unsigned int agility;

   public:
    friend class CAESAR_CLASS;
    friend class SQUAD_CLASS;

   private:
    virtual void die();
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

    void takeDamage(unsigned int damageTaken) override;
    void printParams() override;

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

    unsigned int getDamage() override;
    void takeDamage(unsigned int damageTaken) override;
    void printParams() override;

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

    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage(unsigned int damageTaken) override;
    void printParams() override;

   public:
    friend class SQUAD_CLASS;

   private:
    std::string HummanId;
    std::string BeastId;
};

class SQUAD_CLASS : public PLAYER_CLASS {
   public:
    SQUAD_CLASS(std::string id) : id(id){};

    void addPleyer(PLAYER_CLASS* p);
    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage(unsigned int damageTaken) override;
    void printParams() override;

   private:
    int getTeamSize();

   private:
    std::string id;
    struct Node {
        Node(PLAYER_CLASS* p) : p(p) {};

        PLAYER_CLASS* p;
        Node* next=nullptr;
    };
    Node* head=nullptr;
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