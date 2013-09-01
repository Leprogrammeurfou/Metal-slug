#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

void f();
//La classe pour faire un menu
class Menu {
private:
	//Les items du menu, on associe le nom avec la fonction à appeler
	std::vector < sf::Text > textes;
	std::vector < void(*)(void) > fonctions;
	//Les couleurs
	sf::Color m_textColor,m_shapeColor,m_overColor,m_fill;
	//La police et la taille de police
	sf::Font m_police;
	int taillePolice;
	//Le sprite sur lequel est affiché le menu
	sf::Sprite sprite;
	//La police du menu
	sf::Font police;
	//La boundingBox
	sf::IntRect boundingBox;
	//L'item sur lequel la sourie est positionnée, vaut -1 s'il y en a aucun
	int item, hauteur;
	//Les conteneurs
	std::vector < sf::RectangleShape > rectangles;
	

public:
	Menu();
	//Ajouter un item
	void addItem(std::string nom,void (*function)(void) = f);
	//Retourne le sprite
	void afficher(sf::RenderWindow& fenetre,sf::Vector2f position = sf::Vector2f(0,0));
	//Gère les évènements
	void events(sf::Event& event);
	//Initialiser le menu
	void init(sf::Font police,int largeur_min = 100,int taille_texte = 20,sf::Color couleurTexte = sf::Color::Red, sf::Color couleurConteneur = sf::Color::Green,
		sf::Color couleurConteneurSurvole = sf::Color::Yellow,sf::Color backgroundColor = sf::Color::Transparent);
};
