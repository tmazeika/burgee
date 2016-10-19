#ifndef BURGEE_WORLD_H
#define BURGEE_WORLD_H

#include <GL/glew.h>

#include "renderable.h"
#include "shader.h"

class World : public Renderable
{
private:
    const Shader shader;

    GLuint vao;
    GLuint vbo;

public:
    World(const Shader);

    void initialize();

    void update() override;

    void render(const float alpha) const override;

    ~World();
};

#endif
