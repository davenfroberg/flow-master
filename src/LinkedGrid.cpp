#include <map>
#include "LinkedGrid.h"
#include "Node.h"

NodeType LinkedGrid::getColor(int x, int y) {
    return colourMap.at(colours[x][y]);
}

void LinkedGrid::generateBoard() {
    int counter = 1;
    entry = new Node(getColor(0, 0), false, false, counter++);
    Node* columnMarker = entry;
    Node* rowMarker = entry;
    for (int i = 0; i < BOARD_DIMENSION-1; i++) {
        columnMarker->setRight(new Node(getColor(i+1, 0), false, false, counter++));
        columnMarker->getRight()->setLeft(columnMarker);
        columnMarker = columnMarker->getRight();
    }
    for (int y = 0; y < BOARD_DIMENSION-1; y++) {

        rowMarker->setDown(new Node(getColor(0, y+1), false, false, counter++));
        rowMarker->getDown()->setUp(rowMarker);

        rowMarker = rowMarker->getDown();
        columnMarker = rowMarker;
        for (int x = 0; x < BOARD_DIMENSION-1; x++) {
            columnMarker->setRight(new Node(getColor(x+1, y+1), false, false, counter++));
            columnMarker->getRight()->setLeft(columnMarker);
            columnMarker->getRight()->setUp(columnMarker->getUp()->getRight());
            columnMarker->getRight()->getUp()->setDown(columnMarker->getRight());

            columnMarker = columnMarker->getRight();
        }
    }
}

LinkedGrid::LinkedGrid() {
    generateBoard();
}

void deleteHelper(Node* node) {
    if (node->getDown() != nullptr) {
        deleteHelper(node->getDown());
        node->setDown(nullptr);
    }
    if (node->getRight() != nullptr) {
        deleteHelper(node->getRight());
        node->setRight(nullptr);
    }
    if (node->getUp() != nullptr)
        node->getUp()->setDown(nullptr);
    delete node;
}

LinkedGrid::~LinkedGrid() {
    deleteHelper(entry);
}

