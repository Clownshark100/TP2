/********************************************
* Titre: Travail pratique #2 - Panier.h
* Date: 25 janvier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*
* Panier contient les produits qu'un client achete avec le total a payer.
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

	vector<const Produit*>  obtenirContenuPanier()const;
	int obtenirNombreContenu() const;
	double obtenirTotalApayer() const;

	void modifierTotalAPayer(double totalAPayer);

	void ajouter(const Produit * prod);
	void livrer();

	const Produit* trouverProduitPlusCher() const;

	friend ostream& operator<<(ostream& os,const Panier& panier);

private:
	double totalAPayer_;

	vector<const Produit*> contenuPanier_;
	

};
