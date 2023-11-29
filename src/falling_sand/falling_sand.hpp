
#pragma once

#include "../application/application.hpp"
#include "../application/window.hpp"
#include "falling_sand_world.hpp"

class FallingSand : public Application {
    public:
        FallingSand();
        virtual ~FallingSand();

        void run() override;

    private:
        Window window;
        FallingSandWorld world;

        void processInput();
};

