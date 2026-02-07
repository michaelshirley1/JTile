#include "core/root.h"
#include "core/baseIncludes.h"

#define WIN_WIDTH 1600
#define WIN_HEIGHT 900

void root::run()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;

    sf::RenderWindow windowBase(
        sf::VideoMode(WIN_WIDTH, WIN_HEIGHT),
        "Open Explore",
        sf::Style::Default,
        settings
    );

    window = &windowBase;
    window->setFramerateLimit(60);

    gameScene = std::make_unique<Game>(*window);

    currentScene = std::move(gameScene);

    sf::Clock clock;

    while (window->isOpen())
    {
        float dt = clock.restart().asSeconds();
        gameProcess(dt, window);
    }
}

void root::gameProcess(float dt, sf::RenderWindow* renderWindow)
{
    baseProcesses();
    inputLoop(dt);
    update(dt);
    renderLoop(renderWindow);
}

void root::baseProcesses()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void root::inputLoop(float dt)
{
    currentScene->inputLoop(dt);
}

void root::update(float dt)
{
    currentScene->update(dt);
}

void root::renderLoop(sf::RenderWindow* renderWindow)
{
    window->clear();

    currentScene->render(renderWindow);

    window->display();
}