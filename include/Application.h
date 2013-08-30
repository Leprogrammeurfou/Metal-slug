//Tu es là ?
#include <SFML\Graphics.hpp>

class Application {
private:
	//La fenêtre de l'application,
	sf::RenderWindow* fenetre;
public:
	//Le constructeur
	Application();
	//La fonction gérant les évènements
	void event(sf::Event& event);
	//La fonction définissant un tour de boucle de l'application
	void loop();
	//La fonction permettant de démarrer l'application
	int start();
	//Le destructeur !
	~Application();
};