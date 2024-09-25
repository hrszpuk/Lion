#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

enum class NodeType {
    // Statements

    // Expressions

};

class Node {
protected:
    NodeType type;
    std::vector<Node> children;
    std::string name;

public:
    Node();
    ~Node();

    [[nodiscard]] std::string toString() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] NodeType getType() const;
    [[nodiscard]] std::vector<Node> getChildren() const;
};

#endif //NODE_H
