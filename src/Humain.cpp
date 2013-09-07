#include "Humain.h"

Humain::Humain(){


	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;

	canFly = -11;
	SpriteSheet.setTexture(texture);
}

Humain::Humain(std::string imgsrc){
	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;

	canFly = -11;
	
	texture.loadFromFile(imgsrc);
	SpriteSheet.setTexture(texture);
}

void Humain::init(std::string imgsrc){
	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;

	canFly = -11;
	
	texture.loadFromFile(imgsrc);
	SpriteSheet.setTexture(texture);
}

void Humain::inactif(unsigned int side){
	SpriteSheet.setTextureRect(this->playInactifAnimation(side));
}
void Humain::move(unsigned int side){
	this->playMoveAnimation(side);
	std::cout<<"Hey ! Je suis un humain, et je bouge";
}
void Humain::jump(unsigned int side){
	this->playJumpAnimation(side);
}

void Humain::setGravity(int G){
	canFly = G;
}

void Humain::render(sf::RenderWindow* window){
	window->draw(SpriteSheet);
}
Humain* Humain::return_this(){
	return this;
}

void Humain::setTexture(std::string imgsrc){
	texture.loadFromFile(imgsrc);
	SpriteSheet.setTexture(texture);
}

sf::IntRect Humain::playAnyAnimation(Animation* Animation, unsigned int side){
	return Animation->loop();
}