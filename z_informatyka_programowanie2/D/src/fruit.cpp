//kamil gieras
#include "fruit.hpp"

unsigned int FRUIT_CLASS::getWeights() {
    return fruitWeight;
}

unsigned int FRUIT_CLASS::getLength() {
    return length;
}

void FRUIT_CLASS::growthFruit() {
    fruitWeight++;
}

void FRUIT_CLASS::fadeFruit() {
    fruitWeight--;
}

void FRUIT_CLASS::pluckFruit() {
    fruitWeight=0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer() {
    return BranchPointer;
}
