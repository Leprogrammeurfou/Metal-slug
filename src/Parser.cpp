#include "Parser.h"

void Parser::loads(std::string contenu) {
	//Ok on a le contenu, on supprime les \r, \n et les espaces
	std::string contenuFinal = "";

	bool supprimer = true;
	for(size_t i = 0;i < contenu.size();i++) {
		//Si le caractère est un guillemet on change supprimer
		if(contenu[i] == '"')
			supprimer = !supprimer;

		//Si on peut supprimer et que le caractère est interdit on supprime
		if((supprimer && contenu[i] != ' ' && contenu[i] != '\r' && contenu[i] != '\n') || (!supprimer && contenu[i] != '"'))
			contenuFinal += contenu[i];
	}

	int taille = ((int) contenuFinal.size()) - 1;
	//Si le dernier caractère est un point virgule, on le supprime
	if(taille > 0 && contenuFinal[taille] == ';')
		contenuFinal = contenuFinal.substr(0,taille);
	
	//On vide le tableau des elements
	elements.clear();

	std::vector < std::string > paires = Parser::explode(';',contenuFinal);
	for(size_t i = 0;i < paires.size();i++) {
		std::vector < std::string > ensemble = Parser::explode(':',paires[i]);
		elements.push_back(std::pair<std::string,std::string>(ensemble[0],ensemble[1]));
	}
}

//Charge le parser
void Parser::loadFile(std::string nom) {
	std::string contenu = "",ligne = "";
	std::ifstream fichier(nom,std::ios::in);
	while(std::getline(fichier,ligne)) {
		contenu += ligne;
	}
	fichier.close();

	loads(contenu);
}

std::vector < std::string > Parser::explode(char delimiteur,std::string chaine) {
	std::vector < std::string > tableau;
	std::string chaine_en_cours;
	for(size_t i = 0;i < chaine.size();i++) {
		if(delimiteur != chaine[i])
			chaine_en_cours += chaine[i];
		else {
			tableau.push_back(chaine_en_cours);
			chaine_en_cours = "";
		}
	}

	tableau.push_back(chaine_en_cours);
	return tableau;
}

std::string Parser::get(std::string identifiant) {
	for(size_t i = 0;i < elements.size();i++) {
		//Ca a bien cet identifiant ? on retourne la valeur
		if(elements[i].first == identifiant)
			return elements[i].second;
	}

	return "";
}

int Parser::geti(std::string identifiant) {
	return Parser::stringToInt(get(identifiant));
}

int Parser::stringToInt(std::string chaine) {
	std::istringstream stream(chaine);
	int nombre;
	stream >> nombre;
	return nombre;
}