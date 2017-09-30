//
// Created by g on 9/28/17.
//
#include "iostream"
#include "AppRenderer.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "Tree.h"

AppRenderer::AppRenderer(std::shared_ptr<Tree> treeLogic) {
    std::cout << "myRenderer started" << std::endl;
}

void AppRenderer::draw() {
    cinder::gl::clear();

    ci::gl::clear();
    cinder::gl::pushModelMatrix();

    cinder::gl::translate(cinder::app::getWindowCenter());

    int numCircles = 16;
    float radius = cinder::app::getWindowHeight() / 2 - 30;

    for (int c = 0; c < numCircles; ++c) {
        float rel = c / (float) numCircles;
        float angle = rel * M_PI * 2;
        cinder::vec2 offset(cos(angle), sin(angle));

        cinder::gl::pushModelMatrix();
        cinder::gl::translate(offset * radius);
        cinder::gl::color(cinder::Color(cinder::CM_HSV, rel, 1, 1));
        cinder::gl::drawStrokedCircle(cinder::vec2(), 30);
        cinder::gl::popModelMatrix();
    }

    cinder::gl::color((cinder::Color(1, 1, 1)));
    cinder::gl::drawSolidCircle(cinder::vec2(), 15);

    cinder::gl::popModelMatrix();
}


