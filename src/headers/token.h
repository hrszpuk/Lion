#ifndef TOKEN_H
#define TOKEN_H

#include <span>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>

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

// String representation of TokenType
inline std::string TokenTypeString[] = {
    "UNKNOWN",

    // Keywords
    "LET_KW",
    "PRINT_KW",
    "INPUT_KW",
    "IF_KW",
    "ELSE_KW",

    // Literal
    "STRING_LITERAL",
    "INTEGER_LITERAL",

    "IDENTIFIER",

    // Type keywords
    "I32_KW",
    "U32_KW",
    "STRING_KW",

    // Arithmetic operators
    "PLUS",
    "MINUS",
    "MUL",
    "DIV",

    // Logical operators
    "AND",
    "OR",
    "NOT",

    // Comparison operators
    "GREATER_THAN",
    "LESS_THAN",
    "EQUAL_TO",
    "GREATER_THAN_OR_EQUAL_TO",
    "LESS_THAN_OR_EQUAL_TO",

    // Braces, parameters, and brackets
    "LBRACE",
    "RBRACE",
    "LPAREN",
    "RPAREN",

    // Assignment operator
    "EQUALS"
};

inline const std::unordered_map<std::string, TokenType>& keywords() {
    static const std::unordered_map<std::string, TokenType> m = {
        {"let", TokenType::LET_KW},
        {"print", TokenType::PRINT_KW},
        {"input", TokenType::INPUT_KW},
        {"if", TokenType::IF_KW},
        {"else", TokenType::ELSE_KW},
        {"string", TokenType::STRING_KW},
        {"i32", TokenType::I32_KW},
        {"u32", TokenType::U32_KW}
    };
    return m;
}


class Position {
protected:
    uint line;
    uint columnStart;
    uint columnEnd;
    uint start; // Start position of the token (raw)
    uint end;   // End position of the token (raw)

public:
    Position() = default;
    Position(const uint line, const uint columnStart, const uint columnEnd, const uint start, const uint end)
        : line(line), columnStart(columnStart), columnEnd(columnEnd), start(start), end(end) {
        if (line == 0 || columnStart == 0 || columnEnd == 0) throw std::invalid_argument("Invalid Line/Column Position");
        if (start >= end) throw std::invalid_argument("Invalid Start/End Position");
    };

    [[nodiscard]] uint getLine() const;
    [[nodiscard]] uint getColumnStart() const;
    [[nodiscard]] uint getColumnEnd() const;
    [[nodiscard]] uint getStart() const;
    [[nodiscard]] uint getEnd() const;

    [[nodiscard]] std::string toString() const;

    bool operator==(const Position &other) const; // This is used for test cases
};

class Token {
protected:
  	TokenType type;
    std::string value;
    Position position;

    static void checkArgs(const TokenType type, std::string value) {
        if (value.empty()) throw std::invalid_argument("empty string");
        if (type < TokenType::UNKNOWN || type > TokenType::EQUALS) throw std::invalid_argument("invalid token type");
    }

public:
    explicit Token(const TokenType type, std::string value): type(type), value(value), position() {
        checkArgs(type, value);
    }

    explicit Token(const TokenType type, std::string value, Position pos): type(type), value(value), position(pos) {
        checkArgs(type, value);
    }
    Token() = default;

    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getValue() const;
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] Position getPosition() const;
};

#endif //TOKEN_H
