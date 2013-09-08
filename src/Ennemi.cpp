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

Ennemi::Ennemi(std::string imgsrc, unsigned int base_side_) : Humain(imgsrc, base_side_){

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

	sf::IntRect M1(2,49,27,38);
	sf::IntRect M2(2,49,27,38);
	sf::IntRect M3(2,49,27,38);
	sf::IntRect M4(2,49,27,38);
	sf::IntRect M5(2,49,27,38);
	sf::IntRect M6(2,49,27,38);
	sf::IntRect M7(2,49,27,38);
	sf::IntRect M8(2,49,27,38);
	sf::IntRect M9(2,49,27,38);
	sf::IntRect M10(2,49,27,38);
	sf::IntRect M11(2,49,27,38);
	sf::IntRect M12(2,49,27,38);


	std::vector <sf::IntRect> M;

	M.push_back(M1);
	M.push_back(M2);
	M.push_back(M3);
	M.push_back(M4);
	M.push_back(M5);
	M.push_back(M6);
	M.push_back(M7);
	M.push_back(M8);
	M.push_back(M9);
	M.push_back(M10);
	M.push_back(M11);
	M.push_back(M12);

	Animation Move(M,100,"NAME",1);

	PrimarySprite["Gauche"]["Move"] = Move;

	PrimarySprite["Gauche"]["Jump"] = Inactif2;
}

void Ennemi::init(std::string imgsrc, unsigned int base_side){
	std::map<std::string,Animation> tampon;
	PrimarySprite["Droite"] = tampon;
	PrimarySprite["Gauche"] = tampon;

	canFly = -11;
	
	Base.loadFromFile(imgsrc);
	Base_inverted = Base;
	Base_inverted.flipHorizontally();
	texture.loadFromImage(Base);
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
	Animation Inactif(I,100,"INACTIF",1);
	Inactif.switch_animation_type();
	texture.getSize().x;
	Inactif.invertAll(texture.getSize().x);
	Animation Inactif2(I,300,1);

	PrimarySprite["Gauche"]["Inactif"] = Inactif;

	sf::IntRect(2,49,27,38);
	sf::IntRect M2(36,49,27,38);
	sf::IntRect M3(71,47,27,40);
	sf::IntRect M4(103,47,27,40);
	sf::IntRect M5(135,48,27,39);
	sf::IntRect M6(171,49,27,38);
	sf::IntRect M7(203,49,27,38);
	sf::IntRect M8(234,49,27,38);
	sf::IntRect M9(265,47,27,40);
	sf::IntRect M10(296,47,27,40);
	sf::IntRect M11(332,48,27,39);
	sf::IntRect M12(370,49,27,38);


	std::vector <sf::IntRect> M;

	M.push_back(M1);
	M.push_back(M2);
	M.push_back(M3);
	M.push_back(M4);
	M.push_back(M5);
	M.push_back(M6);
	M.push_back(M7);
	M.push_back(M8);
	M.push_back(M9);
	M.push_back(M10);
	M.push_back(M11);
	M.push_back(M12);

	Animation Move(M,50,"JUMP",1);

	PrimarySprite["Gauche"]["Move"] = Move;
	PrimarySprite["Droite"]["Move"] = Move;
	PrimarySprite["Droite"]["Move"].invertAll(texture.getSize().x);

	PrimarySprite["Gauche"]["Jump"] = Inactif2;
}
 
void playAnimation(std::string name) {
	this->anima