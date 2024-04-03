#include <gtest/gtest.h>
#include "../src/Depot.hpp"

TEST(MyFunctionTest, OutputTest) {
    // Przechwytujemy strumień wyjściowy
    testing::internal::CaptureStdout();

    // Wywołujemy funkcję, która wypisuje dane na ekran
    std::cout<<"Hello, world!\n";

    // Sprawdzamy, czy dane wypisane na ekran są zgodne z oczekiwanymi bezpośrednio wewnątrz asercji
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Hello, world!\n");
}