#pragma once
#include "fruit.hpp"

class TREE_CLASS;

class BRANCH_CLASS {
   private:
    struct fruitNode;

   public:
    BRANCH_CLASS(TREE_CLASS* treePointer,unsigned int height) :treePointer(treePointer), height(height){};
    ~BRANCH_CLASS();

    unsigned int getHeight() { return height; }
    unsigned int getLength() { return length; }
    TREE_CLASS* getTreePointer() { return treePointer; }
    unsigned int getFruitsTotal() { return FruitsTotal; }
    unsigned int getWeightsTotal() { return weightsTotal; }

    void fadeBranch();
    void GrowthFruit();
    void Growthbranch();
    void decreaseWeightsTotal( unsigned int ValToDecrease );
    void increaseWeightsTotal( unsigned int ValToIncrease );

   private:
    TREE_CLASS* treePointer;

    unsigned int height;
    unsigned int length;
    unsigned int FruitsTotal=0;
    unsigned int weightsTotal=0;

    struct fruitNode {
        fruitNode(FRUIT_CLASS* val) : value(val) {}
        FRUIT_CLASS* value;
        fruitNode* prev = nullptr;
        fruitNode* next = nullptr;
    };
    fruitNode* head = nullptr;
};