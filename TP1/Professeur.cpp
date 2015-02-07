////////////////////////////////////////////////////////////////////////////////////
//FICHIER		PROFESSEUR.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, de modification des atributs de l'objet Professeur,
//				d'affichage des données de l'objet Etudiant
////////////////////////////////////////////////////////////////////////////////////
#include "Professeur.h"

//Initialisation par defaut d'un objet Professeur
Professeur::Professeur()
{
	numeroEmploye_ = "";
	prenom_ = "";
	nom_ = "";
	departement_ = "";
}

//Initialisation par parametre d'un objet Professeur
Professeur::Professeur(const string& numeroEmploye, const string& prenom, const string& nom, const string& departement)
{
	numeroEmploye_ = numeroEmploye;
	prenom_ = prenom;
	nom_ = nom;
	departement_ = departement;
}

//Methode de suppression d'un objet Professeur
Professeur::~Professeur()
{
}

//Methode d'acces aux atributs d'un objet Professeur
string Professeur::getNumeroEmploye() const {
	return numeroEmploye_;
}

string Professeur::getPrenom() const {
	return prenom_;
}

string Professeur::getNom() const {
	return nom_;
}

string Professeur::getDepartement() const {
	return departement_;
}

//Methode de modifications des atributs d'un objet Professeur
void Professeur::setNumeroEmploye(const string& numeroEmploye){
	numeroEmploye_ = numeroEmploye;
}

void Professeur::setPrenom(const string& prenom){
	prenom_ = prenom;
}

void Professeur::setNom(const string& nom){
	nom_ = nom;
}

void Professeur::setDepartement(const string& departement){
	departement_ = departement;
}

//Methode d'ffichage des atributs d'un objet Professeur
void Professeur::afficher() const{
	cout << "Numero d'employe : " << numeroEmploye_ << endl << "Nom : " << nom_ << endl << "Prenom : " << prenom_ << endl << "Departement : " << departement_ << endl;
}