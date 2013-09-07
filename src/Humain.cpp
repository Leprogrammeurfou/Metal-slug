#include "Humain.h"

Humain::Humain(){
	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;
	canFly = -11;
	SpriteSheet.setTexture(texture);
}

Humain::Humain(std::string imgsrc, unsigned int base_side_){
	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;

	canFly = -11;
	
	Base.loadFromFile(imgsrc);
	Base_inverted = Base;
	Base_inverted.flipHorizontally();
	texture.loadFromImage(Base);
	SpriteSheet.setTexture(texture);
	this->base_side = base_side_;
}

void Humain::init(std::string imgsrc, unsigned int base_side_){
	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;

	canFly = -11;
	
	Base.loadFromFile(imgsrc);
	Base_inverted = Base;
	Base_inverted.flipHorizontally();
	texture.loadFromImage(Base);
	SpriteSheet.setTexture(texture);
	this->base_side = base_side_;

}

void Humain::inactif(unsigned int side){
	SpriteSheet.setTextureRect(this->playInactifAnimation(side));

	this->setSide(side);
}
void Humain::move(unsigned int side){
	SpriteSheet.setTextureRect(this->playMoveAnimation(side));

	this->setSide(side);
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

void Humain::setSide(unsigned int side){
	if(base_side %2 == 0){
	if(side%2 == 0){
		this->texture.loadFromImage(Base);
	}else{
		this->texture.loadFromImage(Base_inverted);
	}
	}
	else{
		if(side%2 == 1){
		this->texture.loadFromImage(Base);
	}else{
		this->texture.loadFromImage(Base_inverted);
	}
	}
}

void Humain::setTexture(std::string imgsrc){
	texture.loadFromFile(imgsrc);
	SpriteSheet.setTexture(texture);
}

sf::IntRect Humain::playAnyAnimation(Animation* Animation, unsigned int side){
	return Animation->loop();
}