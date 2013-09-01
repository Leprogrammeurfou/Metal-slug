#include "MainApplication.h"

Application* MainApplication::current = NULL;
sf::RenderWindow* MainApplication::fenetre = NULL;

MainApplication::MainApplication() {
	fenetre = new sf::RenderWindow(sf::VideoMode(800,600),"");
	fenetre->setFramerateLimit(60);
}

int MainApplication::start() {
	while(fenetre->isOpen()) {
		sf::Event evenement;
		while(fenetre->pollEvent(evenement)) {
			//SI on veut quitter ben on quitte
			if(evenement.type == sf::Event::Closed) {
				fenetre->close();
			}
			//Sinon on donne l'evenement à l'application en cours
			else if(current != NULL)
				current->event(evenement);
		}
		fenetre->clear();
		//On appelle la boucle de l'application en cours
		if(current != NULL)
			current->loop();		
		fenetre->display();
	}

	return 1;
}

void MainApplication::changerApplication(Application* app,bool supprimer) {
	//On supprime s'il le veut
	if(supprimer && current != NULL)
		delete current;

	//On change l'application en cours
	current = app;

	//On initialie l'application
	current->init();
}

MainApplication::~MainApplication() {
	delete fenetre;
	//On supprime également l'application en cours si elle ne l'est pas déjà
	if(current != NULL)
		delete current;
}