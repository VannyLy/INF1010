////////////////////////////////////////////////////////////////////////////////////
//FICHIER		ETUDIANT.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, 
//				de suppression d'un objet section et d'affichage des attributs d'un objet Etudiant.
////////////////////////////////////////////////////////////////////////////////////

#include "Etudiant.h"
using namespace std;

//Initialisation par defaut
Etudiant::Etudiant()
{
	nom_ = "";
	prenom_ = "";
}

//Initialisation par parametre 
Etudiant::Etudiant(const std::string nom, const std::string prenom)
{
	nom_ = nom;
	prenom_ = prenom;
}

//Methode de suppression
Etudiant::~Etudiant()
{
}

//Methode d'acces aux atributs

unsigned int Etudiant::getNiveauAcces() const
{
	return accesEtudiant_ ;
}

std::string Etudiant::getClasseEmploye() const
{
	return typeid(*this).name();
}


//AFFICHAGE DES ATTRIBUTS
std::ostream& operator<< (std::ostream& os, const Etudiant& etudiant)
{
	os << static_cast<Employe>(etudiant)
		<< "Niveau d'acces:" << etudiant.getNiveauAcces() << std::endl
		<< "Classe :" << etudiant.getClasseEmploye() << std::endl;
	return os;
}
