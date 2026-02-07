#pragma once
#include "core/baseIncludes.h"
#include "baseGameState.h"
#include <scenes/game.h>

class root
{
	public:
		void run();
		void gameProcess(float dt, sf::RenderWindow* renderWindow);
		void baseProcesses();
		void inputLoop(float dt);
		void update(float dt);
		void renderLoop(sf::RenderWindow* renderWindow);

		enum gameState
		{
			MAIN_MENU,
			GAMEPLAY,
			OPTIONS_MENU,
			EXIT
		};

		gameState currentState = GAMEPLAY;

	private:
		sf::Clock clock;

		std::unique_ptr<baseGameState> currentScene;

		std::unique_ptr<Game> gameScene;
		//std::unique_ptr<MainMenuState>     menuScene;
		//std::unique_ptr<TitleScreenState>  titleScene;

		sf::RenderWindow* window;
};