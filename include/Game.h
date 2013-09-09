#pragma once
#include "Application.h"
#include "MenuPause.h"
#include "Joueur.h"

class MenuPause;

//Le jeu
class Game : public Application {
private:
	//La cam�ra
	sf::View camera;
	Niveau niveau;
	Joueur* joueur;
public:
	//Initialiser le jeu
	void init();
	//G�rer les �v�nements du jeu
	void event(sf::Event& _event);
	//Mettre � jour le jeu
	void loop();

};