//Tu es l� ?
#include <SFML\Graphics.hpp>

class Application {
private:
	//La fen�tre de l'application,
	sf::RenderWindow* fenetre;
public:
	//Le constructeur
	Application();
	//La fonction g�rant les �v�nements
	void event(sf::Event& event);
	//La fonction d�finissant un tour de boucle de l'application
	void loop();
	//La fonction permettant de d�marrer l'application
	int start();
	//Le destructeur !
	~Application();
};