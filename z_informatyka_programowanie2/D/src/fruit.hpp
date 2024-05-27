// kamil gieras
#pragma once

class BRANCH_CLASS;

class FRUIT_CLASS {
   public:
    FRUIT_CLASS(BRANCH_CLASS* BranchPointer, unsigned int length) : BranchPointer(BranchPointer), length(length) {}

    void growthFruit() { ++fruitWeight; }
    void fadeFruit() { --fruitWeight; }
    void pluckFruit() { fruitWeight = 0; }
    unsigned int getWeights() { return fruitWeight; }
    unsigned int getLength() { return length; }
    BRANCH_CLASS* getBranchPointer() { return BranchPointer; }

   private:
    BRANCH_CLASS* BranchPointer;
    unsigned int length;
    unsigned int fruitWeight = 0;
};