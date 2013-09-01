// metal_slug.cpp : définit le point d'entrée pour l'application console.
//

#include "MainApplication.h"
#include "MainMenu.h"

int main()
{
	//On met le jeu comme application en cours
	Application::main_app->changerApplication(new MainMenu());
	//On démarre l'application principale
	int result = Application::main_app->start();
	//On supprime l'application principal
	delete Application::main_app;
	//On retourne le résultat
	return result;
}

