////////////////////////////////////////////////////////////////////////////////////
//FICHIER BASEDEDONNEES.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type BaseDeDonnees ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef	BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include <string>
#include <vector>
#include "Connection.h"

using namespace std;

class BaseDeDonnees
{
protected:
	vector<Connection*> connections_;

public:
	bool ajouterConnection(Connection* connection);
	bool retirerConnection(Connection* connection);
	void mettreAJourConnections();
	virtual void mettreAJourDonnees() = 0;
};

#endif