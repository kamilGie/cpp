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
    return totalFruits;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    unsigned int weightsTotal = 0;
    for (fruitNode* current = head; current; current = current->next) {
        weightsTotal += current->value->getWeights();
    }
    return weightsTotal;
}

unsigned int BRANCH_CLASS::getLength() {
    return length;
}

void BRANCH_CLASS::Growthbranch() {
    length++;

    fruitNode* current = head;
    if (length % 2 == 0) {
        bool isLengthoccupied = false;
        while(current) {
            current->value->growthFruit();
            if (current->value->getLength() == length){
                isLengthoccupied = true;
                break;
            } 
            current = current->next;
        }
        current = current->next;
        if (!isLengthoccupied) GrowthFruit();
    }

    while(current){
        current->value->growthFruit();
        current = current->next;
    }
}

void BRANCH_CLASS::GrowthFruit() {
    FRUIT_CLASS* newFruitClass = new FRUIT_CLASS(this,length);
    fruitNode* newFruit = new fruitNode(newFruitClass);
    if (head) {
        newFruit->next = head;
        head->prev = newFruit;
    }
    head = newFruit;
}
