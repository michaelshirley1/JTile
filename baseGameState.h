#pragma once
#include "headers/baseIncludes.h"

class baseGameState
{
	public:
		baseGameState();
		void run();
		void inputLoop();
		void renderLoop();
		void baseProcesses();
		void setWindow(sf::RenderWindow* window);
		sf::RenderWindow* getWindow();

	private:
		sf::RenderWindow* window;
};