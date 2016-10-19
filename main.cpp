#include "GL/glew.h"
#include "window.h"
#include "game.h"

#define S_PER_UPDATE 1.0f / 60.0f

void loop(const Window, Game);

int main()
{
    Window window(800, 600, "Burgee");
    window.initialize();

    // initialize GLEW
    glewExperimental = GL_TRUE;
    glewInit();

    Game game(window.get_input());
    game.initialize();

    loop(window, game);

    return 0;
}

void loop(const Window window, Game game)
{
    double previous = glfwGetTime();
    double lag = 0;
    double current;
    double elapsed;

    while (!window.should_close() && !game.should_close()) {
        current = glfwGetTime();
        elapsed = current - previous;
        previous = current;
        lag += elapsed;

        while (lag >= S_PER_UPDATE) {
            game.update();
            lag -= S_PER_UPDATE;
        }

        game.render(static_cast<float>(lag) / S_PER_UPDATE);
        window.swap_and_poll();
    }
}
