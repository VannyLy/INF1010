////////////////////////////////////////////////////////////////////////////////////
//FICHIER BASEDEDONNEES.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet BaseDeDonees: ajouterConnection(),
//				retirerConnection(), mettreAJourConenction() et mettreAJourDonnees().
////////////////////////////////////////////////////////////////////////////////////

#include "BaseDeDonnees.h"
using namespace std;

bool BaseDeDonnees::ajouterConnection(Connection* connection) //Méthode qui prend en paramètre un pointeur de Connection. 
//Elle retourne true lorsqu’une Connection est ajoutée avec succès.Elle retourne false lorsque la Connection est déjà présente.

{
	for (int i = 0; i < connections_.size(); i++)
	{ 
		if (connections_[i] == connection)
			return false;
	}
	connections_.push_back(connection);
	return true;
}	

bool BaseDeDonnees::retirerConnection(Connection* connection) //Méthode qui prend en paramètre un pointeur de Connection. 
//Elle retourne true lorsqu’une Connection est retirée avec succès. Elle retourne false lorsque la Connection est absente.
{
	for (int i = 0; i < connections_.size(); i++)
	{
		if (connections_[i] == connection)
		{
			connections_[i] = connections_.back();
			connections_.pop_back();
			return true;
		}
	}
	return false;
}

void BaseDeDonnees::mettreAJourConnections() //Méthode qui met à jour toutes les éléments contenus dans l'attribut
//connections_ en appelant Connection::mettreAJourConnection().
{
	for (int i = 0; i < connections_.size(); i++)
	{
		connections_[i]->mettreAJourConnection(this);
	}
}

//Méthode qui met à jour les données
//MANQUANT