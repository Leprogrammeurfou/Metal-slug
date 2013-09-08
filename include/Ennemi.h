#pragma once
#define DROITE 1
#define GAUCHE 2
#include "Humain.h"
#include <iostream>

class Ennemi : public Humain{
private:
	sf::Sprite first,second;
	std::map <unsigned int,std::map < std::string,Animation > > animations;
public:
	Ennemi();
	Ennemi(std::string imgsrc, unsigned int base_side_);

	void init(std::string imgsrc, unsigned int base_side_);

	void render(sf::RenderWindow* app);
	void playAnimation(std::string name);
};