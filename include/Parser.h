#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Parser {
private:
	//Le tableau comportant les �l�ments sous la forme (nom : valeur)
	std::vector < std::pair < std::string, std::string > > elements;

public:
	//Charger le parser � partir d'une chaine de caract�res
	void Parser::loads(std::string chaine);
	//Charger le parser � partir d'un nom de fichier, passer en param�tre le nom du fichier
	void Parser::loadFile(std::string nom_fichier);
	//retourne l'�l�ment qui a pour identifiant l'identifiant fourni
	std::string get(std::string identifiant);
	//Retourne l'�l�ment qui a pour identifiant l'identifiant fourni en le convertissant en un entier
	int geti(std::string identifiant);
	//Permet d'exploser une chaine de caract�re suivant un certain d�limiteur
	static std::vector < std::string > explode(char delimiteur,std::string chaine);
	//Transforme une chaine en un entier
	static int stringToInt(std::string chaine);
};

