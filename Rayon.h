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
    vector <Produit*> obtenirTousProduits() const;

	void modifierCategorie(const string& cat);

	
	Rayon& operator+=(Produit * produit);
	
	int compterDoublons(const Produit& produit);
	
	friend ostream& operator<<(ostream& os, Rayon& rayon);

private:
	string categorie_;

	vector <Produit*> tousProduits_;

};
