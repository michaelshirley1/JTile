#pragma once
#include "core/baseIncludes.h"

class baseObject
{
    public:
        baseObject(float x, float y);
        virtual ~baseObject() = default;

        virtual void update(float dt);
        virtual void render(sf::RenderWindow* renderWindow);

    protected:
        sf::Sprite sprite;
        sf::Texture texture;

        float x = 0.f;
        float y = 0.f;
        float momentumX = 0.f;
        float momentumY = 0.f;
};