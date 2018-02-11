/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Panier.h"

Panier::Panier() :
	totalAPayer_{ 0 }
{
}

Panier::~Panier()
{
}

// methodes d'accès
vector<Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}

// méthodes de modification

// autres méthodes
void Panier::ajouter(Produit * prod)
{
	contenuPanier_.push_back(prod);
	totalAPayer_ += prod->obtenirPrix();
}

void Panier::livrer()
{
	contenuPanier_.clear();
	totalAPayer_ = 0.0;
}

Produit* Panier::trouverProduitPlusCher()
{
	
	Produit* plusCher = new Produit();
	for (int i = 0; i < contenuPanier_.size(); i++) {
		if ( *(contenuPanier_[i]) > *plusCher ) {
			plusCher = contenuPanier_[i];
		}
	}
	return plusCher;

	//return new Produit("fuck", 666, 66.6);
}

ostream& operator<<(ostream& os, const Panier& panier) {

	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
		os << *(panier.obtenirContenuPanier()[i]);

	os << "----> total a payer : " << panier.obtenirTotalApayer() << endl;

	return os;
}
