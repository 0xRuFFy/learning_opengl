
#pragma once

#include "../application/window.hpp"

class FallingSandWorld {
   public:
       FallingSandWorld();
       ~FallingSandWorld();

       void update();
       void processInput(const Window &window);
};

