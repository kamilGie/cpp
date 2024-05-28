// kamil gieras
#include "fruit.hpp"

#include "branch.hpp"

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
