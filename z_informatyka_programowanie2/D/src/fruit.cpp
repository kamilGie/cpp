// kamil gieras
#include "fruit.hpp"

#include "branch.hpp"

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* BranchPointer, amount length)  : BranchPointer(BranchPointer), length(length) {
    BranchPointer->increaseFruitsTotal();
}

FRUIT_CLASS::~FRUIT_CLASS() {
    BranchPointer->decreaseFruitsTotal();
    BranchPointer->decreaseWeightsTotal(fruitWeight);
}

void FRUIT_CLASS::growthFruit() {
    BranchPointer->increaseWeightsTotal(1);
    fruitWeight++;
}

void FRUIT_CLASS::fadeFruit() {
    BranchPointer->decreaseWeightsTotal(1);
    fruitWeight--;
}

void FRUIT_CLASS::pluckFruit() {
    BranchPointer->decreaseWeightsTotal(fruitWeight);
    fruitWeight = 0;
}
