#ifndef PARSER_H
#define PARSER_H
#include <vector>

#include "node.h"
#include "token.h"

class Parser {
protected:
    std::vector<Node> nodes;
    std::vector<Token> tokens;
    Token currentToken;
    int pos; // token position

public:
    explicit Parser(std::vector<Token> tokens) : tokens(tokens) {
        if (tokens.empty()) {
            throw std::invalid_argument("tokens cannot be empty");
        }

        pos = 0;
        currentToken = tokens[pos];
    }

    virtual ~Parser() = default;

    [[nodiscard]] std::vector<Node> parse();

    // Utilities
    [[nodiscard]] Token nextToken();
    [[nodiscard]] const Token& peekNextToken() const;

    // Parsing statements
    [[nodiscard]] Token parseStatement();
    [[nodiscard]] Token parseVariableDeclaration();
    [[nodiscard]] Token parseAssignment();
    [[nodiscard]] Token parseIfStatement();
    [[nodiscard]] Token parseElseStatement();
    [[nodiscard]] Token parseExpressionStatement();

    // Parsing expressions
    [[nodiscard]] Token parseExpression();     // General expression entry point
    [[nodiscard]] Token parseLogicalOr();      // Handles ||
    [[nodiscard]] Token parseLogicalAnd();     // Handles &&
    [[nodiscard]] Token parseEquality();       // Handles ==, !=
    [[nodiscard]] Token parseRelational();     // Handles >, <, >=, <=
    [[nodiscard]] Token parseAddition();       // Handles +, -
    [[nodiscard]] Token parseMultiplication(); // Handles *, /
    [[nodiscard]] Token parseUnary();          // Handles !, - (unary minus)
    [[nodiscard]] Token parsePrimary();        // Handles literals, variables, and parentheses
};


#endif //PARSER_H
