#pragma once

#include "Menu.h"
#include "Application.h"
#include "Game.h"
#include "MainApplication.h"
#include "MainMenu.h"

class Game;
class MenuPause : public Application {
private:
	Menu menu;
public:
	
	static Game* jeu;
	MenuPause(Game* game);
	void init();
	void event(sf::Event& _event);
	void loop();
};