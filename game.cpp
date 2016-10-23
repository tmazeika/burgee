#include <algorithm>
#include <iostream>

#include "game.h"
#include "world.h"

Game::Game(const Shader shader, const std::shared_ptr<Input> input)
        : shader(shader), input(input)
{
    //
}

void Game::initialize()
{
    const auto world_ptr = std::make_shared<World>(shader);
    world_ptr->initialize();

    game_objects.push_back(world_ptr);
}

void Game::update()
{
    if (input->is_key_down(GLFW_KEY_ESCAPE)) {
        close = true;
        return;
    }

    std::for_each(game_objects.begin(), game_objects.end(), [](std::shared_ptr<Renderable> renderable) {
        renderable->update();
    });
}

void Game::render(const float alpha) const
{
    glClearColor(0, 0, 0, 1);
    shader.use();

    std::for_each(game_objects.begin(), game_objects.end(), [alpha](std::shared_ptr<Renderable> renderable) {
        renderable->render(alpha);
    });
}

bool Game::should_close() const
{
    return close;
}
