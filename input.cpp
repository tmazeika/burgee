#include "input.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Input* input = static_cast<Input*>(glfwGetWindowUserPointer(window));

    input->down_keys[key] = (action == GLFW_PRESS);
    input->down_mod_keys = mods;
}

void Input::initialize(GLFWwindow *window)
{
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, key_callback);
}

bool Input::is_key_down(int key) const
{
    return this->down_keys[key];
}

bool Input::is_mod_key_down(int mod_key) const
{
    return (this->down_mod_keys & mod_key) != 0;
}
