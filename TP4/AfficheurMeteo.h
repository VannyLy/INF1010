////////////////////////////////////////////////////////////////////////////////////
//FICHIER AFFICHEURMETEO.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type AfficheurMeteo ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef	AFFICHEURMETEO_H
#define AFFICHEURMETEO_H

#include "Afficheur.h"
#include "Connection.h"
#include "Meteo.h"

class AfficheurMeteo : public Afficheur , public Connection
{
public:
	virtual void afficherFrancais() const;
	virtual void afficherAnglais() const;
	virtual std::string getTypeAfficheur() const;
	virtual void mettreAJourConnection(BaseDeDonnees* donnees);

private:
	Meteo donnees_;
};
#endif