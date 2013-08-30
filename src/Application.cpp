#include "Application.h"

Application::Application() {
	fenetre = new sf::RenderWindow(sf::VideoMode(800,600),"");
	fenetre->setFramerateLimit(60);
}

void Application::event(sf::Event& event) {
	if(event.type == sf::Event::Closed)
		fenetre->close();
}

void Application::loop() {
	fenetre->clear();
}

int Application::start() {
	while(fenetre->isOpen()) {
		sf::Event evenement;
		while(fenetre->pollEvent(evenement)) {
			this->event(evenement);
		}

		this->loop();
		fenetre->display();
	}

	return 1;
}

Application::~Application() {
	delete fenetre;
}