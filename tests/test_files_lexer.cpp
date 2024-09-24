//
// Created by hrs on 24/09/24.
//
#include <gtest/gtest.h>
#include "../src/headers/lexer.h"
#include "../src/headers/token.h"

TEST(LexerFilesTest, SimpleTest) {
    const std::string argument = "1 + 2 * 3";
    Lexer lexer(argument);
    std::vector<Token> tokens = lexer.lex();

    ASSERT_EQ(tokens.size(), 5);
    EXPECT_EQ(tokens[0].getType(), TokenType::INTEGER);
    EXPECT_EQ(tokens[1].getType(), TokenType::PLUS);
    EXPECT_EQ(tokens[2].getType(), TokenType::INTEGER);
    EXPECT_EQ(tokens[3].getType(), TokenType::MUL);
    EXPECT_EQ(tokens[4].getType(), TokenType::INTEGER);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}