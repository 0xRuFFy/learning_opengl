
#pragma once

#include <GLFW/glfw3.h>

class Window {
    public:
        Window(int width, int height, const char* title);
        ~Window();

        bool shouldClose() noexcept;
        void update() noexcept;

    private:
        GLFWwindow* glfwWindow;
};

