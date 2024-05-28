// kamil gieras
#pragma once

class BRANCH_CLASS;

class FRUIT_CLASS {
   public:
    FRUIT_CLASS(BRANCH_CLASS* BranchPointer, unsigned int length) : BranchPointer(BranchPointer), length(length) {}

    unsigned int getLength() { return length; }
    unsigned int getWeight() { return fruitWeight; }
    BRANCH_CLASS* getBranchPointer() { return BranchPointer; }

    void fadeFruit();
    void pluckFruit();
    void growthFruit();

   private:
    BRANCH_CLASS* BranchPointer;
    
    unsigned int length;
    unsigned int fruitWeight = 0;
};