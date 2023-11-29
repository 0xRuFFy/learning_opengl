
#pragma once

#include <GLFW/glfw3.h>
#include <utility>

class Window {
    public:
        Window(int width, int height, const char* title);
        ~Window();

        [[nodiscard]] bool shouldClose() const noexcept;
        [[nodiscard]] bool isKeyPressed(int keyCode) const noexcept;
        [[nodiscard]] bool isMousePressed(int button) const noexcept;
        [[nodiscard]] bool isMouseClicked(int button) const noexcept;
        [[nodiscard]] std::pair<double, double> getCursorPos() const noexcept;
        void update() noexcept;
        void close() noexcept;

    private:
        GLFWwindow* glfwWindow;
};

