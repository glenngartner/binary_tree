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
    this->rootNode->onTier = 0;
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

void Tree::traverseAndStore(std::shared_ptr<Node> rootNode) {
    if (rootNode != nullptr) {
        this->orphanQueue.push(rootNode);
//        std::cout << this->orphanQueue.back()->name << " added to orphan queue " << std::endl;
        this->traverseAndStore(rootNode->left);
        this->traverseAndStore(rootNode->right);
    }
}

std::shared_ptr<Node> Tree::insert(std::shared_ptr<Node> rootNode, std::string name, int value, std::string info) {
    // if the rootNode is empty, create a new node, and return that
    if (rootNode == nullptr) return this->createNode(name, value, info);

    // otherwise, recur down the tree
    if (value < rootNode->value) {
        rootNode->left = this->insert(rootNode->left, name, value, info);
        rootNode->left->onTier = rootNode->onTier + 1;
        rootNode->left->parent = rootNode;
    } else if (value > rootNode->value) {
        rootNode->right = this->insert(rootNode->right, name, value, info);
        rootNode->right->onTier = rootNode->onTier + 1;
        rootNode->right->parent = rootNode;
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
    while (!nodeQueue.empty()) {
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

void Tree::deleteNode(std::string name, int value, std::shared_ptr<Node> parentNode) {
    // instantiate an empty queue object, to hold the orphan nodes that will have to be re-inserted
    std::queue<std::shared_ptr<Node>> nodeQueue;
    // if the parent node is null, which it will be when called initially,
    if (parentNode == nullptr) {
        // set this scope's parent node to equal this object's root node (start at the top of the tree)
        parentNode = this->rootNode;
    }
    // find the node we're looking for
    std::shared_ptr<Node> nodeToDelete = this->find(name, value);
    // when found, traverse the tree, starting with this node, and store its orphans/children into the orphanQueue property
    this->traverseAndStore(nodeToDelete);
    // remove the front node from the orphan queue, because it's always going to be this delete node. keep the others.
    this->orphanQueue.pop();
    // find the parent of this deleted node, and remove it's parents references to it (check for right or left side, then set to null ptr)
    if (nodeToDelete->parent->right == nodeToDelete) nodeToDelete->parent->right = nullptr;
    if (nodeToDelete->parent->left == nodeToDelete) nodeToDelete->parent->left = nullptr;
    // while the orphan queue is not empty
    while(!this->orphanQueue.empty()){
        // insert a new node into the tree, using the front node of the orphanQueue list
        this->insert(this->rootNode, this->orphanQueue.front()->name, this->orphanQueue.front()->value, this->orphanQueue.front()->information);
        // reset shared_ptr on the queue's front node, deleting the object it's referencing
        this->orphanQueue.front().reset();
        // remove the shared_ptr from the orphanQueue, and loop around to operate on the next one, if it exists
        this->orphanQueue.pop();
    }
    // remove the shared pointer and finally delete the node object it's referencing
    nodeToDelete.reset();
}

