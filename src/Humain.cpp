#include "Humain.h"

void Humain::init(){
	side =  "droite";
	//Ok gros, on charge les animations tranquilou
	Parser parser;
	parser.loadFile("animations.txt");
	imageDroite.loadFromFile(parser.get("image"));
	imageGauche = imageDroite;
	imageGauche.flipHorizontally();
	texture["droite"].loadFromImage(imageDroite);
	texture["gauche"].loadFromImage(imageGauche);
	std::vector < std::string > anims = Parser::explode('-',parser.get("animations"));
	for(unsigned int i = 0;i < anims.size();i++) {
		//Donc on charge chaque animation :p
		Parser animation;
		animation.loads(anims[i]);
		std::vector < std::string > nom = Parser::explode('.',animation.get("nom"));
		animations[nom[0]]["droite"][nom[1]] = new Animation(animation.get("cuts"),animation.geti("delay"));
		animations[nom[0]]["gauche"][nom[1]] = new Animation(animation.get("cuts"),animation.geti("delay"));
		animations[nom[0]]["gauche"][nom[1]]->invertAll(texture["droite"].getSize().x);
	}
	
	//Pfiou les animations sont chargées, on crée les sprites
	for(auto &animation:animations) {
		sf::Sprite sprite;
		sprite.setTexture(texture[side]);
		sprites[animation.first] = sprite;
	}

	isMoving = false;
	isJumping = false;
	stopMoving = false;
	position.x = 0;
	position.y = 0;

	sauter(true);

}

void Humain::move(std::string direction) {
	if(!isMoving || direction != side) {
		//On change la direction ?
		if(side != direction)
			for(auto &sprite:sprites)
				sprite.second.setTexture(texture[direction]);

		side = direction;
		if(!isJumping)
			changerAnimation("deplacement");
		isMoving = true;
	}

	stopMoving = false;
}

void Humain::playAnimation() {
	//Ok donc pour chaque sprite on run l'animation
	for(auto ensembles:animations) {
		sprites[ensembles.first].setTextureRect(ensembles.second[side][animationName]->loop());
	}
}

void Humain::update() {
	sf::IntRect boundingBox = getBoundingBox();
	//S'il bouge il bouge
	if(isMoving) {
		if(stopMoving) {
			if(!isJumping)
				changerAnimation("immobile");
			isMoving = false;
		}
		else {
			stopMoving = true;
			if(side == "droite")
				position.x += 1;
			else
				position.x -= 1;

			Tile* tile = niveau->collision(getBoundingBox());
			//Bon on mate les collisions
			if(tile != NULL) {
				if(side == "droite")
					position.x = tile->getPosition().x - boundingBox.width;
				else
					position.x = tile->getPosition().x + tile->getTextureRect().width;
			}

			//S'il ne saute pas on mate les collisions avec le sol
			if(!isJumping) {
				boundingBox = getBoundingBox();
				boundingBox.top += 1;
				Tile* tile = niveau->collision(boundingBox);
				//Pas de collisions ? bon ben on tombe l'ami
				if(tile == NULL)
					sauter(true);
			}

			
		}
	}

	//S'il saute cousin on le fait sauter
	if(isJumping) {
		position.y += gravity;

		//Ok, on mate s'il y a collision
		Tile* tile = niveau->collision(getBoundingBox());
		if(tile != NULL) {
			//Si on monte, on se cogne et on tombe
			if(gravity <= 0) {
				position.y = tile->getPosition().y + tile->getTextureRect().height;
				gravity = 0;
			}
			else {
				//On stoppe le saut gros
				
				boundingBox = getBoundingBox();
				position.y = tile->getPosition().y - boundingBox.height;
				isJumping = false;
				changerAnimation(isMoving ? "deplacement":"immobile");
			}
		}
		gravity += 0.2;

	}
	
	//On met à jour l'animation
	playAnimation();
	coords(position.x,position.y);
}

void Humain::setNiveau(Niveau* lvl) {
	niveau = lvl;
}

void Humain::render(sf::RenderWindow* app) {
	//On affiche tous les sprites à l'écran
	for(auto &sprite:sprites)
		app->draw(sprite.second);
}

void Humain::changerAnimation(std::string animation) {
	animationName = animation;
	playAnimation();
	coords(position.x,position.y);
	//Nous récupérons également le sprite le plus gros
	int largeur_max = 0;
	for(auto &sprite:sprites) {
		if(sprite.second.getTextureRect().width > largeur_max) {
			largeur_max = sprite.second.getTextureRect().width;
		}
	}

	//On change la bounding box, mine de rien
	size.x = largeur_max;
	//On recalibre le joueur s'il y a collision en x
	Tile* tile = niveau->collision(getBoundingBox());
	if(tile != NULL) {
		if(side == "droite")
			position.x = tile->getPosition().x - size.x;
		else
			position.x = tile->getPosition().x + tile->getTextureRect().width;
	}
	int ancienneHauteur = size.y;
	size.y = hauteur;
	//S'il y a collision en y, on recalibre également
	tile = niveau->collision(getBoundingBox());
	if(tile != NULL) {
		position.y = tile->getPosition().y - size.y;
	}

	//On mate s'il touche le sol quand même
	if(!isJumping) {
			sf::IntRect boundingBox = getBoundingBox();
			boundingBox.top += 1;
			Tile* tile = niveau->collision(boundingBox);
			//Pas de collisions ? bon ben on te met bien
			if(tile == NULL)
				position.y += ancienneHauteur - size.y;
	}
}

void Humain::coords(int x,int y) {
	bool start = true;
	hauteur = y;
	for(auto &sprite:sprites) {
		if(side != "gauche" || start) {
			sprite.second.setPosition(x,y);
			start = false;
		}
		else {
			sprite.second.setPosition(x - sprite.second.getTextureRect().width,y);
		}
		if(side == "gauche")
			x += sprite.second.getTextureRect().width;
		y += sprite.second.getTextureRect().height;
	}

	hauteur = y - hauteur;
}

void Humain::sauter(bool tomber) {
	if(!isJumping) {
		isJumping = true;
		if(!tomber)
			gravity = INITIAL;
		else gravity = 0;
		changerAnimation("saut");
	}
}

Humain::~Humain() {
	for(auto ensembles:animations) {
		for(auto direction:ensembles.second) {
			for(auto anim:direction.second) {
				delete anim.second;
			}
		}
	}
}

sf::IntRect Humain::getBoundingBox() {
	return sf::IntRect(position.x,position.y,size.x,size.y);
}