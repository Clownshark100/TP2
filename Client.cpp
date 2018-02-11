/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
*******************************************/

#include "Client.h"
/**
*Constructeurs par defaut et par paraametres
*/
Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ new Panier() }
{
}
/**
*Constructeurs par copie de client
*/
Client::Client(const Client& copie) :
	nom_{ copie.nom_ },
	prenom_{ copie.prenom_ },
	identifiant_{ copie.identifiant_},
	codePostal_{ copie.codePostal_ },
	dateNaissance_{ copie.dateNaissance_ },
	monPanier_{ new Panier(*(copie.obtenirPanier())) }
{
}
/**
* Destructeur de Rayon, desalloue panier.
*/
Client::~Client()
{
	delete monPanier_;
}

// Methodes d'acces
/**
* Accesseur de nom_
*/
string Client::obtenirNom() const
{
	return nom_;
}
/**
* Accesseur de prénom_
*/
string Client::obtenirPrenom() const
{
	return prenom_;
}
/**
* Accesseur de identifiant_
*/
int Client::obtenirIdentifiant() const
{
	return identifiant_;
}
/**
* Accesseur de codePostal_
*/
string Client::obtenirCodePostal() const
{
	return codePostal_;
}
/**
* Accesseur de dateNaissance_
*/
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}
/**
* Accesseur de monPanier_
*/
Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
/**
* Modifie le nom du client
*/
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}
/**
* Modifie le prenom du client
*/
void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}
/**
* Modifie l'identifiant du client
*/
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}
/**
* Modifie le code postal du client
*/
void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}
/**
* Modifie la date de naissance du client
*/
void Client::modifierDateNaissance(const long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
/**
* Ajoute un produit au panier du client
*/
void Client::acheter(const Produit * prod)
{
	monPanier_->ajouter(prod);
}
/**
* Vide le panier du client.
*/
void Client::livrerPanier()
{
	monPanier_->livrer();
}
/**
* Operateur qui copie l'information et le panier d'un client dans un autre client
*/
void Client::operator=(const Client& client)
{

	delete monPanier_;
	monPanier_ = new Panier( *(client.monPanier_) );

	nom_ = client.nom_;
	prenom_ = client.nom_;
	identifiant_ = client.identifiant_;
	codePostal_ = client.codePostal_;
	dateNaissance_ = client.dateNaissance_;

}
/**
* Operateur qui compare l'indentifiant de client.
*/
bool Client::operator==(const int id) const
{
	return identifiant_ == id;
}
/**
* Operateur qui affiche le contenu du panier.
*/
ostream& operator<<(ostream &os, const Client& client)
{
	if (client.obtenirPanier()->obtenirNombreContenu() != 0) {
		os << "Le panier de " << client.obtenirPrenom() << ": " << endl
		<< *(client.obtenirPanier());
	}
	else {
		os << "Le panier de " << client.obtenirPrenom() << " est vide !" << endl;
	}
	return os;
}
/**
* Operateur qui compare un identifiant à l'identifiant d'un client.
*/
bool operator==(const int id, const Client & client)
{
	return id == client.obtenirIdentifiant();
}
