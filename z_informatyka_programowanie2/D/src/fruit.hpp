// kamil gieras
#pragma once

class BRANCH_CLASS;

class FRUIT_CLASS {
   public:
    FRUIT_CLASS(BRANCH_CLASS* BranchPointer, unsigned int length) : length(length), BranchPointer(BranchPointer) {}

    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    unsigned int getWeights();
    unsigned int getLength();
    BRANCH_CLASS* getBranchPointer();

   private:
    unsigned int length;
    BRANCH_CLASS* BranchPointer;
    unsigned int fruitWeight = 0;
};