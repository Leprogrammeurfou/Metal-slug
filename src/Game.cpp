#include "Game.h"

void Game::init() {
	niveau.init("niveau.txt");
}

void Game::event(sf::Event& _event) {
}

void Game::loop() {
	niveau.afficher(*main_app->fenetre);
}