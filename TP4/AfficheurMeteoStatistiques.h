////////////////////////////////////////////////////////////////////////////////////
//FICHIER METEOSTATISTIQUE.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type MeteoStatistiques ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef	AFFICHEURMETEOSTATISTIQUES_H
#define AFFICHEURMETEOSTATISTIQUES_H

#include "Afficheur.h"
#include "Connection.h"
#include "Meteo.h"

class AfficheurMeteoStatistiques : public Afficheur , public Connection
{
public:
	AfficheurMeteoStatistiques();
	~AfficheurMeteoStatistiques();
	virtual void afficherFrancais() const;
	virtual void afficherAnglais() const;
	virtual std::string getTypeAfficheur() const;
	virtual void mettreAJourConnection(BaseDeDonnees* donnees);

private:
	Meteo* donneesDerniereAnnee_;
	unsigned int nbDonnees_;

};



#endif