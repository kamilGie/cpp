// kamil gieras
#include "branch.hpp"
#include "tree.hpp"

BRANCH_CLASS::~BRANCH_CLASS() {
    while (head) {
        fruitNode* temp = head;
        head = head->next;
        delete temp->value;
        delete temp;
    }
}

void BRANCH_CLASS::decreaseWeightsTotal(unsigned int ValTodecrease) {
    treePointer->decreaseWeightsTotal(ValTodecrease);
     weightsTotal-=ValTodecrease; 
}

void BRANCH_CLASS::increaseWeightsTotal(unsigned int ValToIncrease) {
    treePointer->increaseWeightsTotal(ValToIncrease);
    weightsTotal+=ValToIncrease; 
}

void BRANCH_CLASS::Growthbranch() {
    length++;
    bool isLengthFree = true;
    for (fruitNode* current = head; current; current = current->next) {
        current->value->growthFruit();
        if (current->value->getLength() == length) isLengthFree = false;
    }
    if (length % 2 == 0 && isLengthFree) GrowthFruit();
}

void BRANCH_CLASS::fadeBranch() {
    length--;
    for (fruitNode* current = head; current; current = current->next) {
        current->value->fadeFruit();
    }
}

void BRANCH_CLASS::GrowthFruit() {
    fruitNode* newFruit = new fruitNode(new FRUIT_CLASS(this, length));
    if (head) {
        newFruit->next = head;
        head->prev = newFruit;
    }
    head = newFruit;
    FruitsTotal++;
}
