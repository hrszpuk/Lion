#ifndef NODE_H
#define NODE_H
#include <format>
#include <string>
#include <vector>

#include "token.h"

class Node {
protected:
    Position position{};
    std::vector<Token> tokens;

    void calculatePosition(const std::vector<Token>& tokens);

public:
    explicit Node(const std::vector<Token>& nodeTokens) : tokens(nodeTokens) {
        if (tokens.empty()) throw std::invalid_argument("Node tokens cannot be empty");
        calculatePosition(tokens);
    }

    Node() = default;
    virtual ~Node() = default;

    [[nodiscard]] virtual std::string toString() const {
        return std::format("Node({}, {})", position.toString(), tokens);
    }

    [[nodiscard]] virtual Position getPosition() const {
        return position;
    }

    [[nodiscard]] const std::vector<Token>& getTokens() const {
        return tokens;
    }
};

#endif //NODE_H
