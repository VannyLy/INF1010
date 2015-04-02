////////////////////////////////////////////////////////////////////////////////////
//FICHIER METEO.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type Meteo ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef	METEO_H
#define METEO_H

#include "BaseDeDonnees.h"
#include <ctime>
#include <cstdlib>

class Meteo : public BaseDeDonnees
{
public:
	Meteo();//Constructeur par défaut
	Meteo(float temperature, float vent, float visibilite);//Constructeur par paramètres
	~Meteo();//Destructeur

	///// Accesseurs //////
	float getTemperature() const;
	float getVent() const;
	float getVisibilite() const;


	virtual void mettreAJourDonnees();


private:
	float temperature_;
	float vent_;
	float visibilite_;

};

#endif