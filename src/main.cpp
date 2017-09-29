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
    std::shared_ptr<Node> newChild = this->binaryTree.createNode("Mike", 14, "is a teenage", this->binaryTree.parentNode);
    this->binaryTree.linkChild(newChild);
    puts("Hold the debugger");
}

void BasicApp::draw() {
//    BasicApp::myRenderer.draw();
}

CINDER_APP(BasicApp, ci::app::RendererGl)