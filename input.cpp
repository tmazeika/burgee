#include "input.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Input *input = static_cast<Input*>(glfwGetWindowUserPointer(window));

    input->on_key_action(mods, key, action);
}

Input::Input()
{
    //
}

Input::Input(GLFWwindow *window) : window(window), down_mod_keys(0), down_keys({})
{
    //
}

void Input::register_key_callback()
{
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, key_callback);
}

void Input::on_key_action(int mods, int key, int action)
{
    down_mod_keys = mods;
    down_keys[key] = (action == GLFW_PRESS);
}

bool Input::is_mod_key_down(int mod_key) const
{
    return (down_mod_keys & mod_key) != 0;
}

bool Input::is_key_down(int key) const
{
    return down_keys[key];
}
