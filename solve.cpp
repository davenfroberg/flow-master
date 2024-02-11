#include <iostream>
#include "Node.h"

int main() {
    Node* node = new Node(NodeType::EMPTY, false, false, true);
    delete(node);
    return 0;
}