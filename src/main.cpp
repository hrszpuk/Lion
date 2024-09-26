#include <fstream>
#include <iostream>
#include "headers/lexer.h"


int main(int argc, char *argv[]) {

    if (argc != 2 || argv[1] == nullptr) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];

    try {
        std::ifstream file(filename);
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);  // Enable exceptions

        std::string file_contents((std::istreambuf_iterator(file)),
                               std::istreambuf_iterator<char>());

        Lexer lexer(file_contents);
        for (auto tokens = lexer.lex(); const auto &token : tokens) {
            std::cout << token.toString() << std::endl;
        }

        file.close();
    } catch (const std::ifstream::failure& e) {
        std::cerr << "Error: Exception occurred while reading file: " << e.what() << std::endl;
    }

    return 0;
}