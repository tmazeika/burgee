#ifndef BURGEE_SHADER_H
#define BURGEE_SHADER_H

#include <GL/glew.h>

class Shader
{
private:
    GLuint program;
public:
    void initialize();

    void use();
};

#endif
