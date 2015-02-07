////////////////////////////////////////////////////////////////////////////////////
//FICHIER		ETUDIANT.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type Etudiant ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////
#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>
#include <string>

using namespace std;

class Etudiant
{
public:
	Etudiant();
	Etudiant(const string& matricule, const string& prenom, const string& nom);
	~Etudiant();

	// Les accesseurs
	string getMatricule() const;
	string getPrenom() const;
	string getNom() const;

	// Les mutateurs
	void setNom(const string& nom);
	void setPrenom(const string& prenom);
	void setMatricule(const string& matricule);
	//Methodes publiques
	void afficher() const;

private:
	string matricule_;
	string prenom_;
	string nom_;
};


#endif