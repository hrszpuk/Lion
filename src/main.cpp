#include <iostream>
#include "headers/lexer.h"

int main(int argc, char *argv[]) {
    std::string text = "1 + 2 * 3";
    Lexer lexer(text);
    std::vector<Token> tokens = lexer.lex();
    for (Token token : tokens) {
        std::cout << token.toString() << std::endl;
    }

    std::string s = "test";

    // lambda to reverse a string
    std::string reverse = [&s] {
        std::string reversed;
        for (int i = s.length() - 1; i >= 0; i--) {
            reversed += s[i];
        }
        return reversed;
    }();
    return 0;
}