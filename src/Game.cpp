#include "Game.h"
void Game::init() {
	niveau.init("niveau.txt");
	E.init("Rebel_Soldier.png");
}

void Game::event(sf::Event& _event) {
	//La pause
	if(_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
		MainApplication::changerApplication(new MenuPause(this),false);
}

void Game::loop() {
	niveau.afficher(*MainApplication::fenetre);

	
	E.inactif(1);
	E.render(MainApplication::fenetre);
}