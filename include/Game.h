#pragma once
#include "Application.h"

//Le jeu
class Game : public Application {
private:
	Niveau niveau;
public:
	//Initialiser le jeu
	void init();
	//G�rer les �v�nements du jeu
	void event(sf::Event& _event);
	//Mettre � jour le jeu
	void loop();

};