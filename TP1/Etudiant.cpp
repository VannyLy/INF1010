////////////////////////////////////////////////////////////////////////////////////
//FICHIER		ETUDIANT.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, de modification des atributs de l'objet Etudiant,
//				d'affichage des données de l'objet Etudiant
////////////////////////////////////////////////////////////////////////////////////
#include "Etudiant.h"

//Initialisation par defaut d'un objet Etudiant
Etudiant::Etudiant()
{
	matricule_ = "";
	prenom_ = "";
	nom_ = "";
}


//Initialisation par parametre d'un objet Etudiant par parametre
Etudiant::Etudiant(const string& matricule, const string& prenom, const string& nom)
{
	matricule_ = matricule;
	prenom_ = prenom;
	nom_ = nom;
}


//Supression d'un objet Etudiant
Etudiant::~Etudiant()
{
}

//Methode d'acces des atributs d'un objet Etudiant
string Etudiant::getMatricule() const {
	return matricule_;
}

string Etudiant::getPrenom() const {
	return prenom_;
}

string Etudiant::getNom() const {
	return nom_;
}


//Methode de modification d'un objet Etudiant
void Etudiant::setNom(const string& nom){
	nom_ = nom;
}

void Etudiant::setPrenom(const string& prenom){
	prenom_ = prenom;
}

void Etudiant::setMatricule(const string& matricule){
	matricule_ = matricule;
}

//Methode d'affichage des atributs d'un objet Etudiant
void Etudiant::afficher() const{
	cout << "Nom : " << nom_ << endl << "Prenom : " << prenom_ << endl << "Matricule : " << matricule_ << endl;
}