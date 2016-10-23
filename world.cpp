#include <glm/glm.hpp>

#include "world.h"

World::World(const Shader shader) : shader(shader)
{
    //
}

void World::initialize()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    const float verts[] = {
            -0.75f, -0.75f, 1.0f, 0.0f, 0.0f,
             0.0f ,  0.75f, 0.0f, 1.0f, 0.0f,
             0.75f, -0.75f, 0.0f, 0.0f, 1.0f,
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    shader.set_vert_attrib("position", 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), 0);
    shader.set_vert_attrib("color"   , 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*) (2 * sizeof(GL_FLOAT)));

    glBindVertexArray(0);
}

void World::update()
{
    //
}

void World::render(const float alpha) const
{
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

World::~World()
{
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}
