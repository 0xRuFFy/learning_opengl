
#include "falling_sand_world.hpp"
#include <iostream>

FallingSandWorld::FallingSandWorld() {
    // TODO init
}

FallingSandWorld::~FallingSandWorld() {
    // TODO cleanup
}

void FallingSandWorld::update() {
    // TODO update
}

void FallingSandWorld::processInput(const Window &window) {
    if (window.isMouseClicked(GLFW_MOUSE_BUTTON_LEFT)) {
        auto [cursorX, cursorY] = window.getCursorPos();
        std::cout << cursorX << " " << cursorY << std::endl;
    }
}

