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
    unsigned int getFruitsTotal() { return getTotal(&TREE_CLASS::getFruitsTotal); }
    unsigned int getWeightsTotal() { return getTotal(&TREE_CLASS::getWeightsTotal); }
    unsigned int getBranchesTotal() { return getTotal(&TREE_CLASS::getBranchesTotal); }

    void plantTree();
    void ExtractTree(unsigned int NumberToDalate);
    unsigned int getTotal(unsigned int (TREE_CLASS::*func)()) const;

   private:
    struct treeNode {
        treeNode(TREE_CLASS* val) : value(val) {}
        TREE_CLASS* value;
        treeNode* prev = nullptr;
        treeNode* next = nullptr;
    };
    treeNode* head = nullptr;
    unsigned int tressTotal = 0;
};