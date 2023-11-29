
#include <cstdint>
#include <iostream>
#include <glad/glad.h>
#include "falling_sand_world.hpp"

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

FallingSandWorld::FallingSandWorld() {
    // TODO init

    float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

    uint32_t VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    uint32_t vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

FallingSandWorld::~FallingSandWorld() {
    // TODO cleanup
}

void FallingSandWorld::update() {
    // TODO update
}

void FallingSandWorld::processInput(const Window &window) {
    if (window.isMouseClicked(GLFW_MOUSE_BUTTON_LEFT)) {
        auto [cursorX, cursorY] = window.getCursorPos();
        std::cout << cursorX << " " << cursorY << std::endl;
    }
}
