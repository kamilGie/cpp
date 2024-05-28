// kamil gieras
#include "tree.hpp"

#include "garden.hpp"

TREE_CLASS::~TREE_CLASS() {
    while (head) {
        branchNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void TREE_CLASS::growthTree() {
    height++;
    bool isLengthFree = true;
    for (branchNode* current = head; current; current = current->next) {
        current->value->Growthbranch();
        if (current->value->getLength() == height) isLengthFree = false;
    }
    if (height % 3 == 0 && isLengthFree) addNewTree();
}

void TREE_CLASS::fadeTree() {
    if (!height) return;
    height--;
    if (head->value->getLength() > height) removeBranchFromTop();
    for (branchNode* current = head; current; current = current->next) {
        current->value->fadeBranch();
    }
}

void TREE_CLASS::addNewTree() {
    branchNode* newBranch = new branchNode(new BRANCH_CLASS(this, height));
    if (head) {
        newBranch->next = head;
        head->prev = newBranch;
    }
    head = newBranch;
    totalBranches++;
}

void TREE_CLASS::removeBranchFromTop() {
    branchNode* temp = head;
    head = head->next;
    delete temp->value;
    delete temp;
    totalBranches--;
}

void TREE_CLASS::decreaseWeightsTotal(amount ValToDecrease) {
    gardenPointer->decreaseWeightsTotal(ValToDecrease);
    WeightsTotal -= ValToDecrease;
}

void TREE_CLASS::increaseWeightsTotal(amount ValToIncrease) {
    gardenPointer->increaseWeightsTotal(ValToIncrease);
    WeightsTotal += ValToIncrease;
}

void TREE_CLASS::decreaseFruitsTotal() {
    fruitsTotal--;
}

void TREE_CLASS::increaseFruitsTotal() {
    fruitsTotal++;
}
