// kamil gieras
#pragma once
#include "branch.hpp"

class GARDEN_CLASS;
typedef unsigned int amount;
typedef unsigned int number;

class TREE_CLASS {
   public:
    TREE_CLASS(GARDEN_CLASS* gardenPointer, amount treeNumber) :gardenPointer(gardenPointer), treeNumber(treeNumber){};
    ~TREE_CLASS();

    amount getHeight() { return height; }
    number getNumber() { return treeNumber; }
    amount getFruitsTotal() { return fruitsTotal; }
    amount getWeightsTotal() { return WeightsTotal; }
    amount getBranchesTotal() { return totalBranches; }
    GARDEN_CLASS* gatGardenPointer() { return gardenPointer; }

    void fadeTree();
    void addNewTree();
    void growthTree();
    void removeBranchFromTop();
    void decreaseFruitsTotal();
    void increaseFruitsTotal();
    void decreaseWeightsTotal( amount ValToDecrease );
    void increaseWeightsTotal( amount ValToIncrease );

   private:
    GARDEN_CLASS* gardenPointer;

    number treeNumber;
    amount height = 0;
    amount fruitsTotal = 0;
    amount WeightsTotal = 0;
    amount totalBranches = 0;

    struct branchNode {
        branchNode(BRANCH_CLASS* val) : value(val) {}
        BRANCH_CLASS* value;
        branchNode* prev = nullptr;
        branchNode* next = nullptr;
    };
    branchNode* head = nullptr;
};