/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/

#include "Produit.h"
/**
* Constructeur par défault et par parametres.
*/
Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }

// Methodes d'acces
/**
* Accesseur de nom_.
*/
string Produit::obtenirNom() const
{
	return nom_;
}
/**
* Accesseur de reference_.
*/
int Produit::obtenirReference() const
{
	return reference_;
}
/**
* Accesseur de prix_.
*/
double Produit::obtenirPrix() const
{
	return prix_;
}


// Methodes de modification
/**
* Modifie le nom du produit.
*/
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}
/**
* Modifie la reference du produit.
*/
void Produit::modifierReference(int reference)
{
	reference_ = reference;
}
/**
* Modifie le prix du produit.
*/
void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}
/**
* Compare si le prix est plus grand que le prix du produit.
*/
bool Produit::operator>(const Produit& produit) const
{
	return this->obtenirPrix() > produit.obtenirPrix();
}
/**
* Compare si le prix est plus petit que le prix du produit.
*/
bool Produit::operator<(const Produit& produit) const
{
	return this->obtenirPrix() < produit.obtenirPrix();
}
/**
* Verife si deux produits sont identiques.
*/
bool Produit::operator==(const Produit & produit) const
{
	return this->obtenirNom()       == produit.obtenirNom()
		&& this->obtenirPrix()      == produit.obtenirPrix()
		&& this->obtenirReference() == produit.obtenirReference();
}
/**
*Affiche l'information du produit.
*/
ostream& operator<<(ostream& os, const Produit& produit) {

	os << "----> nom : " <<  produit.obtenirNom()
	   << "	 ref : " << produit.obtenirReference()
	   << "	prix : " << produit.obtenirPrix() << endl;

	return os;
}
