/********************************************
* Titre: Travail pratique #2 - Panier.cpp
* Date: 25 janvier 2018
* Auteur: Loic LeBlanc
*******************************************/

#include "Panier.h"
/**
* Constructeur par default de panier.
*/
Panier::Panier() :
	totalAPayer_{ 0 }
{
}
/**
* Destructeur de Panier, rien a faire.
*/
Panier::~Panier()
{
}

// methodes d'accès
/**
* Accesseur du vecteur de pointeurs contenuPanier_
*/
vector<const Produit*>  Panier::obtenirContenuPanier()const
{
	return contenuPanier_;
}
/**
* Accesseur de nombre de produits dans panier.
*/
int Panier::obtenirNombreContenu() const
{
	return contenuPanier_.size();
}
/**
* Accesseur du total a payer 
*/
double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}
// méthodes de modification
/**
* Modifie le total a payer
*/
void Panier::modifierTotalAPayer(double totalAPayer)
{
	totalAPayer_ = totalAPayer;
}


// autres méthodes
/**
* Ajoute un produit au panier
*/
void Panier::ajouter(const Produit * prod)
{
	contenuPanier_.push_back(prod);
	totalAPayer_ += prod->obtenirPrix();
}
/**
* Vide le panier et remet le total a payer a zero
*/
void Panier::livrer()
{
	contenuPanier_.clear();
	totalAPayer_ = 0.0;
}
/**
* Compare le prix des produits dans le panier et retourne le produit le plus cher du panier.
*/
const Produit* Panier::trouverProduitPlusCher()const
{
	
	const Produit* plusCher = new Produit();
	for (int i = 0; i < contenuPanier_.size(); i++) {
		if ( *(contenuPanier_[i]) > *plusCher ) {
			plusCher = contenuPanier_[i];
		}
	}
	return plusCher;

}
/**
* Affiche le contenu du panier ainsi que le total a payer.
*/
ostream& operator<<(ostream& os, const Panier& panier) {

	for (int i = 0; i < panier.obtenirNombreContenu(); i++)
		os << *(panier.obtenirContenuPanier()[i]);

	os << "----> total a payer : " << panier.obtenirTotalApayer() << endl;

	return os;
}
