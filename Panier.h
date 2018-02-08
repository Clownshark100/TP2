/********************************************
* Titre: Travail pratique #2 - Panier.h
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#pragma once

#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

class Panier
{

public:

	Panier();
	~Panier();

	vector<Produit*>  obtenirContenuPanier()const;
	int obtenirNombreContenu() const;
	double obtenirTotalApayer() const;

	void modifierTotalAPayer(double totalAPayer);

	void ajouter(Produit * prod);
	void livrer();

	Produit* trouverProduitPlusCher();

	friend ostream& operator<<(ostream& os,const Produit& produit);

private:
	double totalAPayer_;

	vector<Produit*> contenuPanier_;
	

};
