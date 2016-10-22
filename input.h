#ifndef BURGEE_INPUT_H
#define BURGEE_INPUT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Input
{
private:
    GLFWwindow *window;
    int down_mod_keys;
    bool down_keys[349];

public:
    Input();

    Input(GLFWwindow *window);

    void register_key_callback();

    void on_key_action(int mods, int key, int action);

    bool is_mod_key_down(int mod_key) const;

    bool is_key_down(int key) const;
};

#endif
