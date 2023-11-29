
#pragma once

#include "../application/application.hpp"
#include "../application/window.hpp"

class FallingSand : public Application {
    public:
        FallingSand();
        virtual ~FallingSand();

        void run() override;

    private:
        Window window;

        void processInput();
};

