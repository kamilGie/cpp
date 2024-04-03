#include <gtest/gtest.h>
#include "../src/Depot.hpp"

using namespace testing::internal;

TEST(GetCommands,GET_SW){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_SW(1,1,1);

    //then
    EXPECT_EQ(GetCapturedStdout(),"10\n");
}