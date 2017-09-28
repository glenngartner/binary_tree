#include <iostream>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "AppRenderer.h"
#include "Node.h"
#include <string>

using namespace ci;
using namespace ci::app;

class BasicApp : public ci::app::App {
public:
    AppRenderer myRenderer;
    std::shared_ptr <Node> newNode;

    void setup() override;

    void draw() override;
};

void BasicApp::setup() {
    std::string name = "G";
    BasicApp::myRenderer;
    std::shared_ptr<Node> newNode(new Node(name, 22));
    BasicApp::newNode = newNode;
    newNode->information = "Hello World";
}

void BasicApp::draw() {
    BasicApp::myRenderer.draw();
}

CINDER_APP(BasicApp, ci::app::RendererGl)