////////////////////////////////////////////////////////////////////////////////////
//FICHIER		SECTION.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type Secion ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////
#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <string>
#include "Etudiant.h"
#include "Professeur.h"

using namespace std;

class Section
{
public:
	Section();
	Section(const string& sigle, const string& local, const string& titre, Professeur* prof);
	~Section();

	// Les accesseurs
	string getSigle() const;
	string getLocal() const;
	string getTitre() const;
	Professeur* getProf() const; 
	unsigned int getNbEtudiant() const;

	// Les mutateurs
	void setSigle(const string& sigle);
	void setLocal(const string& local);
	void setTitre(const string& titre);
	void setProf(Professeur* prof);



	//Methode qui ajoute etudiant dans setion
	bool ajouterEtudiant(Etudiant* etudiant);
	//Methode d'affichage des atributs d'un objet Etudiant
	void afficher() const;

private:
	string sigle_;
	string local_;
	string titre_;
	Professeur* prof_;
	Etudiant* tableauEtudiants_;
	unsigned int nbEtudiant_;

};

#endif