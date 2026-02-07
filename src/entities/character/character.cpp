#include "entities/character/character.h"

character::character(sf::RenderWindow* renderWindow, float xStart, float yStart)
    : baseObject(renderWindow, xStart, yStart)
{
    shape = sf::CircleShape(10.f);
    shape.setFillColor(sf::Color(100, 250, 50));
}

void character::update(float dt)
{
    const float accel = 600.f;
    const float maxSpeed = 300.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        momentumX -= accel * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        momentumX += accel * dt;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        momentumY -= accel * dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        momentumY += accel * dt;

    momentumX = std::clamp(momentumX, -maxSpeed, maxSpeed);
    momentumY = std::clamp(momentumY, -maxSpeed, maxSpeed);

    baseObject::update(dt);
    shape.setPosition(x, y);
}

void character::render() {
    window->draw(shape);
}