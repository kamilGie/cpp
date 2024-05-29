// kamil gieras
#include "tree.hpp"

#include "garden.hpp"

TREE_CLASS::TREE_CLASS(GARDEN_CLASS* gardenPointer, amount treeNumber) : gardenPointer(gardenPointer), treeNumber(treeNumber) {
    gardenPointer->increaseTressTotal();
}

TREE_CLASS::TREE_CLASS(const TREE_CLASS& other, number treeNumber)
    : gardenPointer(other.gardenPointer),
      treeNumber(treeNumber),
      height(other.height),
      fruitsTotal(other.fruitsTotal),
      WeightsTotal(other.WeightsTotal),
      totalBranches(other.totalBranches),
      head(nullptr) {
    if (other.head) {
        head = new branchNode(new BRANCH_CLASS(*other.head->value));
        branchNode* current = head;
        branchNode* otherCurrent = other.head->next;
        while (otherCurrent) {
            current->next = new branchNode(new BRANCH_CLASS(*otherCurrent->value));
            current->next->prev = current;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}

TREE_CLASS::~TREE_CLASS() {
    while (head) {
        branchNode* temp = head;
        head = head->next;
        delete temp;
    }
    gardenPointer->decreaseTressTotal();
}

void TREE_CLASS::growthTree() {
    height++;
    bool isLengthFree = true;
    for (branchNode* current = head; current; current = current->next) {
        current->value->Growthbranch();
        if (current->value->getLength() == height) isLengthFree = false;
    }
    if (height % 3 == 0 && isLengthFree) addNewTree();
}

void TREE_CLASS::fadeTree() {
    if (!height) return;
    height--;
    if (head->value->getLength() > height) removeBranchFromTop();
    for (branchNode* current = head; current; current = current->next) {
        current->value->fadeBranch();
    }
}

void TREE_CLASS::addNewTree() {
    branchNode* newBranch = new branchNode(new BRANCH_CLASS(this, height));
    if (head) {
        newBranch->next = head;
        head->prev = newBranch;
    }
    head = newBranch;
}

void TREE_CLASS::removeBranchFromTop() {
    branchNode* temp = head;
    head = head->next;
    delete temp->value;
    delete temp;
}

void TREE_CLASS::decreaseWeightsTotal(amount ValToDecrease) {
    gardenPointer->decreaseWeightsTotal(ValToDecrease);
    WeightsTotal -= ValToDecrease;
}

void TREE_CLASS::increaseWeightsTotal(amount ValToIncrease) {
    gardenPointer->increaseWeightsTotal(ValToIncrease);
    WeightsTotal += ValToIncrease;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(amount branchHeigth) {
    for (branchNode* current = head; current; current = current->next) {
        if (current->value->getLength() == branchHeigth) return current->value;
    }
    return nullptr;
}

void TREE_CLASS::decreaseFruitsTotal() {
    gardenPointer->decreaseFruitsTotal();
    fruitsTotal--;
}

void TREE_CLASS::increaseBranchesTotal() {
    gardenPointer->increaseBranchesTotal();
    totalBranches++;
}

void TREE_CLASS::decreaseBranchesTotal() {
    gardenPointer->decreaseBranchesTotal();
    totalBranches--;
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* cloningBranch) {
    branchNode* cloneDir = nullptr;
    for (branchNode* current = head; current; current = current->next) {
        if (current->value->getLength() == 0) cloneDir = current;
    }
    if (cloneDir) {
        delete cloneDir->value;
        cloneDir->value = new BRANCH_CLASS(*cloningBranch);
    }
}

void TREE_CLASS::cutTree(amount newHeigth) {
    height = newHeigth;
    for (branchNode* current = head; current && current->value->getHeight() < height; current = current->next) {
        removeBranchFromTop();
    }
}

void TREE_CLASS::harvestTree(amount weightToPluck) {
    for (branchNode* current = head; current; current = current->next) {
        current->value->harvestBranch(weightToPluck);
    }
}

void TREE_CLASS::increaseFruitsTotal(amount ValToIncrease) {
    gardenPointer->increaseFruitsTotal(ValToIncrease);
    fruitsTotal += ValToIncrease;
}
