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

TEST(branchClass, getFruitsTotal) {
    GARDEN_CLASS garden;
    TREE_CLASS tree(&garden,0);
    BRANCH_CLASS branch(&tree,2);
    ASSERT_EQ(branch.getFruitsTotal(),0);
    branch.Growthbranch();
    ASSERT_EQ(branch.getFruitsTotal(),0);
    branch.Growthbranch();
    branch.Growthbranch();
    branch.Growthbranch();
    ASSERT_EQ(branch.getFruitsTotal(),2);
    ASSERT_EQ(branch.getWeightsTotal(),2);
    branch.fadeBranch();
    EXPECT_EQ(branch.getFruitsTotal(),1); 
    EXPECT_EQ(branch.getWeightsTotal(),1); // 1 DLUGOSCI 3 

    branch.Growthbranch(); // 2 0 DLUGOSCI 4 
    branch.Growthbranch(); // 3 1 DLUGOSCI 5
    EXPECT_EQ(branch.getWeightsTotal(),4);

    branch.Growthbranch(); // 4 2 0  DLUGOSCI 6
    branch.Growthbranch(); // 5 3 1  DLUGOSCI 7
    EXPECT_EQ(branch.getWeightsTotal(),9);

    branch.Growthbranch(); // 6 4 2 0  DLUGOSCI 8
    branch.Growthbranch(); // 7 5 3 1  DLUGOSCI 9
    branch.Growthbranch(); // 8 6 4 2 0  DLUGOSCI 10
    EXPECT_EQ(branch.getWeightsTotal(),20);
    branch.harvestBranch(6); // 0 0 4 2 0  DLUGOSCI 10
    EXPECT_EQ(branch.getWeightsTotal(),6);
    ASSERT_EQ(branch.getFruitsTotal(),5);
    branch.harvestBranch(6); // 0 0 4 2 0  DLUGOSCI 10
    branch.cutBranch(6); // 4 2 0  DLUGOSCI 6
    EXPECT_EQ(branch.getWeightsTotal(),6);
    ASSERT_EQ(branch.getFruitsTotal(),5);
}

TEST(TreeClass, getFruitsTotal) {
    GARDEN_CLASS garden;
    TREE_CLASS tree(&garden,0);
    tree.growthTree(); // height 1
    tree.growthTree(); // height 2
    tree.growthTree(); // 0 height 3
    EXPECT_EQ(tree.getBranchesTotal(),1);
    EXPECT_EQ(tree.getFruitsTotal(),0);
    EXPECT_EQ(tree.getWeightsTotal(),0);
    tree.growthTree(); // 1 height 4
    EXPECT_EQ(tree.getWeightsTotal(),0);
    EXPECT_EQ(tree.getFruitsTotal(),0);
    EXPECT_EQ(tree.getWeightsTotal(),0);


    tree.growthTree(); // drzewo 5 ( galaz 2 (owoc 0 ) ) ) ) 
    EXPECT_EQ(tree.getHeight(),5);
    EXPECT_EQ(tree.getFruitsTotal(),1);
    EXPECT_EQ(tree.getHeight(),5);
    EXPECT_EQ(tree.getWeightsTotal(),0);
}