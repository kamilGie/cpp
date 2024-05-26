#pragma once
#include "fruit.hpp"

class BRANCH_CLASS {
   public:
   private:
    struct fruitNode {
        FRUIT_CLASS value;
        fruitNode* prev;
        fruitNode* next;
    };
    unsigned int length;
    unsigned int totalFruits;
    unsigned int sumFruitWeight;
};