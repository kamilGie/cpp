// kamil gieras
#include "tree.hpp"

TREE_CLASS::~TREE_CLASS() {
    while (head) {
        branchNode* temp = head;
        head = head->next;
        delete temp;
    }
}

unsigned int TREE_CLASS::getNumber() {
    return number;
}

unsigned int TREE_CLASS::getBranchesTotal() {
    return totalBranches;
}

unsigned int TREE_CLASS::getFruitsTotal() {
    unsigned int FruitsTotal = 0;
    for (branchNode* current = head; current; current = current->next) {
        FruitsTotal += current->value->getFruitsTotal();
    }
    return FruitsTotal;
}

unsigned int TREE_CLASS::getWeightsTotal() {
    unsigned int weightsTotal = 0;
    for (branchNode* current = head; current; current = current->next) {
        weightsTotal += current->value->getWeightsTotal();
    }
    return weightsTotal;
}
