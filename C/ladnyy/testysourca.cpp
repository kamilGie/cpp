#include <gtest/gtest.h>
#include "source.cpp"

TEST(TestPokazowy, helloTest) {
    int data[20];
    data[0] = -1;
    Add(3, data);
    Add(2, data);
    Add(1, data);
}

TEST(CreateTest, BasicTest) {
    int inputArray[] = {1, 2, 3, 4, 5,-1};
    int result[5]={-1};
    Create(5, inputArray, result);

    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(inputArray[i], result[i]);
    }
}

TEST(AddTest, BasicTest) {
    int data[20] = {-1};
    Add(3, data);
    ASSERT_EQ(data[0], 3);
}

TEST(UnionTest, BasicTest) {
    int setA[] = {1, 2, 3,-1};
    int setB[] = {3, 4, 5,-1};
    int result[6]={-1};

    Union(setA, setB, result);

    ASSERT_TRUE(std::find(std::begin(result), std::end(result), 1) != std::end(result));
    ASSERT_TRUE(std::find(std::begin(result), std::end(result), 2) != std::end(result));
    ASSERT_TRUE(std::find(std::begin(result), std::end(result), 3) != std::end(result));
    ASSERT_TRUE(std::find(std::begin(result), std::end(result), 4) != std::end(result));
    ASSERT_TRUE(std::find(std::begin(result), std::end(result), 5) != std::end(result));
}

TEST(EqualTest, BasicTest) {
    int setA[] = {1, 2, 3,-1};
    int setB[] = {1, 2, 3,-1};
    ASSERT_TRUE(Equal(setA, setB));

    int setC[] = {1, 2, 4,-1};
    ASSERT_FALSE(Equal(setA, setC));
}

TEST(EmptyTest, BasicTest) {
    int setA[] = {1, 2, 3,-1};
    ASSERT_FALSE(Empty(setA));

    int setB[20] = {-1}; // Zbiór pusty
    ASSERT_TRUE(Empty(setB));
}

TEST(NonemptyTest, BasicTest) {
    int setA[] = {1, 2, 3,-1};
    ASSERT_TRUE(Nonempty(setA));

    int setB[20] = {-1}; // Zbiór pusty
    ASSERT_FALSE(Nonempty(setB));
}

TEST(ArithmeticTest, BasicTest) {
    int setA[] = {1, 2, 3,-1};
    ASSERT_EQ(Arithmetic(setA), 2.0);

    int setB[20] = {-1}; // Zbiór pusty
    ASSERT_EQ(Arithmetic(setB), 0.0);
}


TEST(ElementTest, BasicTest) {
    int setA[] = {1, 2, 3,-1};
    ASSERT_TRUE(Element(1, setA));
    ASSERT_FALSE(Element(4, setA));
}

TEST(CardinalityTest, BasicTest) {
    int setA[] = {1, 2, 3,-1};
    int card;
    Cardinality(setA, &card);
    ASSERT_EQ(card, 3);

    int setB[20] = {-1}; 
    Cardinality(setB, &card);
    ASSERT_EQ(card, 0);
}