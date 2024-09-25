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

    IDENTIFIER,

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

class Position {
protected:
    uint line;
    uint column;
    uint start; // Start position of the token (raw)
    uint end;   // End position of the token (raw)

public:
    Position() = default;
    Position(const uint line, const uint column, const uint start, const uint end)
        : line(line), column(column), start(start), end(end) {
        if (line == 0 || column == 0) throw std::invalid_argument("Invalid Line/Column Position");
        if (start >= end) throw std::invalid_argument("Invalid Start/End Position");
    };

    [[nodiscard]] uint getLine() const;
    [[nodiscard]] uint getColumn() const;
    [[nodiscard]] uint getStart() const;
    [[nodiscard]] uint getEnd() const;

    bool operator==(const Position &other) const; // This is used for test cases
};

class Token {
protected:
  	TokenType type;
    std::string value;
    Position position;

    static void check_args(const TokenType type, std::string value) {
        if (value.empty()) throw std::invalid_argument("empty string");
        if (type < TokenType::UNKNOWN || type > TokenType::EQUALS) throw std::invalid_argument("invalid token type");
    }

    explicit Token(const TokenType type = TokenType::UNKNOWN, std::string value = "", std::span<size_t> span = {})
        : type(type), value(value), span(span) {
        if (value.empty()) throw std::invalid_argument("Token value cannot be empty");
        if (type < TokenType::UNKNOWN || type > TokenType::EQUALS) throw std::invalid_argument("Invalid token type");
    }
    Token() = default;

    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getValue() const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] Position getPosition() const;
};

#endif //TOKEN_H
