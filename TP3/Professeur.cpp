////////////////////////////////////////////////////////////////////////////////////
//FICHIER		PROFESSEUR.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, 
//				de suppression d'un objet section et d'affichage des attributs d'un objet Professeur.
////////////////////////////////////////////////////////////////////////////////////

#include "Professeur.h"
#include <string>
using namespace std;

//Initialisation par defaut
Professeur::Professeur()
{
	nom_ = "";
	prenom_ = "";
}

//Initialisation par parametre
Professeur::Professeur(const std::string nom, const std::string prenom)
{
	nom_ = nom;
	prenom_ = prenom;
}

//Methode de suppression
Professeur::~Professeur()
{
}


//Methode d'acces aux atributs

unsigned int Professeur::getNiveauAcces() const
{
	return accesProfesseur_ + Employe::getNiveauAcces();
}

std::string Professeur::getClasseEmploye() const
{
	return typeid(*this).name();
}

//AFFICHAGE DES ATTRIBUTS
std::ostream& operator<< (std::ostream& os, const Professeur& professeur)
{
	os << static_cast<Employe>(professeur)
		<< "Niveau d'acces:" << professeur.getNiveauAcces() << std::endl
		<< "Classe :" << professeur.getClasseEmploye() << std::endl;
	return os;
}

