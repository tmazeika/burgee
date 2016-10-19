#ifndef BURGEE_GAME_H
#define BURGEE_GAME_H

#include <vector>
#include <memory>

#include "renderable.h"
#include "shader.h"
#include "input.h"

class Game : public Renderable
{
private:
    Shader shader;
    const std::shared_ptr<Input> input;

    bool close;
    std::vector<std::shared_ptr<Renderable>> game_objects;

public:
    Game(const std::shared_ptr<Input>);

    void initialize();

    void update() override;

    void render(const float alpha) const override;

    bool should_close() const;
};

#endif
