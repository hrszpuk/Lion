#include "headers/lexer.h"

#include <iostream>
#include <vector>

Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
    this->currentChar = this->text[this->pos];
}

std::vector<Token> Lexer::lex() {

}

Token Lexer::lexInteger() {

}

void Lexer::advance() {

}

void Lexer::skipWhitespace() {

}

void Lexer::error() {

}