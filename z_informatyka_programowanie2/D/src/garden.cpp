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
    treeNode* newTree = new treeNode(new TREE_CLASS(minimalNumber));

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

void GARDEN_CLASS::ExtractTree(unsigned int NumberToDalate) {
    for (treeNode* current = head; current; current = current->next) {
        if (current->value->getNumber() == NumberToDalate) {
            current->prev ? current->prev->next = current->next : head = current->next;     
            if (current->next) current->next->prev = current->prev;
            delete current->value;
            delete current;
            return;
        }
    }
}

unsigned int GARDEN_CLASS::getTressTotal() {
    unsigned int tressTotal = 0;
    for (treeNode* current = head; current; current = current->next) {
        tressTotal++;
    }
    return tressTotal;
}

unsigned int GARDEN_CLASS::getTotal(unsigned int (TREE_CLASS::*func)()) const {
    unsigned int total = 0;
    for (treeNode* current = head; current; current = current->next) {
        total += (current->value->*func)();
    }
    return total;
}
