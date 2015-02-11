#include "Employe.h"
#include <string>
#include <typeinfo>

//Initialisation par defaut
Employe::Employe()
{
	nom_ = "";
	prenom_ = "";
}

//Initialisation par parametre 
Employe::Employe(const std::string nom, const std::string prenom)
{
	nom_ = nom;
	prenom_ = prenom;
}

//Methode de suppression
Employe::~Employe()
{
}

//Methode d'acces aux atributs
std::string Employe::getNom() const {
	return nom_;
}

std::string Employe::getPrenom() const {
	return prenom_;
}

unsigned int Employe::getNiveauAcces() const
{
	return accesEmploye_;
}

std::string Employe::getClasseEmploye() const
{
	return typeid(*this).name();
}


//AFFICHAGE DES ATTRIBUTS
std::ostream& operator<< (std::ostream& os, const Employe& employe)
{
	os << "Nom :" << employe.nom_ << std::endl
		<< "Prenom :" << employe.prenom_ << std::endl;
//		<< "Niveau d'acces:" << employe.accesEmploye_ << std::endl
//		<< "Classe :" << employe.getClasseEmploye() << std::endl;
	return os;
}