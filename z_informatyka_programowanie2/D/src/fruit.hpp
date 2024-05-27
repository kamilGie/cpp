// kamil gieras
#pragma once

class BRANCH_CLASS;

class FRUIT_CLASS {
   public:
    FRUIT_CLASS(BRANCH_CLASS* BranchPointer, unsigned int length) :  BranchPointer(BranchPointer),length(length) {}

    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    unsigned int getWeights();
    unsigned int getLength();
    BRANCH_CLASS* getBranchPointer();

   private:
    BRANCH_CLASS* BranchPointer;
    unsigned int length;
    unsigned int fruitWeight = 0;
};