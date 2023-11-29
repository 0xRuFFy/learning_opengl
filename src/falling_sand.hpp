
#pragma once

#include "application.hpp"
#include "window.hpp"

class FallingSand : public Application {
    public:
        FallingSand();
        virtual ~FallingSand();

        void run() override;
        void initialize() override;
        void cleanup() override;

    private:
        Window window;
};

