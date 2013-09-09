#include "Game.h"
void Game::init() {
	
	Parser parser;
	parser.loads("nom : \"Alpha le bg de ouf; qui tue tout\";age : 18");
	std::cout << parser.get("nom") << std::endl;
	std::cout << "chargement du niveau" << std::endl;
	niveau.init("niveau.txt");
	std::cout << "chargé !" << std::endl;
	//On définit la caméra
	camera.setCenter(0,0);
	camera.setSize(sf::Vector2f(MainApplication::fenetre->getSize()));
	
	//Chargement du joueur
	std::cout << "chargement du joueur..." << std::endl;
	Joueur::chargement();
	std::cout << "chargé !" << std::endl;
	//On crée le joueur
	joueur = new Joueur(camera, &niveau);

}

void Game::event(sf::Event& _event) {
	//La pause
	if(_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
		MainApplication::changerApplication(new MenuPause(this),false);
}

void Game::loop() {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		joueur->move("gauche");
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		joueur->move("droite");
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		joueur->sauter();

	
	MainApplication::fenetre->setView(camera);
	joueur->update();
	
	niveau.afficher(*MainApplication::fenetre);
	joueur->render(MainApplication::fenetre);
}