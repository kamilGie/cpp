#pragma once
#include <iostream>
#include <string>

class PLAYER_CLASS {
   public:
    PLAYER_CLASS();
    virtual ~PLAYER_CLASS() = default;

    virtual unsigned int getRemainingHealth();
    virtual unsigned int getDamage();
    virtual unsigned int getAgility();
    virtual void takeDamage(unsigned int damageTaken);
    void applyWinnerReward();
    void cure();
    void printParams();

   public:
    unsigned int maxHealth;
    unsigned int health;
    unsigned int damage;
    unsigned int agility;

   public:
    friend class CAESAR_CLASS;
    //friend class SQUAD_CLASS; nwm czy to potrzebne 

    private:
        void die();
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

    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
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

    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
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

    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage(unsigned int damageTaken) override;

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

   private:
    std::string id;
};

class CAESAR_CLASS {
   public:
    void judgeDeathOrLife(PLAYER_CLASS* player);
};

class ARENA_CLASS {
   public:
    ARENA_CLASS(CAESAR_CLASS* caesar) : caesar(*caesar){};
    void fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2);

   private:
    CAESAR_CLASS caesar;
};