#include <gtest/gtest.h>
#include "src/garden.hpp"

using namespace testing::internal;

TEST(squad_class, squadGeters) {

    ASSERT_EQ(2+3,5);
    ASSERT_EQ(100+5,105);
    ASSERT_EQ(50+50,100);
}

TEST(gardenClass, getTotal_amount0) {
    GARDEN_CLASS garden;
    ASSERT_EQ(garden.getTressTotal(),0);
    ASSERT_EQ(garden.getBranchesTotal(),0);
    ASSERT_EQ(garden.getFruitsTotal(),0);
    ASSERT_EQ(garden.getWeightsTotal(),0);
}

TEST(gardenClass, plantExtractTree_getTotal) {
    GARDEN_CLASS garden;

    garden.plantTree();
    garden.plantTree();
    garden.plantTree();
    ASSERT_EQ(garden.getTressTotal(),3);

    garden.ExtractTree(2);
    garden.ExtractTree(1);
    ASSERT_EQ(garden.getTressTotal(),1);

    garden.ExtractTree(0);
    garden.ExtractTree(0);
    ASSERT_EQ(garden.getTressTotal(),0);
}

TEST(gardenClass, plantExtractTree_getGoodNumbers) {
    GARDEN_CLASS garden;

    garden.plantTree();
    garden.plantTree();
    garden.plantTree();
    garden.plantTree();
    garden.plantTree();
    garden.ExtractTree(0);
    garden.ExtractTree(4);
    ASSERT_EQ(garden.getTressTotal(),3);
    ASSERT_FALSE( garden.getTreePointer(5));
    ASSERT_FALSE( garden.getTreePointer(4));
    ASSERT_TRUE( garden.getTreePointer(3));
    ASSERT_TRUE( garden.getTreePointer(2));
    ASSERT_TRUE( garden.getTreePointer(1));
    ASSERT_FALSE( garden.getTreePointer(0));
    garden.plantTree();
    garden.plantTree();
    ASSERT_TRUE( garden.getTreePointer(0));
    ASSERT_TRUE( garden.getTreePointer(4));

    garden.ExtractTree(0);
    garden.ExtractTree(2);
    garden.ExtractTree(4);
    garden.plantTree();
    ASSERT_FALSE( garden.getTreePointer(4));
    ASSERT_TRUE( garden.getTreePointer(3));
    ASSERT_FALSE( garden.getTreePointer(2));
    ASSERT_TRUE( garden.getTreePointer(1));
    ASSERT_TRUE( garden.getTreePointer(0));
}

TEST(branchClass, Growthbranch) {
    GARDEN_CLASS garden;
    TREE_CLASS tree(&garden,0);
    BRANCH_CLASS branch(&tree,2);
    ASSERT_EQ(branch.getFruitsTotal(),0);
    branch.Growthbranch();
    branch.Growthbranch();
    branch.Growthbranch();
    branch.Growthbranch();
    ASSERT_EQ(branch.getFruitsTotal(),2);
}