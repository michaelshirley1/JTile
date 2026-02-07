#pragma once
#include "entities/baseObject.h"
#include "core/baseIncludes.h"

class character : public baseObject
{
    public:
        character(sf::RenderWindow* renderWindow, float xStart, float yStart);
        void update(float dt) override;
        void render() override;
        sf::CircleShape shape;
};
