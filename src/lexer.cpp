#include "headers/lexer.h"

#include <iostream>
#include <vector>

Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
    this->currentChar = this->text[this->pos];
}

std::vector<Token> Lexer::lex() {
    while (this->currentChar != '\0') {
        //std::cout << this->currentChar << " " << static_cast<int>(this->currentChar) << std::endl;
        if (this->currentChar == ' ' || this->currentChar == '\n' || this->currentChar == '\t') {
            this->skipWhitespace();
            continue;
        }
        if (isdigit(this->currentChar)) {
            this->tokens.push_back(this->lexInteger());
            continue;
        }
        switch (this->currentChar) {
            case '+':
                this->tokens.push_back(Token(TokenType::PLUS, "+"));
                this->advance();
                break;
            case '-':
                this->tokens.push_back(Token(TokenType::MINUS, "-"));
                this->advance();
                break;
            case '*':
                this->tokens.push_back(Token(TokenType::MUL, "*"));
                this->advance();
                break;
            case '/':
                this->tokens.push_back(Token(TokenType::DIV, "/"));
                this->advance();
                break;
            case '(':
                this->tokens.push_back(Token(TokenType::LPAREN, "("));
                this->advance();
                break;
            case ')':
                this->tokens.push_back(Token(TokenType::RPAREN, ")"));
                this->advance();
                break;
            default:
                this->error();
                break;
        }
    }
    return this->tokens;
}

Token Lexer::lexInteger() {
    std::string result = "";
    while (this->currentChar != '\0' && isdigit(this->currentChar)) {
        result += this->currentChar;
        this->advance();
    }
    return Token(TokenType::INTEGER_LITERAL, result);
}

void Lexer::advance() {
    this->pos++;
    if (this->pos > static_cast<int>(this->text.length()) - 1) {
        this->currentChar = '\0';
    } else {
        this->currentChar = this->text[this->pos];
    }
}

void Lexer::skipWhitespace() {
    while (this->currentChar == ' ' || this->currentChar == '\n' || this->currentChar == '\t') {
        this->advance();
    }
}

void Lexer::error() {
    std::cout << "Invalid character" << std::endl;
    this->pos++;
}