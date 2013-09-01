#include "Menu.h"

Menu::Menu() : boundingBox(0,0,0,0) {
	item = 0;
}

void Menu::init(sf::Font police,int largeur_min,int taille_texte,sf::Color couleurTexte, sf::Color couleurConteneur,
		sf::Color couleurConteneurSurvole,sf::Color backgroundColor) {
			m_police = police;
			taillePolice = taille_texte;
			m_textColor = couleurTexte;
			m_shapeColor = couleurConteneur;
			m_overColor = couleurConteneurSurvole;
			m_fill = backgroundColor;
			boundingBox.width = largeur_min;
}


void Menu::addItem(std::string nom, void(*function)(void)) {
	sf::Text texte;
	texte.setColor(m_textColor);
	texte.setFont(m_police);
	texte.setCharacterSize(20);
	texte.setPosition(0,(float) boundingBox.height);
	texte.setString(sf::String(nom));
	sf::FloatRect size = texte.getGlobalBounds();
	hauteur = ((int) size.height) + 20;
	boundingBox.height += ((int) size.height) + 30;
	if(size.width + 60 > boundingBox.width)
		boundingBox.width = ((int) size.width) + 60;
	textes.push_back(texte);
	fonctions.push_back(function);

	//Shapes
	rectangles.clear();

	for(unsigned int i = 0;i < textes.size();i++) {
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f((float) boundingBox.width,(float) hauteur));
		if(item != i)
			rectangle.setFillColor(m_shapeColor);
		else
			rectangle.setFillColor(m_overColor);
		rectangle.setPosition(0, ((float) i)*hauteur + ((float) i) * 10);
		textes[i].setPosition(rectangle.getSize().x/2 - textes[i].getGlobalBounds().width/2,
			rectangle.getPosition().y + textes[i].getGlobalBounds().height/2);
		rectangles.push_back(rectangle);
	}


}

void Menu::events(sf::Event& event) {
	bool collision = false;
	if(event.type == sf::Event::KeyPressed) {
		switch(event.key.code) {
		case sf::Keyboard::Down:
			rectangles[item].setFillColor(m_shapeColor);
			item += 1;
			if(item == textes.size())
				item = 0;
			rectangles[item].setFillColor(m_overColor);
			break;
		case sf::Keyboard::Up:
			rectangles[item].setFillColor(m_shapeColor);
			item -= 1;
			if(item < 0)
				item = textes.size()-1;
			rectangles[item].setFillColor(m_overColor);
			break;
		}
	}
	if(item != -1 && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
		//Ben  qu'est ce que tu veux couzin ? on appelle la fonction
		fonctions[item]();
	}
}

void Menu::afficher(sf::RenderWindow& fenetre,sf::Vector2f position) {
	for(unsigned int i = 0;i < rectangles.size();i++) {
		rectangles[i].move(position);
		fenetre.draw(rectangles[i]);
		rectangles[i].move(-position.x,-position.y);
		textes[i].move(position);
		fenetre.draw(textes[i]);
		textes[i].move(-position.x,-position.y);
	}
}

void f() {
}