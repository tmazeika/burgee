#ifndef BURGEE_GAME_H
#define BURGEE_GAME_H

#include <memory>
#include <vector>

#include "input.h"
#include "renderable.h"
#include "shader.h"

class Game : public Renderable
{
private:
    const Shader shader;
    const std::shared_ptr<Input> input;

    bool close;
    std::vector<std::shared_ptr<Renderable>> game_objects;

public:
    Game(const Shader shader, const std::shared_ptr<Input>);

    void initialize();

    void update() override;

    void render(const float alpha) const override;

    bool should_close() const;
};

#endif
