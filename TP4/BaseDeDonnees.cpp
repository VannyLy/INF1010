////////////////////////////////////////////////////////////////////////////////////
//FICHIER BASEDEDONNEES.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet BaseDeDonees: ajouterConnection(),
//				retirerConnection(), mettreAJourConenction() et mettreAJourDonnees().
////////////////////////////////////////////////////////////////////////////////////

#include "BaseDeDonnees.h"
using namespace std;

bool BaseDeDonnees::ajouterConnection(Connection* connection) //M�thode qui prend en param�tre un pointeur de Connection. 
//Elle retourne true lorsqu�une Connection est ajout�e avec succ�s.Elle retourne false lorsque la Connection est d�j� pr�sente.

{
	for (int i = 0; i < connections_.size(); i++)
	{ 
		if (connections_[i] == connection)
			return false;
	}
	connections_.push_back(connection);
	return true;
}	

bool BaseDeDonnees::retirerConnection(Connection* connection) //M�thode qui prend en param�tre un pointeur de Connection. 
//Elle retourne true lorsqu�une Connection est retir�e avec succ�s. Elle retourne false lorsque la Connection est absente.
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

void BaseDeDonnees::mettreAJourConnections() //M�thode qui met � jour toutes les �l�ments contenus dans l'attribut
//connections_ en appelant Connection::mettreAJourConnection().
{
	for (int i = 0; i < connections_.size(); i++)
	{
		connections_[i]->mettreAJourConnection(this);
	}
}

//M�thode qui met � jour les donn�es
//MANQUANT