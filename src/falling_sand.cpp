
#include <glad/glad.h>
#include "falling_sand.hpp"

FallingSand::FallingSand() : window(800, 600, "Falling Sand") {
    // TODO setup
}

FallingSand::~FallingSand() {
    // TODO cleanup
}

void FallingSand::run() {
    while (!window.shouldClose()) {
        // TODO update
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.update();
    }
}

void FallingSand::initialize() {
    // TODO initialize
}

void FallingSand::cleanup() {
    // TODO cleanup
}

