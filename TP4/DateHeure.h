////////////////////////////////////////////////////////////////////////////////////
//FICHIER DATEHEURE.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type DateHeure ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef	DATEHEURE_H
#define DATEHEURE_H

#include "BaseDeDonnees.h"
#include <time.h>
#include <stdio.h>

class DateHeure : public BaseDeDonnees
{
public:

	//Initialisation par defaut
	DateHeure();

	//Accesseurs
	unsigned int getHeure() const;
	unsigned int getMinute() const;
	unsigned int getSeconde() const;
	unsigned int getJourMois() const;
	unsigned int getJourSemaine() const;
	unsigned int getMois() const;
	unsigned int getAnnee() const;
	
	//Methode public
	virtual void mettreAJourDonnees(); 
	
private:
	unsigned int heure_;
	unsigned int minute_;
	unsigned int seconde_;
	unsigned int jourMois_;
	unsigned int jourSemaine_;
	unsigned int mois_;
	unsigned int annee_;

};

#endif