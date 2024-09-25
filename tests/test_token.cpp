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
    const Position p {1, 1, 2, 2, 3};
    const Token t(TokenType::LET_KW, std::string("let"), p);

    EXPECT_EQ(t.getType(), TokenType::LET_KW);
    EXPECT_EQ(t.getValue(), "let");
    EXPECT_EQ(t.getPosition(), p);
}

// Test to verify complete constructor initialises correctly
TEST(TokenTest, SpanInitializationTest) {
    const Position pos(1, 1, 2, 10, 13);
    const Token t(TokenType::LET_KW, std::string("let"), pos);

    EXPECT_EQ(t.getPosition(), pos);
}

// Test for checking string representation
TEST(TokenTest, ToStringTest) {
    const Token t(TokenType::LET_KW, "let");

    EXPECT_EQ(t.toString(), "Token(LET_KW, \"let\", (0:0-0)[0..0])");
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

// Test to verify line and column are not 0
TEST(PositionTest, InvalidLineColumnTest) {
    EXPECT_THROW({
        Token t(TokenType::LET_KW, "let", Position{0, 0, 1, 0, 1});
    }, std::invalid_argument);
}

// Test to verify end is greater than start
TEST(PositionTest, InvalidStartEndTest) {
    EXPECT_THROW({
        Token t(TokenType::LET_KW, "let", Position{1, 1, 2, 10, 0});
    }, std::invalid_argument);
}

// Test to verify end is greater than start
TEST(PositionTest, InvalidEqualStartEndTest) {
    EXPECT_THROW({
        Token t(TokenType::LET_KW, "let", Position{1, 1, 2, 0, 0});
    }, std::invalid_argument);
}

// Test to verify position getters work
TEST(PositionTest, GetterTest) {
    const Position p(1, 1, 10, 10, 13);

    EXPECT_EQ(p.getLine(), 1);
    EXPECT_EQ(p.getColumnStart(), 1);
    EXPECT_EQ(p.getColumnEnd(), 10);
    EXPECT_EQ(p.getStart(), 10);
    EXPECT_EQ(p.getEnd(), 13);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}