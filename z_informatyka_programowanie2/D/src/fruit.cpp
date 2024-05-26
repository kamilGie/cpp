//kamil gieras
#include "fruit.hpp"

unsigned int FRUIT_CLASS::getWeights() {
    return fruitWeight;
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
