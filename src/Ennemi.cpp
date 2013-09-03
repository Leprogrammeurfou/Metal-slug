#include "Ennemi.h"


Ennemi::Ennemi() : Humain(){

	sf::IntRect I1(2,5,27,38);
	sf::IntRect I2(38,5,27,38);
	sf::IntRect I3(74,5,27,38);	
	sf::IntRect I4(107,5,27,38);
	std::vector <sf::IntRect> I;
	Animation Inactif(I,300,"NAME");

	Animation Inactif2(I,300);

	PrimarySprite["Gauche"]["Inactif"] = Inactif;

	PrimarySprite["Gauche"]["Inactif"].addAnimations(I);

	PrimarySprite["Gauche"]["Move"] = Inactif2;

	PrimarySprite["Gauche"]["Jump"] = Inactif2;
}


void Ennemi::playInactifAnimation(unsigned int side){
	if(side%2==0){
		PrimarySprite["Droite"]["Inactif"].loop();
	}else{
		PrimarySprite["Gauche"]["Inactif"].loop();
	}

	for (auto& x: PrimarySprite) {
    std::cout << x.first << ": ";
  }
	
}
void Ennemi::playMoveAnimation(unsigned int side){
	if(side%2==0){
		PrimarySprite["Droite"]["Move"].loop();
	}else{
		PrimarySprite["Gauche"]["Move"].loop();
	}
}
void Ennemi::playJumpAnimation(unsigned int side){
	if(side%2==0){
		PrimarySprite["Gauche"]["Jump"].loop();
	}else{
		PrimarySprite["Gauche"]["Jump"].loop();
	}
}
