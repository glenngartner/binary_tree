//
// Created by g on 9/30/17.
//

#ifndef BINARY_TREE_NODEGRAPHIC_H
#define BINARY_TREE_NODEGRAPHIC_H


#include <memory>
#include "Node.h"

struct vec2 {
    int x;
    int y;
};

class NodeGraphic {
public:
    NodeGraphic(std::shared_ptr<Node> node);

    std::shared_ptr<Node> node;
    vec2 position;

};


#endif //BINARY_TREE_NODEGRAPHIC_H
