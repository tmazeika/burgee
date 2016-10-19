#ifndef BURGEE_WINDOW_H
#define BURGEE_WINDOW_H

#include <memory>
#include <string>

#include <GLFW/glfw3.h>

#include "input.h"

class Window
{
private:
    const int width;
    const int height;
    const std::string title;

    GLFWwindow* window;
    std::shared_ptr<Input> input;

public:
    Window(int width, int height, std::string title);

    void initialize();

    const std::shared_ptr<Input> get_input() const;

    bool should_close() const;

    void swap_and_poll() const;

    ~Window();
};

#endif
