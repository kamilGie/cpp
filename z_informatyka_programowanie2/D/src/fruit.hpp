// kamil gieras
#pragma once

class BRANCH_CLASS;

class FRUIT_CLASS {
   public:
    FRUIT_CLASS(BRANCH_CLASS* BranchPointer, int positionOnBranch) : positionOnBranch(positionOnBranch), BranchPointer(BranchPointer) {}

    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    unsigned int getWeights();
    unsigned int getLength();
    BRANCH_CLASS* getBranchPointer();

   private:
    int positionOnBranch;
    BRANCH_CLASS* BranchPointer;
    unsigned int fruitWeight = 0;
};