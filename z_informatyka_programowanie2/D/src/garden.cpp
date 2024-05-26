// kamil gieras
#include "garden.hpp"

GARDEN_CLASS::~GARDEN_CLASS() {
    while (head) {
        treeNode* temp = head;
        head = head->next;
        delete temp->value;
        delete temp;
    }
}

void GARDEN_CLASS::plantTree() {
    TREE_CLASS* newTreeClass = new TREE_CLASS(getMinAvibleNumber());
    treeNode* newTree = new treeNode(newTreeClass);
    if (head) {
        newTree->next = head;
        head->prev = newTree;
    }
    head = newTree;
    totalTrees++;
}

unsigned int GARDEN_CLASS::getMinAvibleNumber() {
    for(unsigned int min = 0;; min++) {
        bool find=true;
        for (treeNode* current = head; current; current = current->next) {
            if (current->value->getNumber() == min) {
                find=false;
                break;
            }
        }
        if(find) return min;
    }
}

void GARDEN_CLASS::ExtractTree(unsigned int NumberToDalate) {
    for (treeNode* current = head; current; current = current->next) {
        if (current->value->getNumber() == NumberToDalate) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            delete current->value;
            delete current;
            totalTrees--;
            return;
        }
    }

}
   

unsigned int GARDEN_CLASS::getTressTotal() {
    return totalTrees;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    unsigned int BranchesTotal = 0;
    for (treeNode* current = head; current; current = current->next) {
        BranchesTotal += current->value->getBranchesTotal();
    }
    return BranchesTotal;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    unsigned int FruitsTotal = 0;
    for (treeNode* current = head; current; current = current->next) {
        FruitsTotal += current->value->getFruitsTotal();
    }
    return FruitsTotal;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {
    unsigned int weightsTotal = 0;
    for (treeNode* current = head; current; current = current->next) {
        weightsTotal += current->value->getWeightsTotal();
    }
    return weightsTotal;
}
