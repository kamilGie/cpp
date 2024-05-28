// kamil gieras
#pragma once
#include "branch.hpp"

class GARDEN_CLASS;

class TREE_CLASS {
   private:
    struct branchNode;

   public:
    TREE_CLASS(GARDEN_CLASS* gardenPointer, unsigned int number) :gardenPointer(gardenPointer), number(number){};
    ~TREE_CLASS();

    unsigned int getHeight() { return height; }
    unsigned int getNumber() { return number; }
    unsigned int getFruitsTotal() { return fruitsTotal; }
    unsigned int getWeightsTotal() { return WeightsTotal; }
    unsigned int getBranchesTotal() { return totalBranches; }
    GARDEN_CLASS* gatGardenPointer() { return gardenPointer; }

    void decreaseWeightsTotal( unsigned int ValToDecrease );
    void increaseWeightsTotal( unsigned int ValToIncrease );

   private:
    GARDEN_CLASS* gardenPointer;

    unsigned int number;
    unsigned int height = 0;
    unsigned int fruitsTotal = 0;
    unsigned int WeightsTotal = 0;
    unsigned int totalBranches = 0;

    struct branchNode {
        branchNode(BRANCH_CLASS* val) : value(val) {}
        BRANCH_CLASS* value;
        branchNode* prev = nullptr;
        branchNode* next = nullptr;
    };
    branchNode* head = nullptr;
};