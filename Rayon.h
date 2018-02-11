/********************************************
* Titre: Travail pratique #2 -Rayon.h
* Date: 25 janvier 2018
* Auteur: Daniel Nahum et Loic LeBlanc
* Rayon classe des objets de type Produit* par categorie
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Rayon
{

public:
	Rayon(const string& cat = "inconnu");
	~Rayon();

	string obtenirCategorie() const;
    vector <const Produit*> obtenirTousProduits() const;

	void modifierCategorie(const string& cat);

	
	Rayon& operator+=(const Produit * produit);
	
	int compterDoublons(const Produit& produit) const;
	
	friend ostream& operator<<(ostream& os,const Rayon& rayon);

private:
	string categorie_;

	vector <const Produit*> tousProduits_;

};
