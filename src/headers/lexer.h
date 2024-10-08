#ifndef LEXER_H
#define LEXER_H

#include <vector>

#include "token.h"

class Lexer {
public:
    std::vector<Token> tokens;
    std::string text;
    int pos;
    char currentChar;

    Lexer(std::string text);

    std::vector<Token> lex();
    Token lexInteger();
    void advance();
    void skipWhitespace();
    void error();
};

#endif //LEXER_H
