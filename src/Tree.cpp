//
// Created by g on 9/28/17.
//

#include "Tree.h"

Tree::Tree() {}

Tree::Tree(std::string name, int value, std::string info) {
    puts("Tree App Launched");
    std::shared_ptr<Node> newNode(new Node(name, value, info));
    this->rootNode = newNode;
    this->currentTier = 0;
    this->rootNode->onTier = this->currentTier;
}

std::shared_ptr<Node> Tree::createNode(std::string name, int value, std::string info) {

    std::shared_ptr<Node> newNode(new Node(name, value, info));
    return newNode;
}

void Tree::traverse(std::shared_ptr<Node> rootNode) {
    if(rootNode != nullptr){
        std::cout << rootNode->name << ": " << rootNode->value << std::endl;
        this->traverse(rootNode->left);
        this->traverse(rootNode->right);
    }
}

std::shared_ptr<Node> Tree::insert(std::shared_ptr<Node> rootNode, std::string name, int value, std::string info) {
    // if the tree is empty (shouldn't be, but just in case) return the
    if(rootNode == nullptr) return this->createNode(name, value, info);

    // otherwise, recur down the tree
    if (value < rootNode->value){
        rootNode->left = this->insert(rootNode->left, name, value, info);
    } else if (value > rootNode->value){
        rootNode->right = this->insert(rootNode->right, name, value, info);
    }
    return rootNode;
}

