#include "MainMenu.h"


void jouer() {
	MainApplication::changerApplication(new Game());
}

void _quitter() {
	MainApplication::fenetre->close();
}

void MainMenu::init() {
	sf::Font police;
	police.loadFromFile("arial.ttf");
	menu.init(police,300);
	menu.addItem("Jouer",jouer);
	menu.addItem("Quitter",_quitter);
}

void MainMenu::event(sf::Event& _event) {
	menu.events(_event);
}

void MainMenu::loop() {
	menu.afficher(*MainApplication::fenetre,sf::Vector2f(100,100));
}
