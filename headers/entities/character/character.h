#pragma once
#include "entities/baseObject.h"
#include "core/baseIncludes.h"

class character : public baseObject
{
    public:
        character(float xStart, float yStart);

        void update(float dt) override;
        void render(sf::RenderWindow* renderWindow) override;

        sf::CircleShape shape;

        //attributes
        int health = 100;
        boolean isRolling;
        boolean justHit;

    private:
        void handleRoll();
        void handleDamage(int amount);

};
