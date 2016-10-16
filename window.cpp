#include "window.h"

// TODO: probably don't want to exit instantly on ESC
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

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

    // TODO
    glfwSetKeyCallback(this->window, key_callback);
}

bool Window::should_close()
{
    return glfwWindowShouldClose(this->window) == GLFW_TRUE;
}

void Window::set_should_close(bool should_close)
{
    glfwSetWindowShouldClose(this->window, should_close);
}

void Window::swap_and_poll()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}
