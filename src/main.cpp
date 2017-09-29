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
    std::shared_ptr<Node> newChild = this->binaryTree.createNode("Mike", 14, "is a teenage");
    this->binaryTree.linkChild(newChild);
    newChild = this->binaryTree.createNode("Bill", 100, "is very old");
    this->binaryTree.linkChild(newChild);
    newChild = this->binaryTree.createNode("Hank", 75, "is kind-of old");
    this->binaryTree.linkChild(newChild);
    newChild = this->binaryTree.createNode("Dude", 25, "is a young adult");
    this->binaryTree.linkChild(newChild);
    newChild = this->binaryTree.createNode("Dude2", 22, "is also a young adult");
    this->binaryTree.linkChild(newChild);
    newChild = this->binaryTree.createNode("Dude3", 22, "is also a young adult");
    this->binaryTree.linkChild(newChild);
    newChild = this->binaryTree.createNode("Dude4", 22, "is also a young adult");
    this->binaryTree.linkChild(newChild);
    this->binaryTree.traverse(this->binaryTree.rootNode);
    puts("Hold the debugger");
}

void BasicApp::draw() {
//    BasicApp::myRenderer.draw();
}

CINDER_APP(BasicApp, ci::app::RendererGl)