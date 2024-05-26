// kamil gieras
#include "branch.hpp"

BRANCH_CLASS::~BRANCH_CLASS() {
        while (head) {
        fruitNode* temp = head;
        head = head->next;
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
