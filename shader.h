#ifndef BURGEE_SHADER_H
#define BURGEE_SHADER_H

#include <string>

#include <GL/glew.h>

class Shader
{
private:
    GLuint program;
public:
    void initialize();

    void use();

    void set_vert_attrib(std::string name, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
                         const void *pointer);

    GLint get_uniform(std::string uniform);

    ~Shader();
};

#endif
