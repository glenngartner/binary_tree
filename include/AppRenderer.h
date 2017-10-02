//
// Created by g on 9/28/17.
//

#include "Tree.h"

#ifndef BINARY_TREE_APPRENDERER_H
#define BINARY_TREE_APPRENDERER_H


class AppRenderer {
public:
    AppRenderer(std::shared_ptr<Tree> treeLogic);
    void draw();

    std::shared_ptr<Tree> treeLogic;
};


#endif //BINARY_TREE_APPRENDERER_H
