////////////////////////////////////////////////////////////////////////////////////
//FICHIER METEOSTATISTIQUE.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet MeteoStatistique: afficherFrancais(),
//				afficherAnglais(), getTypeAfficheur(), mettreAJourConnection().
////////////////////////////////////////////////////////////////////////////////////

#include "AfficheurMeteostatistiques.h"
#include <iostream>
using namespace std;

AfficheurMeteoStatistiques::AfficheurMeteoStatistiques() 
{
	donneesDerniereAnnee_ = new Meteo[365];
	nbDonnees_ = 0;
}

AfficheurMeteoStatistiques::~AfficheurMeteoStatistiques()
{
	delete[] donneesDerniereAnnee_;
}

void AfficheurMeteoStatistiques::afficherFrancais() const //Méthode d'affichage de la météo dans la langue francaise
{
	float sommeTemperature = 0;
	float sommeVent = 0;
	float sommeVisibilite = 0;

	for (int i = 0; i < nbDonnees_; i++)
	{
		sommeTemperature += donneesDerniereAnnee_[i].getTemperature();
		sommeVent += donneesDerniereAnnee_[i].getVent();
		sommeVisibilite += donneesDerniereAnnee_[i].getVisibilite();
	}
	cout << "---------------------Afficheur Statistiques Meteo-----------------------" << endl << endl;
	cout << "Temperature moyenne: " << sommeTemperature/nbDonnees_ << " degres Celsius" << endl 
		<< "Vent moyen: " << sommeVent/nbDonnees_ << " km/h" << endl 
		<< "Visibilite moyenne: " << sommeVisibilite/nbDonnees_ << " km" << endl << endl;
}

void AfficheurMeteoStatistiques::afficherAnglais() const //Méthode d'affichage de la météo dans la langue anglaise
{
	float sommeTemperature = 0;
	float sommeVent = 0;
	float sommeVisibilite = 0;

	for (int i = 0; i < nbDonnees_; i++)
	{
		sommeTemperature += donneesDerniereAnnee_[i].getTemperature();
		sommeVent += donneesDerniereAnnee_[i].getVent();
		sommeVisibilite += donneesDerniereAnnee_[i].getVisibilite();
	}
	cout << "---------------------Weather Statistics-----------------------" << endl << endl;
	cout << "Average temperature: " << sommeTemperature / nbDonnees_ << " degrees Celsius" << endl 
		<< "Average wind: " << sommeVent / nbDonnees_ << " km/h" << endl 
		<< "Average visibility: " << sommeVisibilite / nbDonnees_ << " km" << endl << endl;
}

std::string AfficheurMeteoStatistiques::getTypeAfficheur() const //Méthode qui retourne le type de l'afficheur sous forme de string. 
{
	return typeid(AfficheurMeteoStatistiques).name();
}

void AfficheurMeteoStatistiques::mettreAJourConnection(BaseDeDonnees* donnees) //Méthode qui met à jour les connections lorsque la classe Meteo l'appelle.
{
	if (nbDonnees_ < 365)
	{
		donneesDerniereAnnee_[nbDonnees_] = *dynamic_cast<Meteo*> (donnees);
		nbDonnees_++;
	}
	else
		for (int i = 0; i < 364; i++)
		{
			donneesDerniereAnnee_[i] = donneesDerniereAnnee_[i + 1];
		}
	donneesDerniereAnnee_[364] = *dynamic_cast<Meteo*> (donnees);
}

