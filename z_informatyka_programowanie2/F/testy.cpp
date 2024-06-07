#include <gtest/gtest.h>

#include "polynomial.cpp"

using namespace testing::internal;

TEST(OutOfClassOperators, ostream) {
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
    ASSERT_EQ(GetCapturedStdout(), "( 1, 0, 0 )");
}

TEST(polynomial, constructor) {
    POLYNOMIAL polynomial(4, 0, 1, 2, 3, 4);

    CaptureStdout();
    std::cout << polynomial;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 1, 2, 3, 4 )");
}

TEST(polynomial, GreatestCommonDivisor) {
    POLYNOMIAL polynomial1(4, 0, 2, 4, 6, 8);
    POLYNOMIAL polynomial2(2, 4, -6, 8);
    POLYNOMIAL polynomial3(4, 4, 4, 8, 12, 14);

    CaptureStdout();
    std::cout << polynomial1;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 1, 2, 3, 4 )");
    CaptureStdout();
    std::cout << polynomial2;
    EXPECT_EQ(GetCapturedStdout(), "( 2, -3, 4 )");
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

    POLYNOMIAL polynomial3(4, 10, 10, 10, 10, 10);
    polynomial3 = polynomial2;
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 1, 2, 3, 4 )");
}

TEST(polynomial, overloadAdd) {  
    POLYNOMIAL polynomial1(4, 0, 1, 2, 3, 4);
    POLYNOMIAL polynomial2(4, 0, 1, 2, 3, 3);
    POLYNOMIAL polynomial3 = polynomial1 +  polynomial2;
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 2, 4, 6, 7 )");

    POLYNOMIAL polynomial4(2,1,1,100);
    polynomial4+=polynomial3;

    CaptureStdout();
    std::cout << polynomial4;
    EXPECT_EQ(GetCapturedStdout(), "( 1, 3, 104, 6, 7 )");
}

TEST(polynomial, overloadMinus) {  
    POLYNOMIAL polynomial1(4, 0, 1, 2, 3, 4);
    POLYNOMIAL polynomial2(4, 0, 1, 2, 3, 3);
    POLYNOMIAL polynomial3 = polynomial1 - polynomial2;
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 0, 0, 1 )");

    POLYNOMIAL polynomial4(2,1,1,100);
    polynomial4-=polynomial3;

    CaptureStdout();
    std::cout << polynomial4;
    EXPECT_EQ(GetCapturedStdout(), "( 1, 1, 100, 0, -1 )");
}

TEST(polynomial, overloadMultiplication) {  
    POLYNOMIAL polynomial1(4, 0, 1, 2, 3, 4);
    POLYNOMIAL polynomial2(4, 0, 1, 2, 3, 3);
    POLYNOMIAL polynomial3 = polynomial1 * polynomial2;
    CaptureStdout();
    std::cout << polynomial3;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 4, 10, 19, 23, 21, 12 )");

    POLYNOMIAL polynomial4(2,1,1,100);
    polynomial4*=polynomial3;

    CaptureStdout();
    std::cout << polynomial4;
    EXPECT_EQ(GetCapturedStdout(), "( 0, 0, 1, 5, 114, 429, 1042, 1944, 2333, 2112, 1200 ");
}
