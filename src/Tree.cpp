//
// Created by g on 9/28/17.
//

#include <queue>
#include "Tree.h"

Tree::Tree() {}

Tree::Tree(std::string name, int value, std::string info) {
    puts("Tree App Launched");
    std::shared_ptr<Node> newNode(new Node(name, value, info));
    this->rootNode = newNode;
    this->currentTier = 0;
    this->rootNode->onTier = this->currentTier;
    std::shared_ptr<linkedTier> tempLink = this->createLinkTierFromNode(this->rootNode);
    this->nodesAtTiers = {};
    this->nodesAtTiers.push_back(tempLink);
}

std::shared_ptr<Node> Tree::createNode(std::string name, int value, std::string info) {

    std::shared_ptr<Node> newNode(new Node(name, value, info));
    return newNode;
}

void Tree::traverse(std::shared_ptr<Node> rootNode) {
    if (rootNode != nullptr) {
        std::cout << rootNode->name << ": " << rootNode->value << std::endl;
        this->traverse(rootNode->left);
        this->traverse(rootNode->right);
    }
}

std::shared_ptr<Node> Tree::insert(std::shared_ptr<Node> rootNode, std::string name, int value, std::string info) {
    // if the rootNode is empty, create a new node, and return that
    if (rootNode == nullptr) return this->createNode(name, value, info);

    // otherwise, recur down the tree
    if (value < rootNode->value) {
        rootNode->left = this->insert(rootNode->left, name, value, info);
        rootNode->left->onTier = rootNode->onTier + 1;
    } else if (value > rootNode->value) {
        rootNode->right = this->insert(rootNode->right, name, value, info);
        rootNode->right->onTier = rootNode->onTier + 1;
    }
    return rootNode;
}

std::shared_ptr<Node> Tree::find(std::string name, int value, std::shared_ptr<Node> rootNode) {
    // if no value is passed to rootNode parameter, this may be the first time calling the function, so use this->rootNode to begin
    if (rootNode == nullptr) rootNode = this->rootNode;
    // if this is the node you're looking for, return it
    if (rootNode->name == name && rootNode->value == value) {
        std::cout << "FOUND: " << name << ": " << value << ", on tier: " << rootNode->onTier << std::endl;
        return rootNode;
    }
    // otherwise, go right or left, depending on the value
    if (value < rootNode->value) {
        rootNode = this->find(name, value, rootNode->left);
    } else if (value > rootNode->value) {
        rootNode = this->find(name, value, rootNode->right);
    }

    return rootNode;
}

std::shared_ptr<linkedTier> Tree::createLinkTierFromNode(std::shared_ptr<Node> node) {
    std::shared_ptr<linkedTier> tempLink(new linkedTier());
    tempLink->node = node;
    return tempLink;
}

// prints the entire contents of the tree, breadth wise, or more specifically, by each tier (or row)
void Tree::printTree(std::shared_ptr<Node> parentNode) {
    // instantiate an empty queue object, to hold nodes we'll operate on
    std::queue<std::shared_ptr<Node>> nodeQueue;
    // set the current tier to a number we'll never have, to aid the print Tier condition to trigger for all nodes on a new tier
    int currentTier = -1;
    // if the parent node is null, which it will be when called initially,
    if (parentNode == nullptr) {
        // set this scope's parent node to equal this object's root node (start at the top of the tree)
        parentNode = this->rootNode;
        // push the parent node into the node queue, so we can operate on it first
        nodeQueue.push(parentNode);
    }
    // check to see if the queue has at least one object in it, and if so, operate on it. If not, the queue is empty, and there's nothing more to do
    while (nodeQueue.front() != nullptr) {
        // this will set the parent node, who is the one we're always operating on, to be the front-most node in the queue
        // the front most item is continually updated, so we reset this value every time this loop begins
        parentNode = nodeQueue.front();
        // if the current tier value is different than the current node we're operating on
        if (currentTier != parentNode->onTier) {
            // set the current tier value to the current node's tier value
            currentTier = parentNode->onTier;
            // print the new tier value on a separate line. This helps separate the console printing by tiers (or groups)
            std::cout << std::endl << "Tier: " << currentTier << "-- " << std::endl;
        }
        // print the details for the current node we're operating on. This is always the front-most node in the queue
        std::cout << "Name: " << nodeQueue.front()->name << ", Value: " << nodeQueue.front()->value << " -- "
                  << std::endl;
        // when you're finished operating on this node, remove it from the front of the queue, and the next one, if it exists, will take his place
        nodeQueue.pop();
        // check if the current node has children. if it does, add them to the back of this queue, and they will print when it's their turn
        if (parentNode->left != nullptr) nodeQueue.push(parentNode->left);
        if (parentNode->right != nullptr) nodeQueue.push(parentNode->right);
    }
}

