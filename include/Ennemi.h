#pragma once
#include "Humain.h"
#include <iostream>

class Ennemi : public Humain{
private:

public:
	Ennemi();
	void move();

	void playInactifAnimation(unsigned int side);
	void playMoveAnimation(unsigned int side);
	void playJumpAnimation(unsigned int side);
};