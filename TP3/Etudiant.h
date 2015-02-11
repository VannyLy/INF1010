#pragma once
#include <string>
#include "Employe.h"

class Etudiant : public Employe
{
public:
	Etudiant();
	Etudiant(const std::string nom, const std::string prenom);
	~Etudiant();

	unsigned int getNiveauAcces() const;
	std::string getClasseEmploye() const;

	friend std::ostream& operator<< (std::ostream& os, const Etudiant& etudiant);

private:
	unsigned int accesEtudiant_ = 1;
};

