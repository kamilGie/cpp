#pragma once
#include "fruit.hpp"

class BRANCH_CLASS {
   public:
   BRANCH_CLASS(){};
   ~BRANCH_CLASS();

   unsigned int getFruitsTotal();
   unsigned int getWeightsTotal();

   private:
    struct fruitNode {
        fruitNode(FRUIT_CLASS* val):value(val){}
        FRUIT_CLASS *value;
        fruitNode* prev=nullptr;
        fruitNode* next=nullptr;
    };
    fruitNode* head = nullptr;
    unsigned int length=0;
    unsigned int totalFruits=0;
    unsigned int sumFruitWeight=0;
};