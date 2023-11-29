
#pragma once

#include <GLFW/glfw3.h>
#include <utility>

class Window {
    public:
        Window(int width, int height, const char* title);
        ~Window();

        bool shouldClose() noexcept;
        void close() noexcept;
        bool isKeyPressed(int keyCode) noexcept;
        std::pair<double, double> getCursorPos() noexcept;
        bool isMousePressed(int button) noexcept;
        bool isMouseClicked(int button) noexcept;
        void update() noexcept;

    private:
        GLFWwindow* glfwWindow;
};

