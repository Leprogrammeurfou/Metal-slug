#pragma once
#include "Application.h"
#include "MenuPause.h"
#include "Ennemi.h"

class MenuPause;

//Le jeu
class Game : public Application {
private:
	Niveau niveau;
	Ennemi E;
public:
	//Initialiser le jeu
	void init();
	//G�rer les �v�nements du jeu
	void event(sf::Event& _event);
	//Mettre � jour le jeu
	void loop();

};