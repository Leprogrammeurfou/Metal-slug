#include "Humain.h"

Humain::Humain(){


	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;


	canFly = -11;
	texture.loadFromFile("C:/Users/Lucas/Documents/Metal-slug-sources/medias/Rebel_Soldier.png");
	SpriteSheet.setTexture(texture);
}

void Humain::inactif(Humain*H){
	this->playInactifAnimation(1);
}
void Humain::move(Humain*H){
	H->playMoveAnimation(0);
	std::cout<<"Hey ! Je suis un humain, et je bouge";
}
void Humain::jump(Humain*H){
	this->playJumpAnimation(0);
}

void Humain::setGravity(int G){

}

void Humain::render(sf::RenderWindow* window){
	window->draw(SpriteSheet);
}
Humain* Humain::return_this(){
	return this;
}