/********************************************
* Titre: Travail pratique #2 - Produit.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothee CHAUVIN
*******************************************/

#include "Produit.h"

Produit::Produit(const string& nom, int reference, double prix) :
	nom_{ nom },
	reference_{ reference },
	prix_{ prix }
{ }

// Methodes d'acces
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

double Produit::obtenirPrix() const
{
	return prix_;
}


// Methodes de modification
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}

bool Produit::operator>(const Produit& produit) const
{
	return this->obtenirPrix() > produit.obtenirPrix();
}


bool Produit::operator<(const Produit& produit) const
{
	return this->obtenirPrix() < produit.obtenirPrix();
}

bool Produit::operator==(const Produit & produit) const
{
	return this->obtenirNom()       == produit.obtenirNom()
		&& this->obtenirPrix()      == produit.obtenirPrix()
		&& this->obtenirReference() == produit.obtenirReference();
}

void Produit::afficher() const
{
	cout << "nom : " << nom_ 
			  << "\t ref : " << reference_ 
			  << "\t prix : " << prix_;
}

ostream& operator<<(ostream& os,const Produit& produit) {

	os << "----> nom : " <<  produit.obtenirNom()
	   << "	 ref : " << produit.obtenirReference()
	   << "	prix : " << produit.obtenirPrix() << endl;

	return os;
}
