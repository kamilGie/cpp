// kamil gieras
#pragma once

class BRANCH_CLASS;
typedef unsigned int amount;

class FRUIT_CLASS {
   public:
    FRUIT_CLASS(BRANCH_CLASS* BranchPointer, amount length) : BranchPointer(BranchPointer), length(length) {}
    ~FRUIT_CLASS();

    amount getLength() { return length; }
    amount getWeight() { return fruitWeight; }
    BRANCH_CLASS* getBranchPointer() { return BranchPointer; }

    void fadeFruit();
    void pluckFruit();
    void growthFruit();

   private:
    BRANCH_CLASS* BranchPointer;

    amount length;
    amount fruitWeight = 0;
};