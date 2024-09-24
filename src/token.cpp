#include "headers/token.h"

TokenType Token::getType() const {
    return this->type;
}

std::string Token::getValue() const {
    return this->value;
}

std::string Token::toString() const {
    return "Token(" + std::to_string(static_cast<int>(this->type)) + ", " + this->value + ")";
}