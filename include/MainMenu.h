#pragma once

#include <SFML\Graphics.hpp>
#include "Application.h"
#include "Menu.h"
#include "Game.h"

class MainMenu : public Application {
private:
	Menu menu;
public:
	void init();
	void event(sf::Event& _event);
	void loop();
};

void quitter();