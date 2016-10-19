#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "shader.h"
#include "window.h"
#include "renderable.h"
#include "world.h"

#define S_PER_UPDATE 1.0f / 60.0f

void initialize();
void loop();
void update();
void render(const float alpha);

int main()
{
    window.initialize(800, 600, "Burgee");
    initialize();
    loop();

    return 0;
}

Shader shader;
std::vector<std::shared_ptr<Renderable>> renderables;

void initialize()
{
    glewExperimental = GL_TRUE;
    glewInit();

    shader.initialize();
    shader.use();

    glClearColor(0, 0, 0, 1);

    const std::shared_ptr<Renderable> world_ptr = std::make_shared<World>(shader);

    renderables.push_back(world_ptr);
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

        render(static_cast<float>(lag) / S_PER_UPDATE);
        window.swap_and_poll();
    }
}

void update()
{
    if (window.get_input().is_key_down(GLFW_KEY_ESCAPE)) {
        window.set_should_close(true);
        return;
    }

    std::for_each(renderables.begin(), renderables.end(), [](std::shared_ptr<Renderable> renderable_ptr) {
        renderable_ptr->update();
    });
}

void render(const float alpha)
{
    glClear(GL_COLOR_BUFFER_BIT);

    std::for_each(renderables.begin(), renderables.end(), [alpha](std::shared_ptr<Renderable> renderable_ptr) {
        renderable_ptr->render(alpha);
    });
}

