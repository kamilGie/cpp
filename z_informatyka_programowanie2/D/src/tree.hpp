// kamil gieras
#pragma once
#include "branch.hpp"

class TREE_CLASS {
   public:
   private:
    struct branchNode {
        BRANCH_CLASS value;
        branchNode* prev;
        branchNode* next;
    };
    unsigned int id;
    unsigned int totalBranches;
    unsigned int height;
    unsigned int sumFruitWeight;
};