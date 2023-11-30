
#pragma once

#include "window.hpp"

class Application {
public:
    Application();
    ~Application();

    void run();

private:
    Window window;
    uint32_t VBO{}, VAO{}, EBO{}, shaderProgram;

    void update();
    void render() const;
    void processInput();
};
