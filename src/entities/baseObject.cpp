#include "entities/baseObject.h"

baseObject::baseObject(float xStart, float yStart)
{
    x = xStart;
    y = yStart;
}

void baseObject::update(float dt)
{
    x += momentumX * dt;
    y += momentumY * dt;
    sprite.setPosition(x, y);
}

void baseObject::render(sf::RenderWindow* renderWindow)
{
    renderWindow->draw(sprite);
}