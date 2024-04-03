#include <gtest/gtest.h>
#include "../src/Depot.hpp"

using namespace testing::internal;

TEST(FILLCommands,FILL){
    //for
    Depot cut(5,5,5,5,20);

    //when
    CaptureStdout();
    cut.FILL(2,2,2,2,10);
    cut.GET_E();

    //then
    EXPECT_EQ(GetCapturedStdout(),"260\n");
}



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


//LabelCommands

TEST(LabelCommands,SETandGET_LW){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_LW(0,0,0,0);

    cut.SET_LW(0,0,0,0,12);
    cut.GET_LW(0,0,0,0); 

    cut.SET_LW(1,1,1,1,9);

    cut.SET_LW(1,1,2,1,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "12\n" "error\n" "error\n");
}


TEST(LabelCommands,SETandGET_LH){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_LH(0,0);

    cut.SET_LH(0,0,12);
    cut.GET_LH(0,0); 

    cut.SET_LH(1,1,9);

    cut.SET_LH(1,3,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "12\n" "error\n" "error\n");
}


TEST(LabelCommands,SETandGET_LR){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_LR(0,0);

    cut.SET_LR(0,0,12);
    cut.GET_LR(0,0); 

    cut.SET_LR(1,1,9);

    cut.SET_LR(1,3,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "12\n" "error\n" "error\n");
}


TEST(LabelCommands,SETandGET_LS){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.GET_LS(0);

    cut.SET_LS(0,12);
    cut.GET_LS(0); 

    cut.SET_LS(1,9);

    cut.SET_LS(3,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "12\n" "error\n" "error\n");
}

//Put commands

TEST(PutCommands,PUT_W){
    //for
    Depot cut(2,2,2,2,0);

    //when
    CaptureStdout();

    cut.PUT_W(1,1,1,1,10);
    cut.GET_SW(1,1,1); 

    cut.PUT_W(1,1,1,1,50);
    cut.GET_SW(1,1,1); 

    cut.PUT_W(1,1,1,1,99999);
    cut.GET_SW(1,1,1); 

    cut.PUT_W(1,1,1,2,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"10\n" "60\n" "65535\n" "error\n");
}

TEST(PutCommands,PUT_H){
    //for
    Depot cut(2,2,2,2,0);

    //when
    CaptureStdout();

    cut.PUT_H(1,1,10);
    cut.GET_SH(1); 

    cut.PUT_H(1,1,50);
    cut.GET_SH(1); 

    cut.PUT_H(1,1,99999);
    cut.GET_SH(1); 

    cut.PUT_H(2,1,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"10\n" "60\n" "65535\n" "error\n");
}

TEST(PutCommands,PUT_R){
    //for
    Depot cut(2,2,2,2,0);

    //when
    CaptureStdout();

    cut.PUT_R(1,1,10);
    cut.GET_SR(1); 

    cut.PUT_R(1,1,50);
    cut.GET_SR(1); 

    cut.PUT_R(1,1,99999);
    cut.GET_SR(1); 

    cut.PUT_R(2,1,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"10\n" "60\n" "65535\n" "error\n");
}


// PUT-R s p A - w podręcznym regale składu, na półce o numerze s, do miejsca o numerze p dodaje ilości towaru wynoszącą A.
// PUT-S p A - w podręcznej półce składu, do miejsca o numerze p dodaje ilości towaru wynoszącą A.