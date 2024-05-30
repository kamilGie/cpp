// kamil gieras
#include "branch.hpp"

#include "tree.hpp"

BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS* treePointer, amount height) : treePointer(treePointer), height(height) {
    treePointer->increaseBranchesTotal();
}

BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& clone) : BRANCH_CLASS(clone.treePointer, clone.height) {
    length = clone.length;
    FruitsTotal = clone.FruitsTotal;
    weightsTotal = clone.weightsTotal;
    
    treePointer->increaseWeightsTotal(weightsTotal);
    treePointer->increaseFruitsTotal(FruitsTotal);

    if (clone.head) {
        head = new fruitNode(clone.head->value);
        fruitNode* current = head;
        fruitNode* cloneCurrent = clone.head->next;
        while (cloneCurrent) {
            current->next = new fruitNode(cloneCurrent->value);
            current = current->next;
            cloneCurrent = cloneCurrent->next;
        }
    }
}

BRANCH_CLASS::~BRANCH_CLASS() {
    while (head) {
        fruitNode* temp = head;
        head = head->next;
        delete temp->value;
        delete temp;
    }
    treePointer->decreaseBranchesTotal();
}

void BRANCH_CLASS::increaseFruitsTotal() {
    treePointer->increaseFruitsTotal();
    FruitsTotal++;
}

void BRANCH_CLASS::decreaseFruitsTotal() {
    treePointer->decreaseFruitsTotal();
    FruitsTotal--;
}

void BRANCH_CLASS::decreaseWeightsTotal(amount ValTodecrease) {
    treePointer->decreaseWeightsTotal(ValTodecrease);
    weightsTotal -= ValTodecrease;
}

void BRANCH_CLASS::increaseWeightsTotal(amount ValToIncrease) {
    treePointer->increaseWeightsTotal(ValToIncrease);
    weightsTotal += ValToIncrease;
}

void BRANCH_CLASS::harvestBranch(amount weightToPluck) {
    for (fruitNode* current = head; current; current = current->next) {
        if (current->value->getWeight() >= weightToPluck) current->value->pluckFruit();
    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitsPointer(amount fruitLength) {
    for (fruitNode* current = head; current; current = current->next) {
        if (current->value->getLength() == fruitLength) return current->value;
    }
    return nullptr;
}

void BRANCH_CLASS::Growthbranch() {
    length++;
    bool isLengthFree = true;
    for (fruitNode* current = head; current; current = current->next) {
        current->value->growthFruit();
        if (current->value->getLength() == length) isLengthFree = false;
    }
    if (length % 2 == 0 && isLengthFree) addNewFruit();
}

void BRANCH_CLASS::cutBranch(amount newLength) {
    length = newLength;
    for (fruitNode* current = head; current && current->value->getLength() < length; current = current->next) {
        removeFruitFromTop();
    }
}

void BRANCH_CLASS::fadeBranch() {
    length--;
    if (head->value->getLength() > length) removeFruitFromTop();
    for (fruitNode* current = head; current; current = current->next) {
        current->value->fadeFruit();
    }
}

void BRANCH_CLASS::removeFruitFromTop() {
    fruitNode* temp = head;
    head = head->next;
    delete temp->value;
    delete temp;
}

void BRANCH_CLASS::addNewFruit() {
    fruitNode* newFruit = new fruitNode(new FRUIT_CLASS(this, length));
    newFruit->next = head;
    head = newFruit;
}
