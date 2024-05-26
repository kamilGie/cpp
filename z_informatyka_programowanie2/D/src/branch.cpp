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
