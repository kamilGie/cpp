#include <gtest/gtest.h>
#include "../src/Depot.hpp"

using namespace testing::internal;


TEST(GetCommands,GET_SW){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_SW(1,1,1);
    cut.GET_SW(1,-1,1);
    cut.GET_SW(0,0,0);
    cut.GET_SW(2,0,0);
    cut.GET_SW(1,0,1);
    cut.GET_SW(1,1,2);

    //then
    EXPECT_EQ(GetCapturedStdout(),"20\n" "error\n" "20\n" "error\n" "20\n" "error\n" );
}