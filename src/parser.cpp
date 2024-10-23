#include "headers/parser.h"
#include "headers/token.h"
#include "headers/nodes/node.h"

[[nodiscard]] std::vector<Node> Parser::parse() {
    while (this->pos < this->tokens.size()) {
        switch (this->currentToken.getType()) {
            case TokenType::LET_KW:
                this->nodes.push_back(this->parseVariableDeclaration());
                break;
            case TokenType::IF_KW:
                this->nodes.push_back(this->parseIfStatement());
                break;
            default: ;
        }
    }
    return this->nodes;
}

// Utilities
[[nodiscard]] std::optional<Token> Parser::nextToken() {
    if (pos < this->tokens.size()) {
        this->pos++;
        this->currentToken = this->tokens.at(pos);
        return this->currentToken;
    }
    return std::nullopt;
}

[[nodiscard]] std::optional<Token> Parser::peekToken() const {
    if (pos+1 < this->tokens.size()) {
        Token t = this->tokens.at(pos+1);
        return t;
    }
    return std::nullopt;
}

// Parsing statements
[[nodiscard]] Node Parser::parseStatement() {
    return Node{};
}

[[nodiscard]] Node Parser::parseVariableDeclaration() {
    return Node{};
}

[[nodiscard]] Node Parser::parseAssignment() {
    return Node{};
}

[[nodiscard]] Node Parser::parseIfStatement() {
    return Node{};
}

[[nodiscard]] Node Parser::parseElseStatement() {
    return Node{};
}

[[nodiscard]] Node Parser::parseExpressionStatement() {
    return Node{};
}

// Parsing expressions
[[nodiscard]] Node Parser::parseExpression() {
    return Node{};
}

[[nodiscard]] Node Parser::parseLogicalOr() {
    return Node{};
}

[[nodiscard]] Node Parser::parseLogicalAnd() {
    return Node{};
}

[[nodiscard]] Node Parser::parseEquality() {
    return Node{};
}

[[nodiscard]] Node Parser::parseRelational() {
    return Node{};
}

[[nodiscard]] Node Parser::parseAddition() {
    return Node{};
}

[[nodiscard]] Node Parser::parseMultiplication() {
    return Node{};
}

[[nodiscard]] Node Parser::parseUnary() {
    return Node{};
}

[[nodiscard]] Node Parser::parsePrimary() {
    return Node{};
}