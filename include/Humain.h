#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <map>
#include <iostream>

class Humain{
protected: 
	std::map <std::string, std::map<std::string,Animation>> PrimarySprite;
	sf::Vector2f coords;
	int canFly;//Le personnage est-il sensible � la gravit� ?
	sf::Sprite SpriteSheet;
	sf::Image Base;
	sf::Image Base_inverted;
	sf::Texture texture;
	int jumpForce;
	
	unsigned int base_side;
public:
	Humain();
	Humain(std::string imgsrc, unsigned int base_side_);

	virtual void init(std::string imgsrc, unsigned int base_side_);
	//Animation de l'inactivit� pouvant �tre coup�e par le d�placement, le saut, etc.
	void inactif(unsigned int side);
	//Animation du d�placement
	void move(unsigned int side);
	//Saut
	void jump(unsigned int side);
	//Rendu de l'humain
	virtual void render(sf::RenderWindow* window);
	//Modifier la sensibilit� � la gravit�
	virtual void setGravity(int G);

	virtual sf::IntRect playInactifAnimation(unsigned int side) = 0;
	virtual sf::IntRect playMoveAnimation(unsigned int side) = 0;
	virtual sf::IntRect playJumpAnimation(unsigned int side) = 0;

	sf::IntRect playAnyAnimation(Animation* Animation, unsigned int side);

	virtual void setSide(unsigned int side);

	void setTexture(std::string imgsrc);

	Humain* return_this();
};