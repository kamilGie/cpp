#include <gtest/gtest.h>
#include "../src/Depot.hpp"

using namespace testing::internal;

TEST(GetCommands,GET_E){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_E();

    //then
    EXPECT_EQ(GetCapturedStdout(),"260\n");
}


TEST(GetCommands,GET_W){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_W(1);
    cut.GET_W(-1);
    cut.GET_W(0);
    cut.GET_W(2);

    //then
    EXPECT_EQ(GetCapturedStdout(),"100\n" "error\n" "100\n" "error\n");
}


TEST(GetCommands,GET_RW){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_RW(1,1);
    cut.GET_RW(-1,0);
    cut.GET_RW(0,0);
    cut.GET_RW(0,2);

    //then
    EXPECT_EQ(GetCapturedStdout(),"40\n" "error\n" "40\n" "error\n");
}


TEST(GetCommands,GET_RH){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_RH();

    //then
    EXPECT_EQ(GetCapturedStdout(),"40\n" );
}


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


TEST(GetCommands,GET_SH){
    //for
    Depot cut(2,2,2,2,10);


    //when
    CaptureStdout();
    cut.GET_SH(1);
    cut.GET_SH(-1);
    cut.GET_SH(0);
    cut.GET_SH(2);

    //then
    EXPECT_EQ(GetCapturedStdout(),"20\n" "error\n" "20\n" "error\n");
}

TEST(GetCommands,GET_SR){
    //for
    Depot cut(2,2,2,2,10);


    //when
    CaptureStdout();
    cut.GET_SR(1);
    cut.GET_SR(-1);
    cut.GET_SR(0);
    cut.GET_SR(2);

    //then
    EXPECT_EQ(GetCapturedStdout(),"20\n" "error\n" "20\n" "error\n");
}

TEST(GetCommands,GET_S){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_S();

    //then
    EXPECT_EQ(GetCapturedStdout(),"20\n" );
}