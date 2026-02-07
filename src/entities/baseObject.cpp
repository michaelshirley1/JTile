#include "entities/baseObject.h"

baseObject::baseObject(sf::RenderWindow* renderWindow, float xStart, float yStart)
    : window(renderWindow)
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

void baseObject::render()
{
    window->draw(sprite);
}