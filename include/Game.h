#pragma once
#include "Application.h"

//Le jeu
class Game : public Application {
private:
	Niveau niveau;
public:
	//Initialiser le jeu
	void init();
	//Gérer les évènements du jeu
	void event(sf::Event& _event);
	//Mettre à jour le jeu
	void loop();

};