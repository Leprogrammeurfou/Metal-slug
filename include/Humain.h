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
	sf::Texture texture;
	int jumpForce;
public:
	Humain();
	//Animation de l'inactivit� pouvant �tre coup�e par le d�placement, le saut, etc.
	void inactif(Humain*);
	//Animation du d�placement
	void move(Humain*);
	//Saut
	void jump(Humain*);
	//Rendu de l'humain
	virtual void render(sf::RenderWindow* window);
	//Modifier la sensibilit� � la gravit�
	virtual void setGravity(int G);

	virtual void playInactifAnimation(unsigned int side) = 0;
	virtual void playMoveAnimation(unsigned int side) = 0;
	virtual void playJumpAnimation(unsigned int side) = 0;

	Humain* return_this();
};