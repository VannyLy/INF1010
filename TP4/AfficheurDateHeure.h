////////////////////////////////////////////////////////////////////////////////////
//FICHIER AFFICHEURDATEHEURE.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type AfficheurDateheure ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef AFFICHEUR_DATE_HEURE_H
#define AFFICHEUR_DATE_HEURE_H

#include "Afficheur.h"
#include "Connection.h"
#include "DateHeure.h"

class AfficheurDateHeure : public Afficheur, public Connection
{
public:
	virtual void afficherFrancais() const;
	virtual void afficherAnglais() const;
	virtual std::string getTypeAfficheur() const;
	virtual void mettreAJourConnection(BaseDeDonnees* donnees);

private:
	DateHeure dateHeure_;

};

const std::string JOUR_STRING_FR[] = { "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };
const std::string MOIS_STRING_FR[] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

const std::string JOUR_STRING_EN[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
const std::string MOIS_STRING_EN[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };


#endif