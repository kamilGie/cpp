#pragma once
#include "fruit.hpp"

class BRANCH_CLASS {
   public:
   BRANCH_CLASS(unsigned int height): height(height) {};
   ~BRANCH_CLASS();

   unsigned int getFruitsTotal();
   unsigned int getWeightsTotal();
   unsigned int getLength();
   void Growthbranch();
   void GrowthFruit();

   private:
    struct fruitNode {
        fruitNode(FRUIT_CLASS* val):value(val){}
        FRUIT_CLASS *value;
        fruitNode* prev=nullptr;
        fruitNode* next=nullptr;
    };
    fruitNode* head = nullptr;
    unsigned int height;
    unsigned int length;
    unsigned int totalFruits=0;
};