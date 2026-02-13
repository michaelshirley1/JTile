#pragma once
#include "entities/baseObject.h"
#include "core/baseIncludes.h"

class character : public baseObject
{
    public:

        sf::Sprite sprite;

        int health = 100;
        boolean isRolling = false;
        boolean justHit = false;

        character(float xStart, float yStart);

        void update(float dt) override;
        void render(sf::RenderWindow* renderWindow) override;

    private:
        sf::Clock rollClock;
        sf::Clock justHitClock;
        sf::Clock rollCoolDownClock;

        sf::Time rollDuration = sf::milliseconds(30);
        sf::Time rollCoolDown = sf::milliseconds(500);
        sf::Time justHitCoolDown = sf::milliseconds(100);

        float lastX = 0;
        float lastY = 0;

        float rollSpeed = 2000.f;

        void handleRoll();
        void handleDamage(int amount);
};
