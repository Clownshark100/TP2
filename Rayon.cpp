/********************************************
* Titre: Travail pratique #2 - Rayon.cpp
* Date: 25 janvier 2018
* Auteur: Daniel Nahum et Loic LeBlanc
*******************************************/

#include "Rayon.h"
/** 
*Constructeurs par defaut et par paraametres
*/
Rayon::Rayon(const string& cat) :
	categorie_{ cat },
	tousProduits_{}
{
}
/**
* Destructeur de Rayon, rien a faire.
*/
Rayon::~Rayon()
{
}

// Methodes d'acces
/**
* Accesseur de categorie_
*/
string Rayon::obtenirCategorie() const
{
	return categorie_;
}
/**
* Accesseur du vecteur de pointeurs tousProduits_
*/
vector <const Produit*> Rayon::obtenirTousProduits() const
{
	return tousProduits_ ;
}


// Methodes de modification
/**
* Modifie la valeur de categorie_ par la valeur cat passee en parametre
*/
void Rayon::modifierCategorie(const string& cat)
{
	categorie_ = cat;
}

/**
* Ajoute un pointeur vers un produit à la fin du vecteur et retourne le rayon mise a jour.
*/
Rayon& Rayon::operator+=(const Produit* produit)
{
	tousProduits_.push_back(produit);
	return *this;
}
/**
* Compte le nombre de fois qu'apparait un produit passé en parametres dans le rayon
*/
int Rayon::compterDoublons(const Produit& produit) const
{
	int compteur = 0;
	for (int i = 0; i <tousProduits_.size(); i++)
	{
		if (*tousProduits_[i] == produit)
			compteur++;
	}
	return compteur;
}
/**
* Affiche les propriétés du rayon et les produits du rayon
*/
ostream& operator<<(ostream &os,const Rayon& rayon)
{
	os << "Le rayon " << rayon.obtenirCategorie() << ":" << endl;
	for (int i = 0; i < rayon.obtenirTousProduits().size(); i++)
	{
		os << *(rayon.obtenirTousProduits()[i]);
	}
	return os;
}
