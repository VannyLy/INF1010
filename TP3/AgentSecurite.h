#pragma once
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

