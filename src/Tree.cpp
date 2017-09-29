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
    // if the rootNode is empty, create a new node, and return that
    if(rootNode == nullptr) return this->createNode(name, value, info);

    // otherwise, recur down the tree
    if (value < rootNode->value){
        rootNode->left = this->insert(rootNode->left, name, value, info);
        rootNode->left->onTier = rootNode->onTier + 1;
    } else if (value > rootNode->value){
        rootNode->right = this->insert(rootNode->right, name, value, info);
        rootNode->right->onTier = rootNode->onTier + 1;
    }
    return rootNode;
}

std::shared_ptr<Node> Tree::find(std::string name, int value, std::shared_ptr<Node> rootNode) {
    // if no value is passed to rootNode parameter, this may be the first time calling the function, so use this->rootNode to begin
    if (rootNode == nullptr) rootNode = this->rootNode;
    // if this is the node you're looking for, return it
    if (rootNode->name == name && rootNode->value == value){
        std::cout << "FOUND: " << name << ": " << value << ", on tier: " << rootNode->onTier << std::endl;
        return rootNode;
    }
    // otherwise, go right or left, depending on the value
    if(value < rootNode->value){
        rootNode = this->find(name, value, rootNode->left);
    } else if (value > rootNode->value){
        rootNode = this->find(name, value, rootNode->right);
    }

    return rootNode;
}

