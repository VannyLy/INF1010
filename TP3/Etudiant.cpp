#include "Etudiant.h"


Etudiant::Etudiant()
{
	nom_ = "";
	prenom_ = "";
}

Etudiant::Etudiant(const std::string nom, const std::string prenom)
{
	nom_ = nom;
	prenom_ = prenom;
}


Etudiant::~Etudiant()
{
}

//Methode d'acces aux atributs

unsigned int Etudiant::getNiveauAcces() const
{
	return accesEtudiant_ + Employe::getNiveauAcces();
}

std::string Etudiant::getClasseEmploye() const
{
	return typeid(*this).name();
}


//AFFICHAGE DES ATTRIBUTS
std::ostream& operator<< (std::ostream& os, const Etudiant& etudiant)
{
	os << static_cast<Employe>(etudiant)
		<< "Niveau d'acces:" << etudiant.getNiveauAcces << std::endl
		<< "Classe :" << etudiant.getClasseEmploye << std::endl;
	return os;
}
