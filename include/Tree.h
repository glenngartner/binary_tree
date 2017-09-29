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

//    template <int parent, int child>
//    std::array<std::array<std::shared_ptr<Node>, child>, parent> parentsAtTiers;

    std::shared_ptr<Node> createNode(std::string name, int value, std::string info);

    void traverse(std::shared_ptr<Node> rootNode);

    void linkChild(std::shared_ptr<Node> childNode, std::shared_ptr<Node> parentNode = nullptr);
};


#endif //BINARY_TREE_TREEAPP_H
