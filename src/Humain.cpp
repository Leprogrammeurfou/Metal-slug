#include "Humain.h"

Humain::Humain(){
	/*Faire
	Animations[0].addAnimations();
	pour ajouter une animation
	*/
	sf::IntRect Immobile1;
	Immobile1.top = 0; Immobile1.left = 0; Immobile1.width = 5; Immobile1.height = 9;


	sf::IntRect Immobile2;
	Immobile2.top = 0; Immobile2.left = 5; Immobile2.width = 5; Immobile2.height = 9;

	sf::IntRect Immobile3;
	Immobile3.top = 0; Immobile3.left = 10; Immobile3.width = 5; Immobile3.height = 9;

	sf::IntRect Immobile4;
	Immobile4.top = 0; Immobile4.left = 15; Immobile4.width = 5; Immobile4.height = 9;

	std::vector<sf::IntRect> Immobile_vector;

	Immobile_vector.push_back(Immobile1);
	Immobile_vector.push_back(Immobile2);
	Immobile_vector.push_back(Immobile3);
	Immobile_vector.push_back(Immobile4);

	Animation tampon;
	gauche["Immobile"] = tampon;
	gauche["Deplacement"] = tampon;
	gauche["Saut"] = tampon;

	gauche["Jambes_Immobile"] = tampon;
	gauche["Jambes_Deplacement"] = tampon;
	//etc..

	//tampon.setInvert(largeur);
	droite["Immobile"] = tampon;
	droite["Deplacement"] = tampon;
	droite["Saut"] = tampon;

	gauche["Jambes_Immobile"] = tampon;
	gauche["Jambes_Deplacement"] = tampon;
	
	//Animations["Immobile"] = new Animation(Immobile_vector, 300);
	//Animations["Gauche"] = new Animation();
	//Animations["Droite"] = new Animation();

	canFly = false;
	texture.loadFromFile("C:/Users/Lucas/Documents/Visual Studio 2012/Projects/Metal slug/Metal slug/Debug/SpriteSheet.png");
	SpriteSheet.setTexture(texture);
}

void Humain::inactif(){
	/*SpriteSheet.setTextureRect(Animations["Immobile"]->loop());*/

}



void Humain::move(){
	//Animation

}

void Humain::render(sf::RenderWindow* window){
	window->draw(SpriteSheet);
}