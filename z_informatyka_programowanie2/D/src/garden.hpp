// kamil gieras
#pragma once
#include "tree.hpp"

typedef unsigned int amount;
typedef unsigned int number;

class GARDEN_CLASS {
   public:
    GARDEN_CLASS() {}
    ~GARDEN_CLASS();

    void decreaseTressTotal() { tressTotal--; }
    void increaseTressTotal() { tressTotal++; }
    void decreaseFruitsTotal() { FruitsTotal--; }
    amount getTressTotal() { return tressTotal; }
    amount getFruitsTotal() { return FruitsTotal; }
    void decreaseBranchesTotal() { BranchesTotal--; }
    amount getWeightsTotal() { return weightsTotal; }
    amount getBranchesTotal() { return BranchesTotal; }
    void fadeGarden() { ForEachTree(&TREE_CLASS::fadeTree); }
    void growthGarden() { ForEachTree(&TREE_CLASS::growthTree); }
    void cloneTree(TREE_CLASS* treeToClone) { plantTree(treeToClone); }
    void decreaseWeightsTotal(amount ValToDecrease) { weightsTotal -= ValToDecrease; }
    void increaseWeightsTotal(amount ValToIncrease) { weightsTotal += ValToIncrease; }
    void increaseBranchesTotal(amount ValToIncrease=1) { BranchesTotal+= ValToIncrease; }
    void increaseFruitsTotal(amount ValToIncrease = 1) { FruitsTotal += ValToIncrease; }

    void ExtractTree(number numberToDalate);
    void harvestGarden(amount weightToPluck);
    void plantTree(TREE_CLASS* seed = nullptr);
    void ForEachTree(void (TREE_CLASS::*func)());
    TREE_CLASS* getTreePointer(number numberToFind);

   private:
    amount tressTotal = 0;
    amount FruitsTotal = 0;
    amount weightsTotal = 0;
    amount BranchesTotal = 0;

    struct treeNode {
        treeNode(TREE_CLASS* val) : value(val) {}
        TREE_CLASS* value;
        treeNode* next = nullptr;
    };
    treeNode* head = nullptr;
};