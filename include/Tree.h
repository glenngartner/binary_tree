//
// Created by g on 9/28/17.
//
#include <iostream>
#include <memory>
#include "Node.h"

#ifndef BINARY_TREE_TREEAPP_H
#define BINARY_TREE_TREEAPP_H


class Tree {
public:
    Tree();

    Tree(std::string name, int value, std::string info);

    std::shared_ptr<Node> parentNode;

    std::shared_ptr<Node> createNode(std::string name, int value, std::string info, std::shared_ptr<Node> parent);

    void linkChild(std::shared_ptr<Node> childNode);
};


#endif //BINARY_TREE_TREEAPP_H
