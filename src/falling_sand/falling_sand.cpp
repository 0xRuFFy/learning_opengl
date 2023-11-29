
#include <glad/glad.h>
#include <iostream>
#include "falling_sand.hpp"

FallingSand::FallingSand() : window(800, 600, "Falling Sand") {
    world = FallingSandWorld();
}

FallingSand::~FallingSand() {
    // TODO cleanup
}

void FallingSand::run() {
    while (!window.shouldClose()) {
        processInput();

        // TODO update
        world.update();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.update();
    }
}

void FallingSand::processInput() {
    if (window.isKeyPressed(GLFW_KEY_ESCAPE)) {
        window.close();
    }

    world.processInput(window);
}
