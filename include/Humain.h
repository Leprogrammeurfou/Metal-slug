#pragma once
#define INITIAL -7
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Parser.h"
#include "Niveau.h"
#include <iostream>

class Humain{
protected:
	//Se déplace t-il, saute t-il ?
	bool isMoving, stopMoving, isJumping;
	//Le niveau
	Niveau* niveau;
	//La gravité
	float gravity;
	//La hauteur du truc
	int hauteur;
	//La position ainsi que la taille du joueur
	sf::Vector2f position, size;
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
	void init();
	//Met à jour l'humain
	void update();
	//Affiche l'humain
	void render(sf::RenderWindow* app);
	//Sauter
	void sauter(bool tomber = false);
	//Changer l'anim
	void changerAnimation(std::string nom);
	//Le déplacement
	void move(std::string direction);
	//Changer les coordonées du/des sprites
	virtual void coords(int x,int y);
	//Joue l'animation en cours
	void playAnimation();
	//Le destructeur
	~Humain();
	//Mettre le niveau
	void setNiveau(Niveau* lvl);
	//Retourne la boundingBox
	sf::IntRect getBoundingBox();
};