//
// Created by g on 10/1/17.
//

#include "TreeGraphic.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"

TreeGraphic::TreeGraphic(std::shared_ptr<Tree> treeLogic) {

    this->drawNodeGraphic(treeLogic->rootNode, cinder::app::getWindowCenter().x, 100);

}

void TreeGraphic::drawNodeGraphic(std::shared_ptr<Node> nodeLogic, int x, int y) {
    cinder::gl::pushModelMatrix();

    cinder::gl::translate(cinder::vec2(x, y));

    cinder::gl::drawStrokedCircle(cinder::vec2(), 40, 32);

    cinder::TextLayout textLayout;
    textLayout.clear(cinder::ColorAT<float>(0.1f, 0.1f, 0.1f, 0.7f));
    textLayout.setColor(cinder::Color(0.9f, 0.9f, 0.9f));
    textLayout.setFont(cinder::Font("Arial Black", 30));
    textLayout.addCenteredLine("Test Word");
//    cinder::Surface rendered = textLayout.render(true);
//    std::shared_ptr<cinder::gl::Texture> mTexture = std::make_shared<cinder::gl::Texture>(rendered);

    cinder::gl::popModelMatrix();
}


