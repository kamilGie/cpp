// kamil gieras
#pragma once
#include "tree.hpp"

class GARDEN_CLASS {
   public:
    GARDEN_CLASS() {}
    ~GARDEN_CLASS();

    unsigned int getTressTotal();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();

   private:
    struct treeNode {
        treeNode(TREE_CLASS* val) : value(val) {}
        TREE_CLASS* value;
        treeNode* prev=nullptr;
        treeNode* next=nullptr;
    };
    treeNode *head = nullptr;
    unsigned int totalTrees = 0;
    unsigned int sumFruitWeight = 0;
};