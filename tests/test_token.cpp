#include <gtest/gtest.h>
#include "../src/headers/lexer.h"
#include "../src/headers/token.h"

// Test to verify valid token creation
TEST(TokenTest, ValidConstructorTest) {
    const Token t(TokenType::NOT, std::string("!"));

    EXPECT_EQ(t.getType(), TokenType::NOT);
    EXPECT_EQ(t.getValue(), "!");
}

// Test to verify the default constructor initializes correctly
TEST(TokenTest, DefaultConstructorTest) {
    EXPECT_THROW({
        Token t;
    }, std::invalid_argument);
}

// Test to verify the getters return the expected values
TEST(TokenTest, GettersTest) {
    const Token t(TokenType::LET_KW, std::string("let"));

    EXPECT_EQ(t.getType(), TokenType::LET_KW);
    EXPECT_EQ(t.getValue(), "let");
}

// Test to verify span initialization (this requires an actual range)
TEST(TokenTest, SpanInitializationTest) {
    size_t arr[] = {0, 1, 2};
    const std::span<size_t> sp(arr, 3);
    const Token t(TokenType::LET_KW, "let", sp);

    EXPECT_EQ(t.span.size(), 3);
}

// Test for checking string representation
TEST(TokenTest, ToStringTest) {
    const Token t(TokenType::LET_KW, "let");

    EXPECT_EQ(t.toString(), "Token(1, let)");
}

// Test for empty string value handling
TEST(TokenTest, EmptyStringValueTest) {
    EXPECT_THROW({
        Token t(TokenType::LET_KW, "");
    }, std::invalid_argument);
}

// Test to verify that an exception is thrown for invalid TokenType
TEST(TokenTest, InvalidTokenTypeTest) {
    EXPECT_THROW({
        Token t(static_cast<TokenType>(-1), "invalid");
    }, std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}