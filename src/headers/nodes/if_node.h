#ifndef IFNODE_H
#define IFNODE_H
#include <memory>

#include "node.h"

class IfNode final : public Node {
public:
    std::unique_ptr<Node> condition;       // The condition of the if statement
    std::unique_ptr<Node> statement;       // Statement that is used if condition succeeds
    std::optional<std::unique_ptr<Node>> elseBranch;

    IfNode(const Position& position,
            const std::vector<Token>& tokens,
            std::unique_ptr<Node> cond,
            std::unique_ptr<Node> thenBr,
            std::optional<std::unique_ptr<Node>> elseBr = std::nullopt)
        : Node(tokens), condition(std::move(cond)),
          statement(std::move(thenBr)),
          elseBranch(std::move(elseBr)) {}

    [[nodiscard]] std::string toString() const override {
        return std::format("IfNode({}, {}, {})", this->condition, this->statement, this->elseBranch, position.toString());
    }
};

#endif //IFNODE_H
