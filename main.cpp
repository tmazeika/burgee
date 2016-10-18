#include <iostream>

#include "shader.h"
#include "window.h"

#define S_PER_UPDATE 1.0f / 60.0f

void initialize();
void loop();
void update();
void render(double alpha);

int main()
{
    window.initialize(800, 600, "Burgee");
    initialize();
    loop();

    return 0;
}

GLuint vbo, vao;
Shader shader;

void initialize()
{
    glewExperimental = GL_TRUE;
    glewInit();

    shader.initialize();
    shader.use();

    glClearColor(0, 0, 0, 1);

    // TODO: remove
    const GLfloat vertices[] = {
            -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.0f,  0.5f, 0.0f, 0.0f, 1.0f,
    };
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    shader.set_vert_attrib("position", 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
    shader.set_vert_attrib("color", 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void loop()
{
    double previous = glfwGetTime();
    double lag = 0;
    double current;
    double elapsed;

    while (!window.should_close()) {
        current = glfwGetTime();
        elapsed = current - previous;
        previous = current;
        lag += elapsed;

        while (lag >= S_PER_UPDATE) {
            update();
            lag -= S_PER_UPDATE;
        }

        render(lag / S_PER_UPDATE);
        window.swap_and_poll();
    }
}

void update()
{
    if (window.get_input().is_key_down(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
        return;
    }

    glUniform1f(shader.get_uniform("time"), static_cast<float>(glfwGetTime()));
}

void render(double alpha)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // TODO

    // TODO: remove
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
