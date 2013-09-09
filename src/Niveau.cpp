#include "Niveau.h"

void Niveau::init(std::string filename) {
	current = NULL;
	//Cr�ation du parser
	Parser parser;
	parser.loadFile(filename);

	//On r�cup�re la liste des cartes
	std::vector < std::string > fichiers_cartes = Parser::explode(',',parser.get("maps"));

	//Les informations sur le niveau
	nom = parser.get("nom");

	//On cr�e un parser pour chaque maps
	for(size_t i = 0;i < fichiers_cartes.size();i++) {
		Parser parser;
		parser.loadFile(fichiers_cartes[i]);
		maps.push_back(parser);
	}

	//On choisis la premi�re map
	id_current = 0;
	chargerCarte();
}

void Niveau::chargerCarte() {
	//Si la map en cours existe on la delete
	if(current != NULL)
		delete current;

	//Ok on se contente de charger la map
	current = new Map();
	current->charger(maps[id_current]);
	largeur = current->largeur;
	hauteur = current->hauteur;
}

bool Niveau::afficher(sf::RenderWindow& app) {
	if(current == NULL)
		return false;
	
	current->afficher(app);
	return true;
}

Tile* Niveau::collision(sf::IntRect& boundingBox) {
	if(current != NULL)
		return current->collision(boundingBox);

	return NULL;
}

bool Niveau::defiler(sf::IntRect& boundingBox) {
	if(boundingBox.left + boundingBox.width > current->getLargeur()) {
		//Ca d�passe ? on passe � la map suivante
		id_current += 1;
		if(id_current < (int) maps.size())
			chargerCarte();

		return true;
	}

	return false;
}