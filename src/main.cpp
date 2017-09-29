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
    BasicApp::binaryTree = binaryTree;
}

void BasicApp::draw() {
//    BasicApp::myRenderer.draw();
}

CINDER_APP(BasicApp, ci::app::RendererGl)