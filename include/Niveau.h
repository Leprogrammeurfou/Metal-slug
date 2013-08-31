#include <SFML\Graphics.hpp>
#include "Map.h"
#include "Parser.h"

class Niveau {
private:
	//La liste des parsers des maps du niveau
	std::vector < Parser > maps;
	//La carte en cours
	Map* current;
	//Les informations sur le niveau
	std::string nom;
	//L'identifiant de la carte en cours
	int id_current;
public:
	//Initialiser le niveau, prend en param�tres le nom du fichier
	void init(std::string filename);
	//Affiche le niveau, retourne false si le niveau n'a plus de maps � afficher, en gros s'il est termin�.
	bool afficher(sf::RenderWindow& app);
	//Charge la map en cours
	void chargerCarte();
	//Retourne un pointeur vers le tile s'il y a collision, sinon NULL
	Tile* collision(sf::IntRect& boundingBox);
	//Change de map ou termine le niveau si l'utilisateur a termin� la map en cours. Retourne true si la map fut chang�e
	bool defiler(sf::IntRect& boundingBox);
};