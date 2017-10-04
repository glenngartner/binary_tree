//
// Created by glenn on 10/4/2017.
//
#include <vector>
#include "Tree.h"

#ifndef BINARY_TREE_TREEGRAPHIC_H
#define BINARY_TREE_TREEGRAPHIC_H


class TreeGraphic {
public:
    TreeGraphic(std::shared_ptr<Tree> treeLogic);
    std::vector<Node> positions;
};


#endif //BINARY_TREE_TREEGRAPHIC_H
