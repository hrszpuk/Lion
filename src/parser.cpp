#include "headers/parser.h"
#include "headers/token.h"
#include "headers/node.h"

[[nodiscard]] std::vector<Node> Parser::parse() {
    while (this->pos < this->tokens.size()) {
        switch (this->currentToken.getType()) {
            case TokenType::LET_KW:
                this->nodes.push_back(this->parseVariableDeclaration());
            default: ;
        }
    }
}

// Utilities
[[nodiscard]] Token Parser::nextToken() {

}

[[nodiscard]] const Token& Parser::peekNextToken() const {

}

// Parsing statements
[[nodiscard]] Node Parser::parseStatement() {

}

[[nodiscard]] Node Parser::parseVariableDeclaration() {

}

[[nodiscard]] Node Parser::parseAssignment() {

}

[[nodiscard]] Node Parser::parseIfStatement() {

}

[[nodiscard]] Node Parser::parseElseStatement() {

}

[[nodiscard]] Node Parser::parseExpressionStatement() {

}

// Parsing expressions
[[nodiscard]] Node Parser::parseExpression() {

}

[[nodiscard]] Node Parser::parseLogicalOr() {

}

[[nodiscard]] Node Parser::parseLogicalAnd() {

}

[[nodiscard]] Node Parser::parseEquality() {

}

[[nodiscard]] Node Parser::parseRelational() {

}

[[nodiscard]] Node Parser::parseAddition() {

}

[[nodiscard]] Node Parser::parseMultiplication() {

}

[[nodiscard]] Node Parser::parseUnary() {

}

[[nodiscard]] Node Parser::parsePrimary() {

}