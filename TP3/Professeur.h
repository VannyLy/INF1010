#pragma once

////////////////////////////////////////////////////////////////////////////////////
//FICHIER		PROFESSEUR.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type Professeur ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////


#include <string>
#include "Employe.h"

class Professeur : public Employe
{
public:
	Professeur();
	Professeur(const std::string nom, const std::string prenom);
	~Professeur();

	unsigned int getNiveauAcces() const;
	std::string getClasseEmploye() const;

	friend std::ostream& operator<< (std::ostream& os, const Professeur& professeur);

private:
	unsigned int accesProfesseur_ = 10;
};

