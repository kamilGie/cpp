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
    treeNode* newTree = new treeNode(new TREE_CLASS(getMinAvibleNumber()));
    if (head) {
        newTree->next = head;
        head->prev = newTree;
    }
    head = newTree;
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
            return;
        }
    }
}
   
unsigned int GARDEN_CLASS::getTressTotal() {
    unsigned int tressTotal=0;
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
