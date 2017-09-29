//
// Created by g on 9/28/17.
//

#include "Node.h"

Node::Node(std::string name, int value, std::string info) {

    Node::name = name;
    Node::value = value;
    Node::information = info;
    Node::parent = nullptr;
    Node::left = nullptr;
    Node::right = nullptr;
    this->onTier = -1;
}
