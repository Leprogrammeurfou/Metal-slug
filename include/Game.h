#pragma once
#include "Application.h"
#include "MenuPause.h"
#include "Joueur.h"

class MenuPause;

//Le jeu
class Game : public Application {
private:
	//La caméra
	sf::View camera;
	Niveau niveau;
	Joueur* joueur;
public:
	//Initialiser le jeu
	void init();
	//Gérer les évènements du jeu
	void event(sf::Event& _event);
	//Mettre à jour le jeu
	void loop();

};