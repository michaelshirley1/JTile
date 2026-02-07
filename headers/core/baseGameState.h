#pragma once
#include "core/baseIncludes.h"

class baseGameState
{
    public:
        baseGameState();

        virtual void baseProcesses();
        virtual void inputLoop(float dt);
        virtual void update(float dt);
        virtual void render(sf::RenderWindow* renderWindow);
};