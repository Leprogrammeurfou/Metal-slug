#include "Game.h"
void Game::init() {
	niveau.init("niveau.txt");
	E.init("Rebel_Soldier.png", 1);


}

void Game::event(sf::Event& _event) {
	//La pause
	if(_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
		MainApplication::changerApplication(new MenuPause(this),false);
}

void Game::loop() {
	niveau.afficher(*MainApplication::fenetre);

	

	E.move(0);//Un nombre pair = course à droite
	E.render(MainApplication::fenetre);
}