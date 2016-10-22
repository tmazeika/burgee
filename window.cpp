#include <iostream>
#include <stdlib.h>

#include "window.h"

Window::Window(int width, int height, std::string title)
        : width(width), height(height), title(title)
{
    //
}

void Window::initialize()
{
    if (glfwInit() != GLFW_TRUE) {
        std::cerr << "Could not initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_SAMPLES, 8);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (window == NULL)
    {
        std::cerr << "Could not create GLFW window" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    input = std::make_shared<Input>(window);
    input->register_key_callback();
}

const std::shared_ptr<Input> Window::get_input() const
{
    return input;
}

bool Window::should_close() const
{
    return glfwWindowShouldClose(window) == GLFW_TRUE;
}

void Window::swap_and_poll() const
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
