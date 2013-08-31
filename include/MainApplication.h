//Tu es l� ?
#pragma once
#include <SFML\Graphics.hpp>
#include "Application.h"
#include "Niveau.h"

class Application;

class MainApplication {
public:
	//La fen�tre de l'application,
	sf::RenderWindow* fenetre;

	//L'application actuelle
	Application *current;

	//Changer l'application, prend en premier param�tre l'application, en deuxi�me un booleen indiquant si l'on souhaite supprimer l'application en cours
	void changerApplication(Application* app,bool supprimer = true);

	//Le constructeur
	MainApplication();

	//La fonction permettant de d�marrer l'application
	int start();

	//Le destructeur !
	~MainApplication();
};