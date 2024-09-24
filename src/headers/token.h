#ifndef TOKEN_H
#define TOKEN_H

#include <span>
#include <stdexcept>
#include <string>
#include <utility>

#define TOKEN_TYPE_LENGTH 28
enum class TokenType {
    UNKNOWN,

    // Keywords
    LET_KW,
    PRINT_KW,
    INPUT_KW,
    IF_KW,
    ELSE_KW,

    // Literal
    STRING_LITERAL,
    INTEGER_LITERAL,

    // Type keywords
    I32_KW,
    U32_KW,
    STRING_KW,

    // Arithmetic operators
    PLUS,
    MINUS,
    MUL,
    DIV,

    // Logical operators
    AND,
    OR,
    NOT,

    // Comparison operators
    GREATER_THAN,
    LESS_THAN,
    EQUAL_TO,
    GREATER_THAN_OR_EQUAL_TO,
    LESS_THAN_OR_EQUAL_TO,

    // Braces, parameters, and brackets
    LBRACE,
    RBRACE,
    LPAREN,
    RPAREN,

    // Assignment operator
    EQUALS
};

class Token {
public:
  	TokenType type;
    std::string value;

    Token(TokenType type, std::string value);

    TokenType getType();
    std::string getValue();
    std::string toString();
};

#endif //TOKEN_H
