#pragma once
#include "core/baseIncludes.h"

class baseGameState
{
    public:
        baseGameState();

        virtual void baseProcesses();
        virtual void inputLoop(float dt);
        virtual void update(float dt);
        virtual void render();

        void setWindow(sf::RenderWindow* w) { window = w; }
        sf::RenderWindow* getWindow() const { return window; }

    protected:
        sf::RenderWindow* window;
};