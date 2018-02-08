/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Timoth�e CHAUVIN
*******************************************/

#include "Rayon.h"

Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	tousProduits_{}
{
}

Rayon::~Rayon()
{
}

// Methodes d'acces
string Rayon::obtenirCategorie() const
{
	return categorie_;
}

vector <Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_ ;
}




// Methodes de modification
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}


Rayon& Rayon::operator+=(Produit* produit)
{
	tousProduits_.push_back(produit);
	return *this;
}

int Rayon::compterDoublons(const Produit& produit)
{
	int compteur = 0;
	for (int i = 0; i <tousProduits_.size(); i++)
	{
		if (tousProduits_[i] == produit)
			compteur++;
	}
	return compteur;
}

ostream& operator<<(ostream &os,Rayon& rayon)
{
	os << "Le rayon " << rayon.obtenirCategorie() << ":\n";
	for (int i = 0; i < rayon.obtenirTousProduits().size(); i++)
	{
		os << "----> nom : " << rayon.obtenirTousProduits()[i]->obtenirNom() <<
			"	 ref : " << rayon.obtenirTousProduits()[i]->obtenirReference() <<
			"	prix : " << rayon.obtenirTousProduits()[i]->obtenirPrix() << endl;
	}
	return os;
}
