
#pragma once

#include <GLFW/glfw3.h>
#include <utility>

class Window {
    public:
        Window(int width, int height, const char* title);
        ~Window();

        bool shouldClose() const noexcept;
        void close() noexcept;
        bool isKeyPressed(int keyCode) const noexcept;
        std::pair<double, double> getCursorPos() const noexcept;
        bool isMousePressed(int button) const noexcept;
        bool isMouseClicked(int button) const noexcept;
        void update() noexcept;

    private:
        GLFWwindow* glfwWindow;
};

