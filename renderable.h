#ifndef BURGEE_RENDERABLE_H
#define BURGEE_RENDERABLE_H

class Renderable
{
public:
    virtual void update() const = 0;

    virtual void render(const float alpha) const = 0;
};

#endif
