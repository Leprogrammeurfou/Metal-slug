#pragma once
#include "Humain.h"
#include <iostream>

class Ennemi : public Humain{
private:

public:
	Ennemi();
	Ennemi(std::string imgsrc, unsigned int base_side_);

	void init(std::string imgsrc, unsigned int base_side_);

	//void move();

	sf::IntRect playInactifAnimation(unsigned int side);
	sf::IntRect playMoveAnimation(unsigned int side);
	sf::IntRect playJumpAnimation(unsigned int side);
};