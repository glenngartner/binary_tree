//
// Created by g on 9/30/17.
//

#include <iostream>
#include <BasicApp.h>

BasicApp::BasicApp(){
    this->binaryTree = std::make_shared<Tree>("G", 35, "is tall");
}

void BasicApp::setup() {
    puts("Adding nodes");
    this->binaryTree->insert(this->binaryTree->rootNode, "Mike", 14, "is a teenager");
    this->binaryTree->insert(this->binaryTree->rootNode, "Bill", 100, "is very old");
    this->binaryTree->insert(this->binaryTree->rootNode, "Hank", 75, "is kind-of old");
    this->binaryTree->insert(this->binaryTree->rootNode, "Dude", 25, "is a young adult");
    this->binaryTree->insert(this->binaryTree->rootNode, "Dude2", 24, "is also a young adult");
    this->binaryTree->insert(this->binaryTree->rootNode, "Dude3", 23, "is also also a young adult");
    puts("--------------------");
    puts("Searching for nodes:");
    puts("--------------------");
    this->binaryTree->find("G", 35);
    this->binaryTree->find("Mike", 14);
    this->binaryTree->find("Bill", 100);
    this->binaryTree->find("Hank", 75);
    this->binaryTree->find("Dude", 25);
    this->binaryTree->find("Dude2", 24);
    this->binaryTree->find("Dude3", 23);
    puts("--------------");
    puts("Printing nodes");
    puts("--------------");
    this->binaryTree->printTree();
    puts("--------------");
    puts("Deleting nodes");
    puts("--------------");
    this->binaryTree->deleteNode("Mike", 14);
    puts("--------------");
    puts("Printing nodes again");
    puts("--------------");
    this->binaryTree->printTree();
    this->binaryTree->deleteNode("Hank", 75);
    puts("--------------");
    puts("Deleting nodes");
    puts("--------------");
    this->binaryTree->printTree();
    puts("--------------");
    puts("Printing nodes again");
    puts("--------------");
}

