#include <gtest/gtest.h>
#include "../src/Depot.hpp"

using namespace testing::internal;
//    CaptureStdout();
//    GetCapturedStdout()

TEST(GetCommands,GET_SW){
    //for
    Depot cut(2,2,2,2,10);

    //when
    size_t res = cut.GET_SW(1,1,1);

    //then
    EXPECT_EQ(res,20);
}