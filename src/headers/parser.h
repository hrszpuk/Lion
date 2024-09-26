#ifndef PARSER_H
#define PARSER_H
#include <vector>

#include "nodes/node.h"
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
    [[nodiscard]] Node parseStatement();
    [[nodiscard]] Node parseVariableDeclaration();
    [[nodiscard]] Node parseAssignment();
    [[nodiscard]] Node parseIfStatement();
    [[nodiscard]] Node parseElseStatement();
    [[nodiscard]] Node parseExpressionStatement();

    // Parsing expressions
    [[nodiscard]] Node parseExpression();     // General expression entry point
    [[nodiscard]] Node parseLogicalOr();      // Handles ||
    [[nodiscard]] Node parseLogicalAnd();     // Handles &&
    [[nodiscard]] Node parseEquality();       // Handles ==, !=
    [[nodiscard]] Node parseRelational();     // Handles >, <, >=, <=
    [[nodiscard]] Node parseAddition();       // Handles +, -
    [[nodiscard]] Node parseMultiplication(); // Handles *, /
    [[nodiscard]] Node parseUnary();          // Handles !, - (unary minus)
    [[nodiscard]] Node parsePrimary();        // Handles literals, variables, and parentheses
};


#endif //PARSER_H
