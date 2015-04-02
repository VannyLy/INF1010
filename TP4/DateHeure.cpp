////////////////////////////////////////////////////////////////////////////////////
//FICHIER DATEHEURE.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet DateHeure: mettreAJourDonnees().
////////////////////////////////////////////////////////////////////////////////////

#include "DateHeure.h"
using namespace std;

//Initialisation par defaut
DateHeure::DateHeure()
{
	heure_ = 0;
	minute_ = 0;
	seconde_ = 0;
	jourMois_ = 0;
	jourSemaine_ = 0;
	mois_ = 0;
	annee_ = 0;
}

 /// Accesseurs
unsigned int DateHeure::getHeure() const
{
	return heure_;
}

unsigned int DateHeure::getMinute() const
{
	return minute_;
}

unsigned int DateHeure::getSeconde() const
{
	return seconde_;
}

unsigned int DateHeure::getJourMois() const
{
	return jourMois_;
}

unsigned int DateHeure::getJourSemaine() const
{
	return jourSemaine_;
}

unsigned int DateHeure::getMois() const
{
	return mois_;
}

unsigned int DateHeure::getAnnee() const
{
	return annee_;
}

void DateHeure::mettreAJourDonnees() //Méthode qui met à jour les attributs à l'heure actuelle de l'ordinateur.
{
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	
	heure_ = timeinfo.tm_hour;
	minute_ = timeinfo.tm_min;
	seconde_ = timeinfo.tm_sec;
	jourMois_ = timeinfo.tm_mday;
	jourSemaine_ = timeinfo.tm_wday;
	mois_ = timeinfo.tm_mon;
	annee_ = 1900 + timeinfo.tm_year;
	mettreAJourConnections();
}
