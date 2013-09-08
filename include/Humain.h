#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Parser.h"
#include <map>
#include <iostream>

class Humain{
protected:
	//Se d�place t-il ?
	bool isMoving, stopMoving;
	//La position du joueur
	sf::Vector2f position;
	//Les images
	sf::Image imageGauche,imageDroite;
	//La feuille de sprite
	std::map < std::string, sf::Texture > texture;
	/*
	 * Animations de la forme ["haut"]["direction"]["nom_animation"]
	 */
	std::map < std::string, std::map < std::string,std::map < std::string,Animation* > > > animations;
	/*
	 * La liste des sprites de l'humain
	 */
	std::map < std::string, sf::Sprite > sprites;
	//Le nom de l'animation en cours ainsi que la direction
	std::string animationName,side;
public:
	//Le constructeur de l'humain
	Humain();
	//Met � jour l'humain
	void update();
	//Affiche l'humain
	void render(sf::RenderWindow* app);
	//Le d�placement
	void move(std::string direction);
	//Changer les coordon�es du/des sprites
	virtual void coords(int x,int y);
	//Joue l'animation en cours
	void playAnimation();
	//Le destructeur
	~Humain();
};