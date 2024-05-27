// kamil gieras
#include "branch.hpp"

BRANCH_CLASS::~BRANCH_CLASS() {
    while (head) {
        fruitNode* temp = head;
        head = head->next;
        delete temp->value;
        delete temp;
    }
}

unsigned int BRANCH_CLASS::getFruitsTotal() {
    unsigned int FruitsTotal = 0;
    for (fruitNode* current = head; current; current = current->next) {
        FruitsTotal++;
    }
    return FruitsTotal;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    unsigned int weightsTotal = 0;
    for (fruitNode* current = head; current; current = current->next) {
        weightsTotal += current->value->getWeights();
    }
    return weightsTotal;
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
}
