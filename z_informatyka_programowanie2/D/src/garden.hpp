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
    void increaseFruitsTotal(amount ValToIncrease=1) { FruitsTotal+=ValToIncrease; }
    amount getTressTotal() { return tressTotal; }
    amount getFruitsTotal() { return FruitsTotal; }
    void increaseBranchesTotal() { BranchesTotal++; }
    void decreaseBranchesTotal() { BranchesTotal--; }
    amount getWeightsTotal() { return weightsTotal; }
    amount getBranchesTotal() { return BranchesTotal; }
    void decreaseWeightsTotal(amount ValToDecrease) { weightsTotal -= ValToDecrease; }
    void increaseWeightsTotal(amount ValToIncrease) { weightsTotal += ValToIncrease; }

    void plantTree();
    void fadeGarden();
    void growthGarden();
    void cloneTree(TREE_CLASS* treeToClone);
    void harvestGarden(amount weightToPluck);
    void ExtractTree(number numberToDalate);
    TREE_CLASS* getTreePointer(number numberToFind);

   private:
    amount tressTotal = 0;
    amount FruitsTotal = 0;
    amount weightsTotal = 0;
    amount BranchesTotal = 0;

    struct treeNode {
        treeNode(TREE_CLASS* val) : value(val) {}
        TREE_CLASS* value;
        treeNode* prev = nullptr;
        treeNode* next = nullptr;
    };
    treeNode* head = nullptr;

    // struct MinimumNumberNode {
    //     MinimumNumberNode(number minNumber, treeNode* prevClass = nullptr) : minNumber(minNumber) {}
    //     number minNumber;
    //     MinimumNumberNode* next = nullptr;
    //     treeNode* prevClass;
    // };
    // MinimumNumberNode* curentMinNumber = new MinimumNumberNode(0);
};