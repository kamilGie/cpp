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
    unsigned int minimalNumber = 0;
    treeNode* current = head;
    treeNode* previous = nullptr;
    while (current && current->value->getNumber() == minimalNumber) {
        minimalNumber++;
        previous = current;
        current = current->next;
    }
    treeNode* newTree = new treeNode(new TREE_CLASS(this,minimalNumber));

    if (!previous) {  // insert begin
        newTree->next = head;
        if (head) head->prev = newTree;
        head = newTree;
    } else {  // insert middle or end
        newTree->next = current;
        newTree->prev = previous;
        previous->next = newTree;
        if (current) current->prev = newTree;
    }
}

void GARDEN_CLASS::growthGarden() {
    for (treeNode* current = head; current; current = current->next) {
        current->value->growthTree();
    }
}

void GARDEN_CLASS::cloneTree(TREE_CLASS* treeToClone) {
    unsigned int minimalNumber = 0;
    treeNode* current = head;
    treeNode* previous = nullptr;
    while (current && current->value->getNumber() == minimalNumber) {
        minimalNumber++;
        previous = current;
        current = current->next;
    }
    treeNode* newTree = new treeNode(new TREE_CLASS(*treeToClone,minimalNumber));

    if (!previous) {  // insert begin
        newTree->next = head;
        if (head) head->prev = newTree;
        head = newTree;
    } else {  // insert middle or end
        newTree->next = current;
        newTree->prev = previous;
        previous->next = newTree;
        if (current) current->prev = newTree;
    }
}

void GARDEN_CLASS::harvestGarden(amount weightToPluck) {
    for (treeNode* current = head; current; current = current->next) {
        current->value->harvestTree(weightToPluck);
    }
}

void GARDEN_CLASS::fadeGarden() {
    for (treeNode* current = head; current; current = current->next) {
        current->value->fadeTree();
    }
}

void GARDEN_CLASS::ExtractTree(number numberToDalate) {
    if (!tressTotal) return;

    for (treeNode* current = head; current; current = current->next) {
        if (current->value->getNumber() == numberToDalate) {
            decreaseWeightsTotal(current->value->getWeightsTotal());
            current->prev ? current->prev->next = current->next : head = current->next;     
            if (current->next) current->next->prev = current->prev;
            delete current->value;
            delete current;
            return;
        }
    }
}

TREE_CLASS* GARDEN_CLASS::getTreePointer(number numberToFind) {
    for (treeNode* current = head; current; current = current->next) {
         if (current->value->getNumber() == numberToFind) return current->value;
    }
    return nullptr;
}
