#ifndef ECOLE_H
#define ECOLE_H

////////////////////////////////////////////////////////////////////////////////////
//FICHIER		ECOLE.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type Ecole ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "Section.h"

using namespace std;




class Ecole
{
public:
	Ecole();
	Ecole(const string& nom, const string& adresse);
	~Ecole();

	// Les accesseurs
	string getNom() const;
	string getAdresse() const;
	unsigned int getNombreSection() const;

	// Les mutateurs
	void setNom(const string& nom);
	void setAdresse(const string& adresse);
	///Methodes publiques
	bool ajouterSection(Section* section);
	bool supprimerSection(const string& local);

	void afficher() const;

private:
	string nom_;
	string adresse_;
	unsigned int nombreSection_;
	Section* sections_[50];
};

#endif