#include <BasicApp.h>
#include "GL_Renderer.h"
#include <memory>


int main() {
    // start the app logic
    std::shared_ptr<BasicApp> newApp = std::make_shared<BasicApp>();
    newApp->setup();

    // launch the openGL visuals
//    std::shared_ptr<GL_Renderer> renderer = std::make_shared<GL_Renderer>();
    GL_Renderer *renderer = new GL_Renderer();
    renderer->setup();
    renderer->draw();

    return 0;
}

