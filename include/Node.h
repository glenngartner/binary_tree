//
// Created by g on 9/28/17.
//

#include <string>
#include <memory>

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H


class Node {
public:

    Node(std::string name, int value, std::string info);

    std::string name;
    int value;
    std::string information;
    std::shared_ptr<Node> parent;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

};


#endif //BINARY_TREE_NODE_H
