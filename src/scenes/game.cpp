
#include "core/baseIncludes.h"
#include "scenes/game.h"
#include "entities/character/character.h"

Game::Game(sf::RenderWindow& window)
    : window(window)
{
    player = std::make_unique<character>(&window);
    objects.push_back(std::move(player));
}

void Game::baseProcesses() {

}

void Game::inputLoop(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

    }
}

void Game::update(float dt)
{
    for (auto& obj : objects)
        obj->update(dt);
}

void Game::render()
{
    for (auto& obj : objects)
        obj->render();
}