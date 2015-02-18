#pragma once

////////////////////////////////////////////////////////////////////////////////////
//FICHIER		AGENTSECURITE.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type AgentSecurite ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Employe.h"

class AgentSecurite : public Employe
{
public:
	AgentSecurite();
	AgentSecurite(const std::string nom, const std::string prenom);
	~AgentSecurite();

	unsigned int getNiveauAcces() const;
	std::string getClasseEmploye() const;

	friend std::ostream& operator<< (std::ostream& os, const AgentSecurite& agentSecurite);

private:
	unsigned int accesAgentSecurite_ = 20;
};

