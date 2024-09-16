#include <iostream>
#include "headers/lexer.h"

int main(int argc, char *argv[]) {
    std::string text = "1 + 2 * 3";
    Lexer lexer(text);
    std::vector<Token> tokens = lexer.lex();
    for (Token token : tokens) {
        std::cout << token.toString() << std::endl;
    }
    return 0;
}