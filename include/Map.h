#pragma once
#include <SFML\Graphics.hpp>
#include "Parser.h"
#include <cmath>
//Un tile de la map
class Tile : public sf::Sprite {
private:
	//Savoir si le tile est un obstacle
	bool _obstacle;

public:
	Tile();
	//Définir le tile comme un obstacle
	void obstacle();
	//Retourne true s'il y a une collision, prend en paramètre la boite englobante
	bool collision(sf::IntRect boiteEnglobante);
	//Retourne true si le tile est un obstacle
	bool isObstacle();
};

class Map {
private:
	//Le tileset
	sf::Texture tileset;
	//Le tableau contenant les sprites de la map
	std::vector < std::vector < Tile > > tableau;
	//le nom de la map
	std::string nom;
	//la largeur, la hauteur de la map, la largeur d'un tile, la hauteur d'un tile
	int largeur, hauteur, largeur_tile, hauteur_tile,nombre_tiles_largeur,nombre_tiles_hauteur;
public:
	//Charger la map
	void charger(Parser& parser);
	//Afficher la map
	void afficher(sf::RenderWindow& app);
	//Retourne le tile de la position demandée
	sf::Vector2f getTile(sf::Vector2f position);
	//Retourne le tile s'il y a collision
	Tile* collision(sf::IntRect boundingBox);
	//Retourne la largeur de la map
	int getLargeur();
};