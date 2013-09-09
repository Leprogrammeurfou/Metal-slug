#pragma once
#include <SFML\Graphics.hpp>
#include "Humain.h"
#include "Parser.h"
#include "Niveau.h"

class Joueur : public Humain {
private:
	//Les textures associées
	static sf::Image imageGauche, imageDroite;
	static sf::Texture textureGauche, textureDroite;
	static Parser parser;
	//La vue
	sf::View& camera;
public:
	//Le constructeur
	Joueur(sf::View& vue, Niveau* niveau);
	//Charger les images 
	static void chargement();
	//On améliore le déplacement (gestion de la vue)
	void update();
};
