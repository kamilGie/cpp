// kamil gieras
#pragma once
#include "branch.hpp"

class GARDEN_CLASS;
typedef unsigned int amount;
typedef unsigned int number;

class TREE_CLASS {
   public:
    TREE_CLASS(GARDEN_CLASS* gardenPointer, amount treeNumber);
    TREE_CLASS(const TREE_CLASS& other, number treeNumber);
    ~TREE_CLASS();

    amount getHeight() { return height; }
    number getNumber() { return treeNumber; }
    amount getFruitsTotal() { return fruitsTotal; }
    amount getWeightsTotal() { return WeightsTotal; }
    amount getBranchesTotal() { return totalBranches; }
    GARDEN_CLASS* gatGardenPointer() { return gardenPointer; }

    void fadeTree();
    void addNewBranch();
    void growthTree();
    void removeBranchFromTop();
    void decreaseFruitsTotal();
    void decreaseBranchesTotal();
    void cutTree(amount newHeigth);
    void harvestTree(amount weightToPluck);
    void cloneBranch(BRANCH_CLASS* cloningBranch);
    void decreaseWeightsTotal(amount ValToDecrease);
    void increaseWeightsTotal(amount ValToIncrease);
    BRANCH_CLASS* getBranchPointer(amount fruitLength);
    void increaseFruitsTotal(amount ValToIncrease = 1);
    void increaseBranchesTotal(amount ValToIncrease = 1);

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
        branchNode* next = nullptr;
    };
    branchNode* head = nullptr;
};