//
// Created by g on 9/28/17.
//

#include <string>

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H


class Node {
public:
    Node(std::string name, int value);

    std::string name;
    int value;
    std::string information;
    Node *parent;
    Node *left;
    Node *right;

};


#endif //BINARY_TREE_NODE_H
