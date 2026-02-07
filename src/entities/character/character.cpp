#include "entities/character/character.h"

character::character(float xStart, float yStart)
    : baseObject(xStart, yStart)
    , shape(20.f)
{
    shape.setFillColor(sf::Color(100, 250, 50));
}

void character::update(float dt)
{
    float inputX = 0.f;
    float inputY = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) inputX -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) inputX += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) inputY -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) inputY += 1.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))

    float length = std::sqrt(inputX * inputX + inputY * inputY);

    if (length > 0.f)
    {
        inputX /= length;
        inputY /= length;
    }

    const float MAX_SPEED = 2800.f;
    const float ACCELERATION = 5800.f;
    const float DRAG = 0.84f;
    const float STOP_DRAG = 0.5f;

    momentumX += inputX * ACCELERATION * dt;
    momentumY += inputY * ACCELERATION * dt;

    float currentDrag = (length > 0.01f) ? DRAG : STOP_DRAG;
    momentumX *= currentDrag;
    momentumY *= currentDrag;

    float currentSpeed = std::sqrt(momentumX * momentumX + momentumY * momentumY);

    if (currentSpeed > MAX_SPEED)
    {
        float scale = MAX_SPEED / currentSpeed;
        momentumX *= scale;
        momentumY *= scale;
    }

    if (currentSpeed < 1.f)
    {
        momentumX = 0.f;
        momentumY = 0.f;
    }

    baseObject::update(dt);

    shape.setPosition(x, y);
}

void character::render(sf::RenderWindow* renderWindow) {
    renderWindow->draw(shape);
}