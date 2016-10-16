#include "window.h"

int main()
{
    Window window;

    window.initialize(800, 600, "Burgee");

    // TODO
    while (!window.should_close()) {
        glClear(GL_COLOR_BUFFER_BIT);

        window.swap_and_poll();
    }

    return 0;
}
