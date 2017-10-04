//
// Created by g on 10/2/17.
//
#include "glfw/glfw3.h"

#ifndef STARTER01_GL_RENDERER_H
#define STARTER01_GL_RENDERER_H


class GL_Renderer {
public:
    GLFWwindow *window;
    int shaderProgram;
    int VAO;

    void setup();
    void draw();
    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
    void processInput(GLFWwindow *window);
    int buildShaderProgram();
    int createGeo();
};


#endif //STARTER01_GL_RENDERER_H
