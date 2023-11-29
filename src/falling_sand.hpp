
#pragma once

#include "application.hpp"
#include "window.hpp"

class FallingSand : public Application {
    public:
        FallingSand();
        virtual ~FallingSand();

        void run() override;

    private:
        Window window;

        void processInput();
};

