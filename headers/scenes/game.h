#pragma once
#include "core/baseIncludes.h"
#include "core/baseGameState.h"
#include "entities/character/character.h"
#include "entities/baseObject.h"

class Game: public baseGameState
{
    public:
        Game(sf::RenderWindow& window);
        void baseProcesses();
        void inputLoop(float dt);
        void update(float dt);
        void render(sf::RenderWindow* renderWindow);

    private:
        std::vector<std::unique_ptr<baseObject>> objects;
        std::unique_ptr<character> player;
};