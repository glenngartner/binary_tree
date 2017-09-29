#include <iostream>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "AppRenderer.h"
#include "Node.h"
#include "Tree.h"
#include <string>


class BasicApp : public ci::app::App {
public:
//    AppRenderer myRenderer;
    Tree binaryTree;

    void setup() override;

    void draw() override;
};

void BasicApp::setup() {
//    BasicApp::myRenderer;
    Tree binaryTree("G", 35, "is tall");
    this->binaryTree = binaryTree;
    this->binaryTree.insert(this->binaryTree.rootNode, "Mike", 14, "is a teenager");
    this->binaryTree.insert(this->binaryTree.rootNode, "Bill", 100, "is very old");
    this->binaryTree.insert(this->binaryTree.rootNode, "Hank", 75, "is kind-of old");
    this->binaryTree.insert(this->binaryTree.rootNode, "Dude", 25, "is a young adult");
    this->binaryTree.insert(this->binaryTree.rootNode, "Dude2", 24, "is also a young adult");
    this->binaryTree.insert(this->binaryTree.rootNode, "Dude3", 23, "is also also a young adult");
    this->binaryTree.traverse(this->binaryTree.rootNode);
    this->binaryTree.find("G", 35);
    this->binaryTree.find("Mike", 14);
    this->binaryTree.find("Bill", 100);
    this->binaryTree.find("Hank", 75);
    this->binaryTree.find("Dude", 25);
    this->binaryTree.find("Dude2", 24);
    this->binaryTree.find("Dude3", 23);
    puts("Hold the debugger");
}

void BasicApp::draw() {
//    BasicApp::myRenderer.draw();
}

CINDER_APP(BasicApp, ci::app::RendererGl)