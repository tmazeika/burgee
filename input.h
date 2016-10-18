#ifndef BURGEE_INPUT_H
#define BURGEE_INPUT_H

#include <GLFW/glfw3.h>

class Input
{
public:
    bool down_keys[349];
    int down_mod_keys;

    void initialize(GLFWwindow *window);

    bool is_key_down(int key) const;

    bool is_mod_key_down(int mod_key) const;
};

#endif
