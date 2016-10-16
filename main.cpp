#include "window.h"

#define MS_PER_UPDATE 16

void loop(Window window);
void update();
void render(double alpha);

int main()
{
    Window window;
    window.initialize(800, 600, "Burgee");

    loop(window);

    return 0;
}

void loop(Window window)
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
}
