#pragma once
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

