
#pragma once

#include "window.hpp"

class FallingSandWorld {
public:
    FallingSandWorld();
    ~FallingSandWorld();

    void update();
    void processInput(const Window &window);
};
