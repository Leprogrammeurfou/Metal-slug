#include "Ennemi.h"


Ennemi::Ennemi() : Humain(){

	sf::IntRect I1(2,5,27,38);
	sf::IntRect I2(38,5,27,38);
	sf::IntRect I3(75,5,27,38);	
	sf::IntRect I4(107,5,27,38);
	std::vector <sf::IntRect> I;
	I.push_back(I1);
	I.push_back(I2);
	I.push_back(I3);
	I.push_back(I4);
	Animation Inactif(I,100,"NAME",1);
	Inactif.switch_animation_type();
	Animation Inactif2(I,300,1);

	PrimarySprite["Gauche"]["Inactif"] = Inactif;

	PrimarySprite["Gauche"]["Move"] = Inactif2;

	PrimarySprite["Gauche"]["Jump"] = Inactif2;
}

Ennemi::Ennemi(std::string imgsrc) : Humain(imgsrc){

	sf::IntRect I1(2,5,27,38);
	sf::IntRect I2(38,5,27,38);
	sf::IntRect I3(75,5,27,38);	
	sf::IntRect I4(107,5,27,38);
	std::vector <sf::IntRect> I;
	I.push_back(I1);
	I.push_back(I2);
	I.push_back(I3);
	I.push_back(I4);
	Animation Inactif(I,100,"NAME",1);
	Inactif.switch_animation_type();
	texture.getSize().x;
	Inactif.invertAll(texture.getSize().x);
	Animation Inactif2(I,300,1);

	PrimarySprite["Gauche"]["Inactif"] = Inactif;

	PrimarySprite["Gauche"]["Move"] = Inactif2;

	PrimarySprite["Gauche"]["Jump"] = Inactif2;
}

void Ennemi::init(std::string imgsrc){
	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;


	canFly = -11;
	
	texture.loadFromFile(imgsrc);
	SpriteSheet.setTexture(texture);

	sf::IntRect I1(2,5,27,38);
	sf::IntRect I2(38,5,27,38);
	sf::IntRect I3(75,5,27,38);	
	sf::IntRect I4(107,5,27,38);
	std::vector <sf::IntRect> I;
	I.push_back(I1);
	I.push_back(I2);
	I.push_back(I3);
	I.push_back(I4);
	Animation Inactif(I,100,"NAME",1);
	Inactif.switch_animation_type();
	sf::Vector2f u(texture.getSize().x, 5);
	Inactif.invertAll(texture.getSize().x);
	Animation Inactif2(I,300,1);

	PrimarySprite["Gauche"]["Inactif"] = Inactif;

	PrimarySprite["Gauche"]["Move"] = Inactif2;

	PrimarySprite["Gauche"]["Jump"] = Inactif2;
}

sf::IntRect Ennemi::playInactifAnimation(unsigned int side){
	if(side%2==0){
		return PrimarySprite["Droite"]["Inactif"].loop();
	}else{
		return PrimarySprite["Gauche"]["Inactif"].loop();
	}	
}
sf::IntRect Ennemi::playMoveAnimation(unsigned int side){
	if(side%2==0){
		return PrimarySprite["Droite"]["Move"].loop();
	}else{
		return PrimarySprite["Gauche"]["Move"].loop();
	}
}
sf::IntRect Ennemi::playJumpAnimation(unsigned int side){
	if(side%2==0){
		return PrimarySprite["Gauche"]["Jump"].loop();
	}else{
		return PrimarySprite["Gauche"]["Jump"].loop();
	}
}
