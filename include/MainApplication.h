//Tu es là ?
#pragma once
#include <SFML\Graphics.hpp>
#include "Application.h"
#include "Niveau.h"

class Application;

class MainApplication {
public:
	//La fenêtre de l'application,
	sf::RenderWindow* fenetre;

	//L'application actuelle
	Application *current;

	//Changer l'application, prend en premier paramètre l'application, en deuxième un booleen indiquant si l'on souhaite supprimer l'application en cours
	void changerApplication(Application* app,bool supprimer = true);

	//Le constructeur
	MainApplication();

	//La fonction permettant de démarrer l'application
	int start();

	//Le destructeur !
	~MainApplication();
};