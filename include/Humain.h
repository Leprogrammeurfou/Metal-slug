#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <map>
#include <iostream>

class Humain{
protected: 
	std::map <std::string, std::map<std::string,Animation>> PrimarySprite;
	sf::Vector2f coords;
	int canFly;//Le personnage est-il sensible à la gravité ?
	sf::Sprite SpriteSheet;
	sf::Texture texture;
	int jumpForce;
public:
	Humain();
	//Animation de l'inactivité pouvant être coupée par le déplacement, le saut, etc.
	void inactif(Humain*);
	//Animation du déplacement
	void move(Humain*);
	//Saut
	void jump(Humain*);
	//Rendu de l'humain
	virtual void render(sf::RenderWindow* window);
	//Modifier la sensibilité à la gravité
	virtual void setGravity(int G);

	virtual void playInactifAnimation(unsigned int side) = 0;
	virtual void playMoveAnimation(unsigned int side) = 0;
	virtual void playJumpAnimation(unsigned int side) = 0;

	Humain* return_this();
};