// kamil gieras
#pragma once
#include "tree.hpp"

class GARDEN_CLASS {
   public:
   private:
    struct treeNode {
        TREE_CLASS value;
        treeNode* prev;
        treeNode* next;
    };
    unsigned int totalTrees;
    unsigned int sumFruitWeight;
};