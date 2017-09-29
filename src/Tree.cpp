//
// Created by g on 9/28/17.
//

#include "Tree.h"
#include <iostream>

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

// link a child node to a parent node
void Tree::linkChild(std::shared_ptr<Node> childNode, std::shared_ptr<Node> parentNode) {
    // if this is the first time running, parentNode will be null, so make the parent node the tree root (parentNode)
    if (parentNode == nullptr) parentNode = this->rootNode;
    // the child's tier should always be one greater than the current parent in scope
    childNode->onTier = parentNode->onTier + 1;
    // if the parent's left node is empty, assign the child there
    if (parentNode->left == nullptr) {
        parentNode->left = childNode;
        childNode->parent = parentNode;
    // if the parent's right node is empty, assign the child there
    } else if (parentNode->right == nullptr) {
        parentNode->right = childNode;
        childNode->parent = parentNode;
    //
    } else if (parentNode->parent != nullptr && parentNode->parent->right->left == nullptr) {
        Tree::linkChild(childNode, parentNode->parent->right);
    } else {
        Tree::linkChild(childNode, parentNode->left);
    }
}

void Tree::traverse(std::shared_ptr<Node> rootNode) {
    if(rootNode != nullptr){
        std::cout << rootNode->name << ": " << rootNode->value << std::endl;
        this->traverse(rootNode->left);
        this->traverse(rootNode->right);
    }

}
