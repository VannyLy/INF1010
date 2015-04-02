////////////////////////////////////////////////////////////////////////////////////
//FICHIER AFFICHEURDATEHEURE.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet AfficheurDateheure: afficherFrancais(),
//				afficherAnglais(), getTypeAfficheur(), mettreAJourConnection().
////////////////////////////////////////////////////////////////////////////////////

#include "AfficheurDateHeure.h"
#include <iostream>
using namespace std;

void AfficheurDateHeure::afficherFrancais() const //M�thode d'affichage de la m�t�o dans la langue francaise
{
	cout << "---------------------Afficheur Date et Heure-----------------------" << endl << endl;
	cout << JOUR_STRING_FR[dateHeure_.getJourSemaine()] 
		<< " le " << dateHeure_.getJourMois()
		<< " " << MOIS_STRING_FR[dateHeure_.getMois()]
		<< " " << dateHeure_.getAnnee() << ", " 
		<< dateHeure_.getHeure() << "h " 
		<< dateHeure_.getMinute() << "min et " 
		<< dateHeure_.getSeconde() << "sec" << endl << endl;
}

void AfficheurDateHeure::afficherAnglais() const //M�thode d'affichage de la m�t�o dans la langue anglaise
{
	cout << "---------------------Date and Time-----------------------" << endl << endl;
	cout << JOUR_STRING_EN[dateHeure_.getJourSemaine()] << " "
		<< MOIS_STRING_EN[dateHeure_.getMois()] << " "
		<< dateHeure_.getJourMois()
		<< " " << dateHeure_.getAnnee() << ", "
		<< dateHeure_.getHeure() << "h "
		<< dateHeure_.getMinute() << "min and "
		<< dateHeure_.getSeconde() << "sec" << endl << endl;
}

std::string AfficheurDateHeure::getTypeAfficheur() const //M�thode qui retourne le type de l'afficheur sous forme de string. 
{
	return typeid(AfficheurDateHeure).name();
}

void AfficheurDateHeure::mettreAJourConnection(BaseDeDonnees* donnees) //M�thode qui met � jour les connections lorsque la classe DateHere l'appelle.
{
	dateHeure_ = *dynamic_cast<DateHeure*> (donnees);
}
