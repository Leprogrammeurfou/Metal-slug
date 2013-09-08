#pragma once
#include "Application.h"
#include "MenuPause.h"
#include "Ennemi.h"

class MenuPause;

//Le jeu
class Game : public Application {
private:
	Niveau niveau;
	Humain humain;
public:
	//Initialiser le jeu
	void init();
	//Gérer les évènements du jeu
	void event(sf::Event& _event);
	//Mettre à jour le jeu
	void loop();

};