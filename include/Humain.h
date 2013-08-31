#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include "Animation.h"

class Humain{
private: 
	std::map <std::string, Animation*> Animations;
	sf::Vector2f coords;
	bool canFly;//Le personnage est-il sensible à la gravité ?
	sf::Sprite SpriteSheet;
	sf::Texture texture;
public:
	Humain();//Ajouter args comme type de perso pour charger la feuille de sprites
	void inactif();
	void move();
	void render(sf::RenderWindow* window);
	//Aujouter le saut et la gravité
};