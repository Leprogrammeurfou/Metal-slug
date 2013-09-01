#include "Map.h"

bool in_array(std::string recherche,std::vector < std::string > tableau) {
	for (unsigned int i = 0;i < tableau.size();i++)
		if(tableau[i] == recherche)
			return true;

	return false;
}

Tile::Tile() : sf::Sprite(),_obstacle(false) {
}

void Tile::obstacle() {
	_obstacle = true;
}

bool Tile::isObstacle() {
	return _obstacle;
}

bool Tile::collision(sf::IntRect boundingBox) {
	sf::IntRect myBoundingBox = sf::IntRect((int) getPosition().x,
		(int) getPosition().y,getTextureRect().width,getTextureRect().height);

	return myBoundingBox.left + myBoundingBox.width > boundingBox.left && 
		myBoundingBox.left < boundingBox.left + boundingBox.width && 
		myBoundingBox.top + myBoundingBox.height > boundingBox.top &&
		myBoundingBox.top < boundingBox.top + boundingBox.height;
}

void Map::charger(Parser& parser) {
	//Chargement du tileset
	std::string k = parser.get("tileset");
	tileset.loadFromFile(parser.get("tileset"));

	//On initialise les paramètres de la map
	nom = parser.get("nom");
	largeur = parser.geti("largeur");
	hauteur = parser.geti("hauteur");
	largeur_tile = parser.geti("largeur_tile");
	hauteur_tile = parser.geti("hauteur_tile");
	nombre_tiles_largeur = largeur/largeur_tile;
	nombre_tiles_hauteur = hauteur/hauteur_tile;

	//On récupère les obstacles
	std::vector < std::string > tiles_obstacles = Parser::explode(',',parser.get("obstacles"));

	//Ok on récupère les tiles
	std::vector < std::string > tiles = Parser::explode(',',parser.get("tiles"));

	//on rempli le tableau
	for(int y = 0;y < nombre_tiles_hauteur;y++) {
		std::vector < Tile > sprites;
		for(int x = 0;x < nombre_tiles_largeur;x++) {
			bool obstacle = in_array(tiles[y * nombre_tiles_largeur + x],tiles_obstacles);
			//On récupère le numéro du tile
			int tile = Parser::stringToInt(tiles[y * nombre_tiles_largeur + x]) - 1;
			//On récupère la position du tile
			int position_x = tile%int(tileset.getSize().x/largeur_tile);
			double position_y = floor((double) tile/int(tileset.getSize().x/largeur_tile));

			//Création du sprite
			Tile sprite;
			sprite.setTexture(tileset);
			//Découpage du tileset
			sprite.setTextureRect(sf::IntRect((position_x) * largeur_tile,((int) position_y) * hauteur_tile,largeur_tile,hauteur_tile));
			sprite.setPosition((float) x * largeur_tile,(float) y * hauteur_tile);

			//Si c'est un obstacle, nous le signalons
			if(obstacle)
				sprite.obstacle();

			sprites.push_back(sprite);
		}
		//On ajoute la ligne au tableau
		tableau.push_back(sprites);
	}
}

void Map::afficher(sf::RenderWindow& app) {
	for(unsigned int i = 0;i < tableau.size();i++) {
		for(unsigned int j = 0;j < tableau[i].size();j++) {
			app.draw(tableau[i][j]);
		}
	}
}

sf::Vector2f Map::getTile(sf::Vector2f position) {
	float x = position.x/largeur_tile, y = position.y/hauteur_tile;
	return sf::Vector2f(x,y);
}

Tile* Map::collision(sf::IntRect boundingBox) {
	sf::Vector2i tile(getTile(sf::Vector2f((float) boundingBox.left,(float) boundingBox.top)));
	for(unsigned int j = -1;j < 2;j++) {
		for(unsigned int i = -1;i < 2;i++) {
			int x = tile.x + i,y = tile.y + j;
			std::cout << x << ", "<< y << std::endl;
			//Si la position existe
			if(y >= 0 && y < (int) tableau.size() && x >= 0 && y < (int) tableau[y].size()) {

				//Si c'est un obstacle et en collision
				if(tableau[y][x].isObstacle()) {
					if(tableau[y][x].collision(boundingBox))
						return &tableau[y][x];
				}
			}
		}
	}

	return NULL;
}

int Map::getLargeur() {
	return largeur;
}