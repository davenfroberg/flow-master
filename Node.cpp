#include "Node.h"

NodeType Node::getType() const {
    return type;
}

void Node::setType(NodeType type) {
    Node::type = type;
}

bool Node::isStart() const {
    return startNode;
}

bool Node::isEnd() const {
    return endNode;
}

bool Node::isEmpty() const {
    return emptyNode;
}

void Node::setEmpty(bool isEmpty) {
    Node::emptyNode = isEmpty;
}

Node *Node::getUp() const {
    return up;
}

void Node::setUp(Node *up) {
    Node::up = up;
}

Node *Node::getDown() const {
    return down;
}

void Node::setDown(Node *down) {
    Node::down = down;
}

Node *Node::getLeft() const {
    return left;
}

void Node::setLeft(Node *left) {
    Node::left = left;
}

Node *Node::getRight() const {
    return right;
}

void Node::setRight(Node *right) {
    Node::right = right;
}

Node::Node(NodeType type, bool startNode, bool endNode, bool emptyNode) {
    validateArguments(type, startNode, endNode, emptyNode);

    Node::type = type;
    Node::startNode = startNode;
    Node::endNode = endNode;
    Node::emptyNode = emptyNode;
}
