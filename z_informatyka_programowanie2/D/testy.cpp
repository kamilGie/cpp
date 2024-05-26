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

TEST(gardenClass, getTressTotal) {
    GARDEN_CLASS garden;
    garden.plantTree();
    garden.plantTree();
    ASSERT_EQ(garden.getTressTotal(),2);
}