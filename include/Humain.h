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
	Humain(std::string imgsrc);

	virtual void init(std::string imgsrc);
	//Animation de l'inactivité pouvant être coupée par le déplacement, le saut, etc.
	void inactif(unsigned int side);
	//Animation du déplacement
	void move(unsigned int side);
	//Saut
	void jump(unsigned int side);
	//Rendu de l'humain
	virtual void render(sf::RenderWindow* window);
	//Modifier la sensibilité à la gravité
	virtual void setGravity(int G);

	virtual sf::IntRect playInactifAnimation(unsigned int side) = 0;
	virtual sf::IntRect playMoveAnimation(unsigned int side) = 0;
	virtual sf::IntRect playJumpAnimation(unsigned int side) = 0;

	sf::IntRect playAnyAnimation(Animation* Animation, unsigned int side);

	void setTexture(std::string imgsrc);

	Humain* return_this();
};