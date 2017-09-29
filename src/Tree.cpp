//
// Created by g on 9/28/17.
//

#include "Tree.h"
#include <iostream>

Tree::Tree(){}

Tree::Tree(std::string name, int value, std::string info) {
    puts("Tree App Launched");
    std::shared_ptr<Node> newNode(new Node(name, value, info));
    this->parentNode = newNode;
}

void Tree::addNode(std::string name, int value, std::string info, std::shared_ptr<Node> parent = nullptr) {

    std::unique_ptr<Node> newNode(new Node(name, value, info));
    newNode->parent = parent;
}
