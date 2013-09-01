#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include "Animation.h"

class Humain{
private: 
	std::map < std::string, Animation > gauche;
	std::map < std::string, Animation > droite;
	sf::Vector2f coords;
	bool canFly;//Le personnage est-il sensible � la gravit� ?
	sf::Sprite SpriteSheet;
	sf::Texture texture;
public:
	//Ajouter args comme type de perso pour charger la feuille de sprites
	Humain();
	//Animation de l'inactivit� pouvant �tre coup�e par le d�placement, le saut, etc.
	void inactif();
	//Animation du d�placement
	void deplacement();
	//Rendu de l'humain
	void render(sf::RenderWindow* window);
	//Aujouter le saut et la gravit�
};