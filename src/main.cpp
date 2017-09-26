#include <iostream>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class BasicApp : public ci::app::App {
public:
    void draw() override;
};

void BasicApp::draw() {
    ci::gl::clear();
    gl::pushModelMatrix();

    gl::translate(getWindowCenter());

    int numCircles = 16;
    float radius = getWindowHeight() / 2 - 30;

    for (int c = 0; c < numCircles; ++c){
        float rel = c / (float)numCircles;
        float angle = rel * M_PI * 2;
        vec2 offset(cos (angle), sin(angle));

        gl::pushModelMatrix();
        gl::translate(offset * radius);
        gl::color(Color(CM_HSV, rel, 1,1));
        gl::drawStrokedCircle(vec2(), 30);
        gl::popModelMatrix();
    }

    gl::color((Color(1, 1, 1)));
    gl::drawSolidCircle(vec2(), 15);

    gl::popModelMatrix();
}

CINDER_APP(BasicApp, ci::app::RendererGl)