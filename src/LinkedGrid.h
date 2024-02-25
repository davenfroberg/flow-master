#ifndef FLOW_MASTER_LINKEDGRID_H
#define FLOW_MASTER_LINKEDGRID_H

#include "Node.h"
#include <map>
#include <string>

class LinkedGrid {
private:
    // this is just temporary, will be replaced with a file reader
    const std::string colours[5][5] = {
            {"B", "E", "E", "E", "B"},
            {"R", "E", "E", "E", "R"},
            {"G", "E", "E", "E", "G"},
            {"Y", "E", "E", "E", "Y"},
            {"O", "E", "E", "E", "O"}
    };

    const std::map<std::string, NodeType> colourMap = {
            {"B", NodeType::BLUE},
            {"R", NodeType::RED},
            {"G", NodeType::GREEN},
            {"Y", NodeType::YELLOW},
            {"O", NodeType::ORANGE},
            {"E", NodeType::EMPTY}
    };

    void generateBoard();
    Node* entry{};
    const int BOARD_DIMENSION = 5;
public:
    LinkedGrid();

    ~LinkedGrid();

    NodeType getColor(int x, int y);
};


#endif //FLOW_MASTER_LINKEDGRID_H
