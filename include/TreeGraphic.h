//
// Created by g on 10/1/17.
//
#include <memory>
#include "Tree.h"
#include "Node.h"

#ifndef BINARY_TREE_TREEGRAPHIC_H
#define BINARY_TREE_TREEGRAPHIC_H


class TreeGraphic {
public:
    TreeGraphic(std::shared_ptr<Tree> treeLogic);

    void drawNodeGraphic(std::shared_ptr<Node> nodeLogic, int x, int y);
};


#endif //BINARY_TREE_TREEGRAPHIC_H
