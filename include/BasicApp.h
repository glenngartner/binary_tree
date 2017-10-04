//
// Created by g on 9/30/17.
//

#include "Tree.h"

#ifndef BINARY_TREE_BASICAPP_H
#define BINARY_TREE_BASICAPP_H


class BasicApp  {
public:

    BasicApp();

    std::shared_ptr<Tree> binaryTree;

    void setup();

    void draw();
};


#endif //BINARY_TREE_BASICAPP_H
