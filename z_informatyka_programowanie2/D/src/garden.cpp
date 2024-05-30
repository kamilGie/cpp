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

void GARDEN_CLASS::plantTree(TREE_CLASS* seed) {
    unsigned int minimalNumber = 0;
    treeNode* current = head;
    treeNode* previous = nullptr;
    while (current && current->value->getNumber() == minimalNumber) {
        minimalNumber++;
        previous = current;
        current = current->next;
    }
    treeNode* newTree =  seed ? new treeNode(new TREE_CLASS( *seed, minimalNumber)) //clone tree 
                              : new treeNode(new TREE_CLASS( this, minimalNumber)); //new tree 
    
    if (!previous) {  // insert begin
        newTree->next = head;
        head = newTree;
    } else {  // insert middle or end
        newTree->next = current;
        previous->next = newTree;
    }
}

void GARDEN_CLASS::ExtractTree(number numberToDalate) {
    treeNode* previous = nullptr;
    for (treeNode* current = head; current; current = current->next) {
        if (current->value->getNumber() == numberToDalate) {
            previous ? previous->next = current->next : head = current->next;
            delete current->value;
            delete current;
            return;
        }
        previous = current;
    }
}

void GARDEN_CLASS::ForEachTree(void (TREE_CLASS::*func)()) {
    for (treeNode* current = head; current; current = current->next) {
        (current->value->*func)();
    }
}

void GARDEN_CLASS::harvestGarden(amount weightToPluck) {
    for (treeNode* current = head; current; current = current->next) {
        current->value->harvestTree(weightToPluck);
    }
}

TREE_CLASS* GARDEN_CLASS::getTreePointer(number numberToFind) {
    for (treeNode* current = head; current; current = current->next) {
        if (current->value->getNumber() == numberToFind) return current->value;
    }
    return nullptr;
}