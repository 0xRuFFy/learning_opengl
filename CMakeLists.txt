cmake_minimum_required(VERSION 3.12)

project(LearningOpenGL)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Dont build docs/tests/examples of GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add source files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Add header files
# file(GLOB_RECURSE HEADER_FILES "include/*.hpp" "include/*.h" "src/*.hpp" "src/*.h")

# Add header files
include_directories(include)
include_directories(external/glad/include)

# Add Glad
add_library(glad STATIC "external/glad/src/glad.c")

# Add GLFW
add_subdirectory(external/glfw)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)
