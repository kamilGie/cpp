// kamil gieras
#include "tree.hpp"
#include "garden.hpp"

TREE_CLASS::~TREE_CLASS() {
    while (head) {
        branchNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void TREE_CLASS::decreaseWeightsTotal(unsigned int ValToDecrease) {
    gardenPointer->decreaseWeightsTotal(ValToDecrease);
    WeightsTotal-=ValToDecrease;
}

void TREE_CLASS::increaseWeightsTotal(unsigned int ValToIncrease) {
    gardenPointer->increaseWeightsTotal(ValToIncrease);
    WeightsTotal-=ValToIncrease;
}
