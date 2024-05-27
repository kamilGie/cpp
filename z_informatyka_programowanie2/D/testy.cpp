#include <gtest/gtest.h>
#include "src/garden.hpp"

using namespace testing::internal;

TEST(squad_class, squadGeters) {

    ASSERT_EQ(2+3,5);
    ASSERT_EQ(100+5,105);
    ASSERT_EQ(50+50,100);
}

TEST(gardenClass, getTotal_amouth0) {
    GARDEN_CLASS garden;
    ASSERT_EQ(garden.getTressTotal(),0);
    ASSERT_EQ(garden.getBranchesTotal(),0);
    ASSERT_EQ(garden.getFruitsTotal(),0);
    ASSERT_EQ(garden.getWeightsTotal(),0);
}

TEST(gardenClass, plantExtractTree) {
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

TEST(branchClass, Growthbranch) {
    BRANCH_CLASS branch(0);
    ASSERT_EQ(branch.getFruitsTotal(),0);
    branch.Growthbranch();
    branch.Growthbranch();
    branch.Growthbranch();
    branch.Growthbranch();
    ASSERT_EQ(branch.getFruitsTotal(),2);
}