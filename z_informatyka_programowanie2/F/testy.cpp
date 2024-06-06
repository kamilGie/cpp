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