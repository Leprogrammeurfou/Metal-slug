#include "Joueur.h"

Parser Joueur::parser;
sf::Image Joueur::imageDroite;
sf::Image Joueur::imageGauche;
sf::Texture Joueur::textureDroite;
sf::Texture Joueur::textureGauche;

Joueur::Joueur(sf::View& vue, Niveau* niveau) : camera(vue) {
	//On met le niveau
	setNiveau(niveau);
	//On initialise le joueur
	init(&textureGauche,&textureDroite,parser,2);
}

void Joueur::chargement() {
	parser.loadFile("animations.txt");
	imageDroite.loadFromFile(parser.get("image"));
	imageGauche = imageDroite;
	imageGauche.flipHorizontally();
	textureDroite.loadFromImage(imageDroite);
	textureGauche.loadFromImage(imageGauche);
}

void Joueur::update() {
	Humain::update();
	//S'il se déplace ou qu'il saute
	if(isMoving ||isJumping) {
		//Le centre de la vue = le centre du joueur
		sf::IntRect boundingBox = getBoundingBox();
		sf::Vector2f center(boundingBox.left + boundingBox.width/2,boundingBox.top + boundingBox.height/2);
		//Si le centre de la vue part en cacahuetes, on l'ajuste
		if(center.x - camera.getSize().x/2 < 0)
			center.x = camera.getSize().x/2;
		else if(center.x + camera.getSize().x/2 > niveau->largeur)
			center.x = niveau->largeur - camera.getSize().x/2;

		if(center.y - camera.getSize().y/2 < 0)
			center.y = camera.getSize().y/2;
		else if(center.y + camera.getSize().y/2 > niveau->hauteur)
			center.y = niveau->hauteur - camera.getSize().y/2;
		
		camera.setCenter(center);
	}

	//On fait défiler le niveau 0
	if(niveau->defiler(getBoundingBox())) {
		position.x = 0;
		position.y = 0;
		isJumping = false;
		isMoving = false;
		sauter(true);
	}
}