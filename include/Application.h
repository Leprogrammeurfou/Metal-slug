#pragma once
#include <SFML\Graphics.hpp>
#include "MainApplication.h"

class MainApplication;

class Application {
public:
	//L'application principale
	static MainApplication* main_app;

	//La fonction qui initialise l'application
	virtual void init() = 0;
	//La fonction qui recevra les évènements
	virtual void event(sf::Event& _event) = 0;
	//La boucle
	virtual void loop() = 0;
};