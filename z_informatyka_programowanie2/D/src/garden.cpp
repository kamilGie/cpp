// kamil gieras
#include "garden.hpp"

GARDEN_CLASS::~GARDEN_CLASS() {
    while (head) {
        treeNode* temp = head;
        head = head->next;
        delete temp;
    }
}

unsigned int GARDEN_CLASS::getTressTotal() {
    return totalTrees;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    unsigned int BranchesTotal=0;
    for(treeNode* current = head; current; current= current->next){
        BranchesTotal += current->value->getBranchesTotal();
    }
    return BranchesTotal;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    unsigned int FruitsTotal=0;
    for(treeNode* current = head; current; current= current->next){
        FruitsTotal += current->value->getFruitsTotal();
    }
    return FruitsTotal;
}
