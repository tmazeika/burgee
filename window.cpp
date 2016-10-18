#include "window.h"

void Window::initialize(int width, int height, std::string title) throw(GlfwException)
{
    if (!glfwInit()) {
        throw GlfwException();
    }

    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (!this->window)
    {
        throw GlfwException();
    }

    glfwMakeContextCurrent(this->window);
    this->input.initialize(this->window);
}

Input Window::get_input() const
{
    return this->input;
}

bool Window::should_close() const
{
    return glfwWindowShouldClose(this->window) == GLFW_TRUE;
}

void Window::set_should_close(bool should_close) const
{
    glfwSetWindowShouldClose(this->window, should_close);
}

void Window::swap_and_poll() const
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}
