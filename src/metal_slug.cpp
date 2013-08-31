// metal_slug.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "MainApplication.h"
#include "Game.h"

int main()
{
	//On met le jeu comme application en cours
	Application::main_app->changerApplication(new Game());
	//On d�marre l'application principale
	int result = Application::main_app->start();
	//On supprime l'application principal
	delete Application::main_app;
	//On retourne le r�sultat
	return result;
}

