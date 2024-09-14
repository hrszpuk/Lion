#include "headers/token.h"

Token::Token(TokenType type, std::string value) {
    this->type = type;
    this->value = value;
}

TokenType Token::getType() {
    return this->type;
}

std::string Token::getValue() {
    return this->value;
}

std::string Token::toString() {
    return "Token(" + std::to_string(static_cast<int>(this->type)) + ", " + this->value + ")";
}