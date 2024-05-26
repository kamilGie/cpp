// kamil gieras
#pragma once
#include "branch.hpp"

class TREE_CLASS {
   public:
    TREE_CLASS(unsigned int number) : number(number){};
    ~TREE_CLASS();

    unsigned int getNumber();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();

   private:
    struct branchNode {
        branchNode(BRANCH_CLASS* val) : value(val) {}
        BRANCH_CLASS* value;
        branchNode* prev = nullptr;
        branchNode* next = nullptr;
    };
    branchNode* head = nullptr;
    unsigned int number;
    unsigned int totalBranches = 0;
    unsigned int height = 0;
    unsigned int sumFruitWeight = 0;
};