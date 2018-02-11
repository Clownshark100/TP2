/********************************************
* Titre: Travail pratique #2 - Produit.h
* Date: 25 janvier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*
* La classe Produit gere l'information d'un produit
*******************************************/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produit
{

public:
	Produit(const string& nom = "outil", int reference = 0, double prix = 0.0);

	string obtenirNom() const;
	int obtenirReference() const;
	double obtenirPrix() const;

	void modifierNom(const string& nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);

	//surcharges d'operateurs
	bool operator>(const Produit& produit) const;
	bool operator<(const Produit& produit) const;
	bool operator==(const Produit& produit) const;
	friend ostream& operator<<(ostream& os, Produit& produit);
   
private:
	string nom_;
	int reference_;
    double prix_;
};
