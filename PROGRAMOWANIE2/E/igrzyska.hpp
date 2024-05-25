#pragma once
#include <iostream>
#include <string>

class PLAYER_CLASS {
   public:
    PLAYER_CLASS(){};
    virtual ~PLAYER_CLASS() = default;

    virtual void deletePlayer(PLAYER_CLASS* p){};
    virtual void deleteSquad(PLAYER_CLASS* p){};
    virtual int sumOfAgilityAndDefance()=0;
    virtual int getType()=0;
    virtual std::string getId()=0;
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

    int getType() override;
    std::string getId() override;
    int sumOfAgilityAndDefance() override;
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

    int getType() override;
    int sumOfAgilityAndDefance() override;
    std::string getId() override;
    unsigned int getDamage() override;
    void takeDamage(unsigned int damageTaken) override;
    void printParams() override;

    public:

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

    std::string getId() override;
    int getType() override;
    int sumOfAgilityAndDefance() override;
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

    std::string getId() override;
    void deletePlayer(PLAYER_CLASS* p) override;
    void deleteSquad(PLAYER_CLASS* p) override;
    void addPlayer(PLAYER_CLASS* p);
    int sumOfAgilityAndDefance() override;
    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage(unsigned int damageTaken) override;
    void printParams() override;
    int getType()override;

   private:
    int getTeamSize();
    bool isAlreadyInSquad(PLAYER_CLASS* p);
    bool isBigger(PLAYER_CLASS* bigger, PLAYER_CLASS* smaler);

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