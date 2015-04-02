////////////////////////////////////////////////////////////////////////////////////
//FICHIER CONNECTION.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type Connection qui est une interface
//				qui permet à ses classes dérivées de se connecter à une base de données.
////////////////////////////////////////////////////////////////////////////////////

#ifndef	CONNECTION_H
#define CONNECTION_H

class BaseDeDonnees;

class Connection
{
public:
	virtual void mettreAJourConnection(BaseDeDonnees* donnees) = 0;
};

#endif