
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"

Window::Window(int width, int height, const char* title) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    std::cout << "GLFW initialized" << std::endl;

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

    std::cout << "GLAD initialized" << std::endl; 

    glViewport(0, 0, 800, 600);
}

Window::~Window() {
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
}

bool Window::shouldClose() noexcept {
    return glfwWindowShouldClose(glfwWindow);
}

void Window::close() noexcept {
    glfwSetWindowShouldClose(glfwWindow, GLFW_TRUE);
}

bool Window::isKeyPressed(int keyCode) noexcept {
    return glfwGetKey(glfwWindow, keyCode) == GLFW_PRESS;
}

std::pair<double, double> Window::getCursorPos() noexcept {
    double x, y;
    glfwGetCursorPos(glfwWindow, &x, &y);
    return std::make_pair(x, y);
}

bool Window::isMousePressed(int button) noexcept {
    return glfwGetMouseButton(glfwWindow, button) == GLFW_PRESS;
}

bool Window::isMouseClicked(int button) noexcept {
    static bool wasPressed = false;
    bool isPressed = glfwGetMouseButton(glfwWindow, button) == GLFW_PRESS;

    if (isPressed && !wasPressed) {
        wasPressed = true;
        return true;
    } else if (!isPressed) {
        wasPressed = false;
    }

    return false;
}

void Window::update() noexcept {
    glfwSwapBuffers(glfwWindow);
    glfwPollEvents();
}
