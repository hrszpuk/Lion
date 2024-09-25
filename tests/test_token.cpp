#include <gtest/gtest.h>
#include "../src/headers/lexer.h"
#include "../src/headers/token.h"

// Test to verify valid token creation
TEST(TokenTest, ValidConstructorTest) {
    const Token t(TokenType::NOT, std::string("!"));

    EXPECT_EQ(t.getType(), TokenType::NOT);
    EXPECT_EQ(t.getValue(), "!");
}

// Test to verify the getters return the expected values
TEST(TokenTest, GettersTest) {
    const Position p {1, 1, 2, 3};
    const Token t(TokenType::LET_KW, std::string("let"), p);

    EXPECT_EQ(t.getType(), TokenType::LET_KW);
    EXPECT_EQ(t.getValue(), "let");
    EXPECT_EQ(t.getPosition(), p);
}

// Test to verify complete constructor initialises correctly
TEST(TokenTest, SpanInitializationTest) {
    const Position pos(1, 1, 10, 13);
    const Token t(TokenType::LET_KW, std::string("let"), pos);

    EXPECT_EQ(t.getPosition(), pos);
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