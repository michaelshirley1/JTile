#include "entities/character/character.h"

character::character(float xStart, float yStart, float xStartDir, float yStartDir)
    : baseObject(xStart, yStart)
{
    
}

void character::update(float dt)
{
    float inputX = 0.f;
    float inputY = 0.f;

    if (!isRolling)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) inputX -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) inputX += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) inputY -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) inputY += 1.f;

        if (inputX != 0.f || inputY != 0.f)
        {
            float len = std::sqrt(inputX * inputX + inputY * inputY);
            lastX = inputX / len;
            lastY = inputY / len;
        }
    }

    const float MAX_SPEED = 2800.f;
    const float ACCELERATION = 5800.f;
    const float DRAG = 0.84f;
    const float STOP_DRAG = 0.5f;

    if (isRolling)
    {
        momentumX = lastX * rollSpeed;
        momentumY = lastY * rollSpeed;
    }
    else
    {
        float length = std::sqrt(inputX * inputX + inputY * inputY);
        if (length > 0.f)
        {
            inputX /= length;
            inputY /= length;
        }

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
    }

    handleRoll();

    baseObject::update(dt);
    sprite.setPosition(x, y);
}

void character::handleDamage(int amount) {
    if (justHit) {
        if (justHitClock.getElapsedTime().asMilliseconds() > justHitCoolDown.asMilliseconds()) {
            justHit = false;
        }
    }
    else {
        justHit = true;
        health -= amount;
        justHitClock.restart();
    }
}

void character::handleRoll()
{
    if (isRolling)
    {
        if (rollClock.getElapsedTime() > rollDuration)
        {
            isRolling = false;
            rollCoolDownClock.restart();
        }
    }
    else if (
        sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
        rollCoolDownClock.getElapsedTime() > rollCoolDown &&
        (lastX != 0.f || lastY != 0.f)
    )
    {
        isRolling = true;
        rollClock.restart();
    }
}

void character::render(sf::RenderWindow* renderWindow) {
    renderWindow->draw(sprite);
}