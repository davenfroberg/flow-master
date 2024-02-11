#ifndef FLOW_MASTER_NODE_H
#define FLOW_MASTER_NODE_H
#include <stdexcept>

enum class NodeType {
    EMPTY,
    BLUE,
    RED,
    GREEN,
    YELLOW,
    ORANGE
};

class Node {

private:
    NodeType type; // the colour of the node (or empty)
    bool startNode; // if the node is one of the pre-defined start or end nodes
    bool endNode; // if the node is one of the pre-defined start or end nodes
    bool emptyNode; // if the node has no colour
    Node *up;
    Node *down;
    Node *left;
    Node *right;

    static void validateArguments(NodeType type, bool start, bool end, bool empty) {
        if (start && (end || empty))
            throw std::invalid_argument("Node cannot be both a start node and an end node or empty");
        if (end && empty)
            throw std::invalid_argument("Node cannot be both an end node and a start node or empty");
        if (empty && (type != NodeType::EMPTY))
            throw std::invalid_argument("Node cannot be empty and have a color");
        if (!empty && (type == NodeType::EMPTY))
            throw std::invalid_argument("Node cannot have a color and be empty");
    };

public:
    Node(NodeType type, bool startNode, bool endNode, bool emptyNode);

    NodeType getType() const;

    void setType(NodeType type);

    bool isStart() const;

    bool isEnd() const;

    bool isEmpty() const;

    void setEmpty(bool isEmpty);

    Node *getUp() const;

    void setUp(Node *up);

    Node *getDown() const;

    void setDown(Node *down);

    Node *getLeft() const;

    void setLeft(Node *left);

    Node *getRight() const;

    void setRight(Node *right);
};

#endif //FLOW_MASTER_NODE_H