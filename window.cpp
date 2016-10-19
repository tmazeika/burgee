#include <iostream>

#include "window.h"

Window::Window(int width, int height, std::string title)
        : width(width), height(height), title(title)
{
    //
}

void Window::initialize()
{
    if (!glfwInit()) {
        std::cerr << "Could not initialize GLFW" << std::endl;
        return;
    }

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (!window)
    {
        std::cerr << "Could not create GLFW window" << std::endl;
        return;
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
