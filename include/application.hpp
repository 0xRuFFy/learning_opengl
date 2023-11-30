
#pragma once

#include "window.hpp"

class Application {
public:
    Application();
    ~Application() = default;

    void run();

private:
    Window window;

    void update();
    void render();
    void processInput();
};
