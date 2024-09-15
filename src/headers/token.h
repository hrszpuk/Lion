#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    INTEGER,        // [0-9]+
    PLUS,           // +
    MINUS,          // -
    MUL,            // *
    DIV,            // /
    LPAREN,         // (
    RPAREN          // )
};

class Token {
public:
  	TokenType type;
    std::string value;

    Token(int type, std::string value);

    Token(TokenType type, std::string value);

    TokenType getType();
    std::string getValue();
    std::string toString();
};

#endif //TOKEN_H
