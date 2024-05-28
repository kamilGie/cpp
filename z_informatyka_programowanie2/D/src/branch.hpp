#pragma once
#include "fruit.hpp"

class TREE_CLASS;
typedef unsigned int amount;

class BRANCH_CLASS {
   public:
    BRANCH_CLASS(TREE_CLASS* treePointer,amount height) :treePointer(treePointer), height(height){};
    ~BRANCH_CLASS();

    amount getHeight() { return height; }
    amount getLength() { return length; }
    amount getFruitsTotal() { return FruitsTotal; }
    amount getWeightsTotal() { return weightsTotal; }
    TREE_CLASS* getTreePointer() { return treePointer; }

    void fadeBranch();
    void GrowthFruit();
    void Growthbranch();
    void decreaseWeightsTotal( amount ValToDecrease );
    void increaseWeightsTotal( amount ValToIncrease );

   private:
    TREE_CLASS* treePointer;

    amount height;
    amount length;
    amount FruitsTotal=0;
    amount weightsTotal=0;

    struct fruitNode {
        fruitNode(FRUIT_CLASS* val) : value(val) {}
        FRUIT_CLASS* value;
        fruitNode* prev = nullptr;
        fruitNode* next = nullptr;
    };
    fruitNode* head = nullptr;
};