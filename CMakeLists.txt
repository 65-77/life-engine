# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(life-engine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Add source files
set(SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Add Glad source file
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/dep/glad/src/glad.c)

# Include directories for Glad and GLFW
include_directories(
    ${CMAKE_SOURCE_DIR}/dep/glad/include
    ${CMAKE_SOURCE_DIR}/dep/glad/include/glad
    ${CMAKE_SOURCE_DIR}/dep/glad/include/KHR
)

# Find GLFW package
find_package(glfw3 REQUIRED)

# Add executable and link libraries (OpenGL and GLFW)
add_executable(life-engine ${SOURCE_FILES} ${GLAD_SRC})
target_link_libraries(life-engine OpenGL::GL glfw)

# Ensure the correct C++ standard is used
target_compile_features(life-engine PRIVATE cxx_std_11)

