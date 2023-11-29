
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"

Window::Window(int width, int height, const char* title) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


    glfwWindow = glfwCreateWindow(800, 600, "Falling Sand", NULL, NULL);
    if (!glfwWindow) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();

    if (!monitor) {
        throw std::runtime_error("Failed to get primary monitor");
    }

    const GLFWvidmode *mode = glfwGetVideoMode(monitor);

    if (!mode) {
        throw std::runtime_error("Failed to get video mode");
    }

    glfwSetWindowPos(glfwWindow, (mode->width - width) / 2, (mode->height - height) / 2);


    glfwMakeContextCurrent(glfwWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glViewport(0, 0, 800, 600);
}

Window::~Window() {
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
}

bool Window::shouldClose() noexcept {
    return glfwWindowShouldClose(glfwWindow);
}

void Window::update() noexcept {
    glfwSwapBuffers(glfwWindow);
    glfwPollEvents();
}
