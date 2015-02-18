#ifndef	SYSTEME_SECURITE_H
#define SYSTEME_SECURITE_H

////////////////////////////////////////////////////////////////////////////////////
//FICHIER		SYSTEMESECURITE.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type SystemeSecurite ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////


#include "RegleAcces.h" 
#include "AgentSecurite.h"
#include "Professeur.h"
#include "Etudiant.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>


class SystemeSecurite
{
public:
	SystemeSecurite();

	bool accederLocal(const AgentSecurite& agent, const std::string& local, const std::string& periode);
	bool accederLocal(const Professeur& prof, const std::string& local, const std::string& periode);
	bool accederLocal(const Etudiant& etudiant, const std::string& local, const std::string& periode);

	bool accederLocal(const std::string& nom, const std::string& prenom, const std::string& fonction, unsigned int niveauAcces, const std::string& local, const std::string& periode);

	bool ajouterRegle(const RegleAcces& regle);

	void imprimerJournal() const;

private:
	std::vector<RegleAcces>		regles_;
	std::vector<std::string>			journalAcces_;
};

#endif //DEPARTEMENT_H