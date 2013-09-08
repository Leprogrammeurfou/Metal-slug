#include "Game.h"
void Game::init() {
	
	Parser parser;
	parser.loads("nom : \"Alpha le bg de ouf; qui tue tout\";age : 18");
	std::cout << parser.get("nom") << std::endl;
	niveau.init("niveau.txt");

}

void Game::event(sf::Event& _event) {
	//La pause
	if(_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
		MainApplication::changerApplication(new MenuPause(this),false);
}

void Game::loop() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		humain.move("gauche");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		humain.move("droite");
	humain.update();
	
	niveau.afficher(*MainApplication::fenetre);
	humain.render(MainApplication::fenetre);
}