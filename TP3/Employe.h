#pragma once
#include <string>
#include <iostream>

class Employe
{
public:
	Employe();
	Employe(const std::string nom, const std::string prenom);
	~Employe();

	// Les accesseurs
	std::string getPrenom() const;
	std::string getNom() const;
	unsigned int getNiveauAcces() const;
	std::string getClasseEmploye() const;


	friend std::ostream& operator<< (std::ostream& os, const Employe& employe);

protected:
	std::string nom_;
	std::string prenom_;
private:
	unsigned int accesEmploye_ = 5;
};

