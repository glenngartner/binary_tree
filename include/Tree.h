//
// Created by g on 9/28/17.
//
#include <iostream>
#include <memory>
#include "Node.h"
#include <vector>

#ifndef BINARY_TREE_TREEAPP_H
#define BINARY_TREE_TREEAPP_H

struct linkedTier {
    std::shared_ptr<Node> node = nullptr;
    std::shared_ptr<Node> next = nullptr;
};

class Tree {
public:
    Tree();

    Tree(std::string name, int value, std::string info);

    std::shared_ptr<Node> rootNode;

    int currentTier;

    std::vector<std::shared_ptr<linkedTier>> nodesAtTiers;

    std::shared_ptr<Node> createNode(std::string name, int value, std::string info);

    void traverse(std::shared_ptr<Node> rootNode);

    std::shared_ptr<Node> insert(std::shared_ptr<Node> rootNode, std::string name, int value, std::string info);

    std::shared_ptr<Node> find(std::string name, int value, std::shared_ptr<Node> rootNode = nullptr);

    std::shared_ptr<linkedTier> createLinkTierFromNode(std::shared_ptr<Node> node);

    void printTree(std::shared_ptr<Node> parentNode = nullptr);
};


#endif //BINARY_TREE_TREEAPP_H
