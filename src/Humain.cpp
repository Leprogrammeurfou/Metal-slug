#include "Humain.h"

Humain::Humain(){
	isMoving = false;
	stopMoving = false;
	side = "droite";
	animationName = "immobile";

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
}

void Humain::move(std::string direction) {
	if(!isMoving || direction != side) {
		//On change la direction ?
		if(side != direction)
			for(auto &sprite:sprites)
				sprite.second.setTexture(texture[direction]);

		side = direction;
		animationName = "deplacement";
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
	if(isMoving) {
		if(stopMoving) {
			animationName = "immobile";
			isMoving = false;
		}
		else {
			stopMoving = true;
			if(side == "droite")
				position.x += 1;
			else
				position.x -= 1;
		}
	}
	//On met à jour l'animation
	playAnimation();
	coords(position.x,position.y);
}

void Humain::render(sf::RenderWindow* app) {
	//On affiche tous les sprites à l'écran
	for(auto &sprite:sprites)
		app->draw(sprite.second);
}

void Humain::coords(int x,int y) {
	bool start = true;
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
		y += sprite.second.getTextureRect().height - 7;
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