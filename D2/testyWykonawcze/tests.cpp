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


TEST(FILLCommands,FILL_error){
    //for
    Depot cut;

    //when
    CaptureStdout();

    cut.FILL(1,1,1,130,1);

    cut.FILL(1,1,1,1,65536);

    cut.FILL(1,1,0,1,1);

    cut.FILL(2,2,1,1,-1);

    //then
    EXPECT_EQ(GetCapturedStdout(),"error\n" "error\n" "error\n" "error\n");
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

TEST(PutCommands,PUT_S){
    //for
    Depot cut(2,2,2,2,0);

    //when
    CaptureStdout();

    cut.PUT_S(1,10);
    cut.GET_S(); 

    cut.PUT_S(1,0);
    cut.GET_S(); 

    cut.PUT_S(1,99999);
    cut.GET_S(); 

    cut.PUT_S(2,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"10\n" "10\n" "65535\n" "error\n");
}

//Pop commands

TEST(PopCommands,POP_W){
    //for
    Depot cut(2,2,2,2,100);

    //when
    CaptureStdout();

    cut.POP_W(1,1,1,1,10);
    cut.GET_SW(1,1,1); 

    cut.POP_W(1,1,1,1,99999);
    cut.GET_SW(1,1,1); 

    cut.POP_W(1,1,1,2,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"190\n" "100\n" "error\n");
}

TEST(PopCommands,POP_H){
    //for
    Depot cut(2,2,2,2,100);

    //when
    CaptureStdout();

    cut.POP_H(1,1,10);
    cut.GET_SH(1); 

    cut.POP_H(1,1,99999);
    cut.GET_SH(1); 

    cut.POP_H(2,1,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"190\n" "100\n" "error\n");
}

TEST(PopCommands,POP_R){
    //for
    Depot cut(2,2,2,2,100);

    //when
    CaptureStdout();

    cut.POP_R(1,1,10);
    cut.GET_SR(1); 

    cut.POP_R(1,1,99999);
    cut.GET_SR(1); 

    cut.POP_R(2,1,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"190\n" "100\n" "error\n");
}

TEST(PopCommands,POP_S){
    //for
    Depot cut(2,2,2,2,100);

    //when
    CaptureStdout();

    cut.POP_S(1,10);
    cut.GET_S(); 

    cut.POP_S(1,99999);
    cut.GET_S(); 

    cut.POP_S(2,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"190\n" "100\n" "error\n");
}



//Mov Commands

TEST(MovCommands,MOV_W){
    //for
    Depot cut(2,2,2,1,100);

    //when
    CaptureStdout();

    cut.MOV_W(1,0,0, 0,0,0, 0,10);
    cut.GET_SW(0,0,0); 

    cut.MOV_W(0,0,0, 1,0,0, 0,200);
    cut.GET_SW(0,0,0); 


    cut.MOV_W(0,0,0, 1,0,0, 0,300);
    cut.GET_SW(0,0,0); 

    cut.MOV_W(0,0,0,9,0,0,0,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"110\n" "0\n" "0\n" "error\n");
}

TEST(MovCommands,MOV_H){
    //for
    Depot cut(2,2,2,1,100);

    //when
    CaptureStdout();

    cut.MOV_H(0,0,0,0,10);
    cut.GET_SW(0,0,0); 

    cut.MOV_H(0,0,0, 0,200);
    cut.GET_SW(0,0,0); 

    cut.MOV_H(0,0,0,9,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"90\n" "0\n" "error\n");
}

TEST(MovCommands,MOV_R){
    //for
    Depot cut(2,2,2,1,65530);

    //when
    CaptureStdout();

    cut.MOV_R(0,0,0,0,0,10);
    cut.GET_SW(0,0,0); 

    cut.MOV_R(0,0,0, 0,0,65535);
    cut.GET_SW(0,0,0); 

    cut.MOV_R(0,0,0,9,0,10);

    //then
    EXPECT_EQ(GetCapturedStdout(),"65525\n" "65525\n" "error\n");
}



//Set Commands

TEST(SetCommands,SET_AP_AddingNew){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AP(0,0,0,10);
    cut.GET_LW(0,0,0,9);
    cut.GET_SW(0,0,0);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "20\n");
}

TEST(SetCommands,SET_AP_Deleting){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AP(0,0,0,1);
    cut.GET_LW(0,0,0,1);
    cut.GET_SW(0,0,0);

    //then
    EXPECT_EQ(GetCapturedStdout(),"error\n" "10\n");
}

TEST(SetCommands,SET_AP_Error){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AP(0,2,0,1);
    cut.SET_AP(0,0,0,-1);


    //then
    EXPECT_EQ(GetCapturedStdout(),"error\n" "error\n");
}


TEST(SetCommands,SET_AS_AddingNew){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AS(0,0,5,10);
    cut.GET_LW(0,0,4,9);
    cut.GET_SW(0,0,4);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "0\n");
}

TEST(SetCommands,SET_AS_Deleting){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AS(0,0,1,1);
    cut.GET_LW(0,0,1,0);
    cut.GET_SW(0,0,0);

    //then
    EXPECT_EQ(GetCapturedStdout(),"error\n" "10\n");
}

TEST(SetCommands,SET_AS_Error){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AS(0,2,0,1);

    cut.SET_AS(0,0,0,0);
    cut.GET_SW(0,0,0);


    //then
    EXPECT_EQ(GetCapturedStdout(),"error\n" "error\n");
}


TEST(SetCommands,SET_AR){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AR(0,5,5,10);
    cut.GET_LW(0,4,0,0);
    cut.GET_SW(0,4,0);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "0\n");
}

TEST(SetCommands,SET_AW){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_AW(5,1,1,1);
    cut.GET_LW(4,0,0,0);
    cut.GET_SW(4,0,0);

    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "0\n");
}

TEST(SetCommands,SET_HW){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_HW(1,5);
    cut.GET_LH(1,4);
    cut.GET_SH(1);


    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "20\n");
}

TEST(SetCommands,SET_HR){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_HR(5,5);
    cut.GET_LR(4,4);
    cut.GET_SR(4);


    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "0\n");
}


TEST(SetCommands,SET_HS){
    //for
    Depot cut(2,2,2,2,10);

    //when
    CaptureStdout();
    cut.SET_HS(5);
    cut.GET_LS(4);
    cut.GET_S();


    //then
    EXPECT_EQ(GetCapturedStdout(),"--\n" "20\n");
}







