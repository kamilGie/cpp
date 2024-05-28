// kamil gieras
#include "garden.hpp"

GARDEN_CLASS::~GARDEN_CLASS() {
    while (head) {
        treeNode* temp = head;
        head = head->next;
        delete temp->value;
        delete temp;
    }
    // while (curentMinNumber) {
    //     MinimumNumberNode* temp = curentMinNumber;
    //     curentMinNumber = curentMinNumber->next;
    //     delete temp;
    // }
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
    tressTotal++;
}

// void GARDEN_CLASS::plantTree() {
//     treeNode* newTree = new treeNode(new TREE_CLASS(this, curentMinNumber->minNumber));

//     if (!curentMinNumber->prevClass) {  // if min number = 0 ;
//         curentMinNumber->prevClass = newTree;
//         newTree->next = head;
//         if (head) {
//             head->prev = newTree;
//         }else{
//             curentMinNumber->minNumber++;
//         }
//         head = newTree;
//     } else if (curentMinNumber->next) {  // if min number its in the middle
//         newTree->next = curentMinNumber->prevClass->next;
//         newTree->prev = curentMinNumber->prevClass;
//         curentMinNumber->prevClass = newTree;
//         newTree->next->prev = newTree;
//         // todo curentMinNumber->next jego prev bedzie nasz nowy tree lub nie xd
//         MinimumNumberNode* temp = curentMinNumber;
//         curentMinNumber = curentMinNumber->next;
//         delete temp;
//     } else {  // if min number its last
//         newTree->prev = curentMinNumber->prevClass;
//         curentMinNumber->prevClass->next = newTree;
//         curentMinNumber->minNumber++;
//         curentMinNumber->prevClass = newTree;
//     }
// }

void GARDEN_CLASS::ExtractTree(number numberToDalate) {
    if (!tressTotal) return;

    for (treeNode* current = head; current; current = current->next) {
        if (current->value->getNumber() == numberToDalate) {
            decreaseWeightsTotal(current->value->getWeightsTotal());
            current->prev ? current->prev->next = current->next : head = current->next;     
            if (current->next) current->next->prev = current->prev;
            delete current->value;
            delete current;
            tressTotal--;
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
