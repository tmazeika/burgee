#include "shader.h"
#include "window.h"

#define MS_PER_UPDATE 16

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

void initialize()
{
    glewExperimental = GL_TRUE;
    glewInit();

    Shader shader;
    shader.initialize();
    shader.use();

    glClearColor(0, 0, 0, 1);

    // TODO: remove
    const GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f,
    };
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    glEnableVertexAttribArray(0);
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

        while (lag >= MS_PER_UPDATE) {
            update();
            lag -= MS_PER_UPDATE;
        }

        render(lag / MS_PER_UPDATE);
        window.swap_and_poll();
    }
}

void update()
{
    // TODO
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
