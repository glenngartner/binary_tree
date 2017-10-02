//
// Created by g on 9/30/17.
//

#include "NodeGraphic.h"

NodeGraphic::NodeGraphic(std::shared_ptr<Node> node) {
    this->node = node;
    this->position = {x: 100, y: 200};

}
