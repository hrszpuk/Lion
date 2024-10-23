#include "headers/token.h"

#include <format>

TokenType Token::getType() const {
    return this->type;
}

std::string Token::getValue() const {
    return this->value;
}

std::string Token::toString() const {
    return std::format("Token({}, \"{}\", {})", TokenTypeString[static_cast<int>(this->type)], this->value, this->position.toString());
}

Position Token::getPosition() const {
    return this->position;
}

uint Position::getLine() const {
    return this->line;
}

uint Position::getColumnStart() const {
    return this->columnStart;
}

uint Position::getColumnEnd() const {
    return this->columnEnd;
}

uint Position::getStart() const {
    return this->start;
}

uint Position::getEnd() const {
    return this->end;
}

std::string Position::toString() const {
    return std::format("({}:{}-{})[{}..{}]", this->line, this->columnStart, this->columnEnd, this->start, this->end);
}

bool Position::operator==(const Position &other) const {
    return this->line == other.line
        && this->columnStart == other.columnStart
        && this->columnEnd == other.columnEnd
        && this->start == other.start
        && this->end == other.end;
}