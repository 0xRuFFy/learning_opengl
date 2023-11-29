cmake_minimum_required(VERSION 3.12)

project(LearningOpenGL)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Add header files
# file(GLOB_RECURSE HEADER_FILES "include/*.hpp" "include/*.h" "src/*.hpp" "src/*.h")

# Add header files
include_directories(include)

# Add Glad
add_library(glad STATIC "include/glad/glad.c")

# Add GLFW
add_subdirectory(external/glfw)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)
