/********************************************
* Titre: Travail pratique #2 - Client.cpp
* Date: 25 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA & Timothée CHAUVIN
*******************************************/

#include "Client.h"

Client::Client(const string&  nom, const string& prenom, int identifiant, const string& codePostal, long date) :
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal },
	dateNaissance_{ date },
	monPanier_{ new Panier() }
{
}

Client::Client(Client& copie) :
	nom_{ copie.nom_ },
	prenom_{ copie.prenom_ },
	identifiant_{ copie.identifiant_},
	codePostal_{ copie.codePostal_ },
	dateNaissance_{ copie.dateNaissance_ },
	monPanier_{ new Panier(*(copie.obtenirPanier())) }
{
}

Client::~Client()
{
	delete monPanier_;
}

// Methodes d'acces
string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}

string Client::obtenirCodePostal() const
{
	return codePostal_;
}

long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

Panier * Client::obtenirPanier() const
{
	return monPanier_;
}

// Methodes de modification
void  Client::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

// Autres méthodes
void Client::acheter(Produit * prod)
{
	monPanier_->ajouter(prod);
}

void Client::livrerPanier()
{
	monPanier_->livrer();
}

void Client::operator=(Client& client)
{

	delete monPanier_;
	monPanier_ = new Panier( *(client.monPanier_) );

	nom_ = client.nom_;
	prenom_ = client.nom_;
	identifiant_ = client.identifiant_;
	codePostal_ = client.codePostal_;
	dateNaissance_ = client.dateNaissance_;

}

bool Client::operator==(int id) const
{
	return identifiant_ == id;
}

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

bool operator==(const int id, const Client & client)
{
	return id == client.obtenirIdentifiant();
}
