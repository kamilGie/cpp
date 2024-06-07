#include <gtest/gtest.h>
#include "cstdarg"
#include "iostream"
using namespace std;
#include "polynomial.cpp"

using namespace testing::internal;

TEST(OutOfClassOperators, ostreamMethods) {
    POLYNOMIAL polynomial;
    std::istringstream input_stream("4 1 0 -5 0 3   2 1 0 0");
    std::cin.rdbuf(input_stream.rdbuf());

    std::cin >> polynomial;
    CaptureStdout();
    std::cout << polynomial;
    ASSERT_EQ(GetCapturedStdout(), "( 1, 0, -5, 0, 3 )");

    std::cin >> polynomial;
    CaptureStdout();
    std::cout << polynomial;
    ASSERT_EQ(GetCapturedStdout(), "( 1 )");
}

TEST(polynomial, constructor) {
    POLYNOMIAL polynomial(4, 0, 1, 2, 3, 4);
    CaptureStdout();
    std::cout << polynomial;
    ASSERT_EQ(GetCapturedStdout(), "( 0, 1, 2, 3, 4 )");
}

TEST(polynomial, GreatestCommonDivisor) {
    POLYNOMIAL polynomial1(4, 0, 2, 4, 6, 8);
    CaptureStdout();
    std::cout << polynomial1;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 1, 2, 3, 4 )");

    POLYNOMIAL polynomial2(2, 4, -6, 8);
    CaptureStdout();
    std::cout << polynomial2;
    EXPECT_EQ(GetCapturedStdout(), "( 2, -3, 4 )");

    POLYNOMIAL polynomial3(4, 4, 4, 8, 12, 14);
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 2, 2, 4, 6, 7 )");
}

TEST(polynomial, overloadEquals) {
    POLYNOMIAL polynomial1(4, 0, 1, 2, 3, 4);
    POLYNOMIAL polynomial2 = polynomial1;
    CaptureStdout();
    std::cout << polynomial2;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 1, 2, 3, 4 )");

    POLYNOMIAL polynomial3(1, 404, 404);
    polynomial3 = polynomial2;
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 1, 2, 3, 4 )");
}

TEST(polynomial, overloadAdd) {
    POLYNOMIAL polynomial3 = POLYNOMIAL(4, 0, 1, 2, 3, 4) + POLYNOMIAL(4, 0, 1, 2, 3, 3);
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 2, 4, 6, 7 )");

    POLYNOMIAL polynomial4(2, 1, 1, 100);
    polynomial4 += polynomial3;
    CaptureStdout();
    std::cout << polynomial4;
    EXPECT_EQ(GetCapturedStdout(), "( 1, 3, 104, 6, 7 )");
}

TEST(polynomial, overloadMinus) {
    POLYNOMIAL polynomial3 = POLYNOMIAL(4, 0, 1, 2, 3, 4) - POLYNOMIAL(4, 0, 1, 2, 3, 3);
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 0, 0, 1 )");

    POLYNOMIAL polynomial4(2, 1, 1, 100);
    polynomial4 -= polynomial3;
    CaptureStdout();
    std::cout << polynomial4;
    EXPECT_EQ(GetCapturedStdout(), "( 1, 1, 100, 0, -1 )");
}

TEST(polynomial, overloadMultiplication) {
    POLYNOMIAL polynomial3 = POLYNOMIAL(4, 0, 1, 2, 3, 4) * POLYNOMIAL(4, 0, 1, 2, 3, 3);
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 4, 10, 19, 23, 21, 12 )");

    POLYNOMIAL polynomial4(2, 1, 1, 100);
    polynomial4 *= polynomial3;
    CaptureStdout();
    std::cout << polynomial4;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 5, 114, 429, 1042, 1944, 2333, 2112, 1200 )");
}

// TEST(polynomial, overloadDivision) {
//     POLYNOMIAL polynomial3 = POLYNOMIAL(4, 0, 1, 2, 3, 4) / POLYNOMIAL(4, 0, 1, 2, 3, 4);
//     CaptureStdout();
//     std::cout << polynomial3;
//     EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 4, 10, 19, 23, 21, 12 )");

//     POLYNOMIAL polynomial4(2,1,1,100);
//     polynomial4/=polynomial3;
//     CaptureStdout();
//     std::cout << polynomial4;
//     EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 5, 114, 429, 1042, 1944, 2333, 2112, 1200 )");
// }

// TEST(polynomial, overloadResFromDivision) {
//     POLYNOMIAL polynomial3 = POLYNOMIAL(4, 0, 1, 2, 3, 4) % POLYNOMIAL(4, 0, 1, 2, 3, 4);
//     CaptureStdout();
//     std::cout << polynomial3;
//     EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 4, 10, 19, 23, 21, 12 )");

//     POLYNOMIAL polynomial4(2,1,1,100);
//     polynomial4%=polynomial3;
//     CaptureStdout();
//     std::cout << polynomial4;
//     EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 5, 114, 429, 1042, 1944, 2333, 2112, 1200 )");
// }

TEST(polynomial, overloadBitOperators) {
    POLYNOMIAL p(3, 1, 3, 4, -1);
    CaptureStdout();
    std::cout << (p << 1);
    EXPECT_EQ(GetCapturedStdout(), "( 3, 4, -1 )");

    POLYNOMIAL q(2, 6, 8, -7);
    CaptureStdout();
    std::cout << (q >> 2);
    EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 6, 8, -7 )");
}

TEST(polynomial, overloadIncremenAndDecrement) {
    POLYNOMIAL p(3, 1, 3, 4, -1);
    POLYNOMIAL q(2, 6, 8, -7);

    q = ++p;

    CaptureStdout();
    std::cout << p;
    EXPECT_EQ(GetCapturedStdout(), "( 2, 4, 5 )");

    CaptureStdout();
    std::cout << q;
    EXPECT_EQ(GetCapturedStdout(), "( 2, 4, 5 )");

    p = q--;

    CaptureStdout();
    std::cout << p;
    EXPECT_EQ(GetCapturedStdout(), "( 2, 4, 5 )");

    CaptureStdout();
    std::cout << q;
    EXPECT_EQ(GetCapturedStdout(), "( 1, 3, 4 )");
}

TEST(polynomial, overloadNewAndDelete) {
    CaptureStdout();

    std::cout << POLYNOMIAL::overloaded;
    POLYNOMIAL* polyPTR = new POLYNOMIAL;
    std::cout << POLYNOMIAL::overloaded;
    delete polyPTR;
    std::cout << POLYNOMIAL::overloaded;

    EXPECT_EQ(GetCapturedStdout(), "010");
}


TEST(globalOverload, bigger) {
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)<POLYNOMIAL(3,1,1,1,1));
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)<POLYNOMIAL(2,2,1,1));
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)<POLYNOMIAL(2,1,1,2));
    EXPECT_FALSE(POLYNOMIAL(2,1,2,1)<POLYNOMIAL(2,1,1,1));
}

TEST(globalOverload, biggerOrEquals) {
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)<=POLYNOMIAL(2,1,1,1));
    EXPECT_TRUE(POLYNOMIAL(0,1)<=POLYNOMIAL(0,1));
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)<=POLYNOMIAL(2,1,1,2));
    EXPECT_FALSE(POLYNOMIAL(2,1,2,1)<=POLYNOMIAL(2,1,1,1));
}

TEST(globalOverload, Equals) {
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)==POLYNOMIAL(2,1,1,1));
    EXPECT_TRUE(POLYNOMIAL(0,1)==POLYNOMIAL(0,3)); // they reduce
    EXPECT_TRUE(POLYNOMIAL(3,1,1,1,0)==POLYNOMIAL(2,1,1,1));
    EXPECT_FALSE(POLYNOMIAL(2,1,2,1)==POLYNOMIAL(2,1,1,1));
}

TEST(globalOverload, NotEquals) {
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)!=POLYNOMIAL(2,1,2,1));
    EXPECT_TRUE(POLYNOMIAL(1,1,1)!=POLYNOMIAL(0,2));
    EXPECT_TRUE(POLYNOMIAL(3,1,1,1,1)!=POLYNOMIAL(2,1,1,1));
    EXPECT_FALSE(POLYNOMIAL(2,1,1,1)!=POLYNOMIAL(2,1,1,1));
}

TEST(globalOverload, smaller) {
    EXPECT_TRUE(POLYNOMIAL(3,1,1,1,1)>POLYNOMIAL(2,1,1,1));
    EXPECT_TRUE(POLYNOMIAL(2,2,1,1)>POLYNOMIAL(2,1,1,1));
    EXPECT_TRUE(POLYNOMIAL(2,1,1,2)>POLYNOMIAL(2,1,1,1));
    EXPECT_FALSE(POLYNOMIAL(2,1,1,1)>POLYNOMIAL(2,1,2,1));
}

TEST(globalOverload, smallerOrEquals) {
    EXPECT_TRUE(POLYNOMIAL(2,1,1,1)>=POLYNOMIAL(2,1,1,1));
    EXPECT_TRUE(POLYNOMIAL(0,1)>=POLYNOMIAL(0,1));
    EXPECT_TRUE(POLYNOMIAL(2,1,1,2)>=POLYNOMIAL(2,1,1,1));
    EXPECT_FALSE(POLYNOMIAL(2,1,1,1)>=POLYNOMIAL(2,1,2,1));
}