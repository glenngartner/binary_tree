//
// Created by g on 9/28/17.
//
#include <iostream>
#include <memory>
#include "Node.h"
#include <array>

#ifndef BINARY_TREE_TREEAPP_H
#define BINARY_TREE_TREEAPP_H

class Tree {
public:
    Tree();

    Tree(std::string name, int value, std::string info);

    std::shared_ptr<Node> rootNode;

    int currentTier;

    std::shared_ptr<Node> createNode(std::string name, int value, std::string info);

    void traverse(std::shared_ptr<Node> rootNode);

    std::shared_ptr<Node> insert(std::shared_ptr<Node> rootNode, std::string name, int value, std::string info);

    std::shared_ptr<Node> find(std::string name, int value, std::shared_ptr<Node> rootNode = nullptr);
};


#endif //BINARY_TREE_TREEAPP_H
