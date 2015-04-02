////////////////////////////////////////////////////////////////////////////////////
//FICHIER AFFICHEURMETEO.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet AfficheurMeteo: afficherFrancais(),
//				afficherAnglais(), getTypeAfficheur(), mettreAJourConnection().
////////////////////////////////////////////////////////////////////////////////////

#include "AfficheurMeteo.h"
#include <iostream>
using namespace std;


void AfficheurMeteo::afficherFrancais() const //Méthode d'affichage de la météo dans la langue francaise
{
	cout << "---------------------Afficheur Meteo-----------------------" << endl << endl;
	cout << "Temperature courante: " << donnees_.getTemperature() << " degres Celsius" << endl 
		<< "Vitesse du vent: " << donnees_.getVent() << " km/h" << endl 
		<< "Visibilite: " << donnees_.getVisibilite() << " km" << endl << endl;
}

void AfficheurMeteo::afficherAnglais() const //Méthode d'affichage de la météo dans la langue anglaise
{
	cout << "---------------------Weather-----------------------" << endl << endl;
	cout << "Current temperature: " << donnees_.getTemperature() << " degrees Celsius" << endl 
		<< "Wind speed: " << donnees_.getVent() << " km/h" << endl 
		<< "Visibility: " << donnees_.getVisibilite() << " km" << endl << endl;
}

std::string AfficheurMeteo::getTypeAfficheur() const //Méthode qui retourne le type de l'afficheur sous forme de string
{
	return typeid(AfficheurMeteo).name();
}


void AfficheurMeteo::mettreAJourConnection(BaseDeDonnees* donnees) //Méthode qui met à jour les connections lorsque la classe Meteo l'appelle.
{
	donnees_ = *dynamic_cast<Meteo*> (donnees);
}
