#include "MenuPause.h"

Game* MenuPause::jeu = NULL;

void reprendre() {
	MainApplication::changerApplication(MenuPause::jeu);
}

void menuPrincipal() {
	delete MenuPause::jeu;
	MainApplication::changerApplication(new MainMenu());
}

void quitter() {
	delete MenuPause::jeu;
	MainApplication::fenetre->close();
}

MenuPause::MenuPause(Game* game) {
	jeu = game;
}

void MenuPause::init() {
	sf::Font font;
	font.loadFromFile("arial.ttf");
	menu.init(font);
	menu.addItem("Reprendre",reprendre);
	menu.addItem("Revenir au menu principal",menuPrincipal);
	menu.addItem("Quitter",quitter);
}

void MenuPause::event(sf::Event& _event) {
	menu.events(_event);
}

void MenuPause::loop() {
	menu.afficher(*MainApplication::fenetre,sf::Vector2f(100,100));
}