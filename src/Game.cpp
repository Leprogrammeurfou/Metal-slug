#include "Game.h"
void Game::init() {
	niveau.init("niveau.txt");
}

void Game::event(sf::Event& _event) {
	//La pause
	if(_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
		MainApplication::changerApplication(new MenuPause(this),false);
}

void Game::loop() {
	niveau.afficher(*MainApplication::fenetre);

	E.inactif(E.return_this());
	E.render(MainApplication::fenetre);
}