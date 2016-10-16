#ifndef BURGEE_WINDOW_H
#define BURGEE_WINDOW_H

#include <string>

#include <GLFW/glfw3.h>

#include "glfw_exception.h"

static class Window
{
private:
    GLFWwindow* window;
public:
    void initialize(int width, int height, std::string title) throw(GlfwException);

    bool should_close() const;

    void set_should_close(bool should_close) const;

    void swap_and_poll() const;

    ~Window();
} window;

#endif
