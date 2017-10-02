//
// Created by g on 9/30/17.
//

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "AppRenderer.h"
#include "Tree.h"

#ifndef BINARY_TREE_BASICAPP_H
#define BINARY_TREE_BASICAPP_H


class BasicApp : public ci::app::App {
public:

    BasicApp();

    std::shared_ptr<AppRenderer> myRenderer;
    std::shared_ptr<Tree> binaryTree;

    void setup() override;

    void draw() override;
};


#endif //BINARY_TREE_BASICAPP_H
