#pragma once
#include <string>

class PLAYER_CLASS {
   public:
    PLAYER_CLASS();
    virtual ~PLAYER_CLASS() = default;

    virtual unsigned int getRemainingHealth();
    virtual unsigned int getDamage();
    virtual unsigned int getAgility();
    virtual void takeDamage();
    void applyWinnerReward();
    void cure();
    void printParams();
    void die();

   public:
    unsigned int maxHealth;
    unsigned int health;
    unsigned int atack;
    unsigned int agility;

   public:
    friend class CAESAR_CLASS;
};

class HUMAN_CLASS : virtual public PLAYER_CLASS {
   public:
    HUMAN_CLASS(std::string id) : id(id) {
        maxHealth = 200;
        health = 200;
        atack = 30;
        agility = 10;
        defance = 10;
    }

    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage() override;

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
        atack = 40;
        agility = 20;
    }

    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage() override;

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
        atack = 35;
        agility = 5;
        defance = 15;
    }

    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage() override;

    public:
      friend class SQUAD_CLASS;

   private:
       std::string HummanId;
       std::string BeastId;
};

class SQUAD_CLASS : public PLAYER_CLASS {
   public:
    SQUAD_CLASS(std::string id) : id(id) {};

    void addPleyer(PLAYER_CLASS* p);

    unsigned int getRemainingHealth() override;
    unsigned int getDamage() override;
    unsigned int getAgility() override;
    void takeDamage() override;

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