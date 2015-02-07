////////////////////////////////////////////////////////////////////////////////////
//FICHIER		PROFESSEUR.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type Professeur ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include <iostream>
#include <string>

using namespace std;

class Professeur
{
public:
	Professeur();
	Professeur(const string& numeroEmploye, const string& prenom, const string& nom, const string& departement);
	~Professeur();

	// Les accesseurs
	string getNumeroEmploye() const;
	string getPrenom() const;
	string getNom() const;
	string getDepartement() const;

	// Les mutateurs
	void setNumeroEmploye(const string& numeroEmploye);
	void setPrenom(const string& prenom);
	void setNom(const string& nom);
	void setDepartement(const string& departement);
	//Methodes publiques
	void afficher() const;

private:
	string numeroEmploye_;
	string prenom_;
	string nom_;
	string departement_;

};

#endif