#ifndef BURGEE_WINDOW_H
#define BURGEE_WINDOW_H

#include <string>

#include <GLFW/glfw3.h>

#include "glfw_exception.h"
#include "input.h"

static class Window
{
private:
    GLFWwindow* window;
    Input input;
public:
    void initialize(int width, int height, std::string title) throw(GlfwException);

    Input get_input() const;

    bool should_close() const;

    void set_should_close(bool should_close) const;

    void swap_and_poll() const;

    ~Window();
} window;

#endif
