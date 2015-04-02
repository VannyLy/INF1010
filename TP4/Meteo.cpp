////////////////////////////////////////////////////////////////////////////////////
//FICHIER METEO.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet Meteo: mettreAJourDonnees().
////////////////////////////////////////////////////////////////////////////////////

#include "Meteo.h"
using namespace std;

//Initialisation par defaut
Meteo::Meteo(){}

//Initialisation par parametre 
Meteo::Meteo(float temperature, float vent, float visibilite)
{
	temperature_ = temperature;
	vent_ = vent;
	visibilite_ = visibilite;
}

//Methode de suppression
Meteo::~Meteo(){}

//Methode d'acces aux atributs

float Meteo::getTemperature() const
{
	return temperature_;
}

float Meteo::getVent() const
{
	return vent_;
}

float Meteo::getVisibilite() const
{
	return visibilite_;
}

///methode public
void Meteo::mettreAJourDonnees() //Méthode qui met les données à jour en générant une variation aléatoire de l'ancienne donnée.
{
	srand(time(NULL)); rand();

	///// source pour la fonction random : http://stackoverflow.com/questions/686353/c-random-float-number-generation

	float X = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (0.2 * temperature_)));
	temperature_ = temperature_ + X* pow((-1), rand());

	float Y = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (0.2 * vent_)));
	vent_ = vent_ + Y* pow((-1), rand());

	float Z = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (0.2 * visibilite_)));
	visibilite_ = visibilite_ + Z* pow((-1), rand());

	mettreAJourConnections();
}