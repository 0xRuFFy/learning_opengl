#include <glad/glad.h>
#include <iostream>
#include "application.hpp"

Application::Application() : window(800, 600, "Learning OpenGL") {
    // learnopengl.com
    // Hello Triangle
    // https://learnopengl.com/Getting-started/Hello-Triangle
    // Vertex input
}

void Application::run() {
    while (!window.shouldClose()) {
        processInput();

        update();

        render();

        window.update();
    }
}

void Application::update() {
    // TODO update
}

void Application::render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Application::processInput() {
    if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
        window.close();
    }

    if (window.isMouseClicked(GLFW_MOUSE_BUTTON_LEFT)) {
        auto [cursorX, cursorY] = window.getCursorPos();
        std::cout << cursorX << " " << cursorY << std::endl;
    }
}
