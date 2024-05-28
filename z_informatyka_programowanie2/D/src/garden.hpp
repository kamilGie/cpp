// kamil gieras
#pragma once
#include "tree.hpp"

class GARDEN_CLASS {
   private:
    struct treeNode;

   public:
    GARDEN_CLASS() {}
    ~GARDEN_CLASS();

    unsigned int getTressTotal() { return tressTotal; }
    unsigned int getFruitsTotal() { return FruitsTotal; }
    unsigned int getWeightsTotal() { return weightsTotal; }
    unsigned int getBranchesTotal() { return BranchesTotal; }
    void decreaseWeightsTotal( unsigned int ValToDecrease ) { weightsTotal-=ValToDecrease; }
    void increaseWeightsTotal( unsigned int ValToIncrease ) { weightsTotal-=ValToIncrease; }

    void plantTree();
    void ExtractTree(unsigned int NumberToDalate);

   private:
    unsigned int tressTotal = 0;
    unsigned int FruitsTotal = 0;
    unsigned int weightsTotal = 0;
    unsigned int BranchesTotal = 0;
    
    struct treeNode {
        treeNode(TREE_CLASS* val) : value(val) {}
        TREE_CLASS* value;
        treeNode* prev = nullptr;
        treeNode* next = nullptr;
    };
    treeNode* head = nullptr;
};