//
// Created by g on 9/28/17.
//

#include "Node.h"
#include <string>

Node::Node(std::string name, int value) {

    Node::name = name;
    Node::value = value;
    Node::information = "";
    Node::parent = nullptr;
    Node::left = nullptr;
    Node::right = nullptr;
}
