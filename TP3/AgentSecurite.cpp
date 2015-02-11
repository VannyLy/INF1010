#include "AgentSecurite.h"
#include <string>

AgentSecurite::AgentSecurite()
{
	nom_ = "";
	prenom_ = "";
}

AgentSecurite::AgentSecurite(const std::string nom, const std::string prenom)
{
	nom_ = nom;
	prenom_ = prenom;
}

AgentSecurite::~AgentSecurite()
{
}

//Methode d'acces aux atributs

unsigned int AgentSecurite::getNiveauAcces() const
{
	return accesAgentSecurite_ + Employe::getNiveauAcces();
}

std::string AgentSecurite::getClasseEmploye() const
{
	return typeid(*this).name();
}


//AFFICHAGE DES ATTRIBUTS
std::ostream& operator<< (std::ostream& os, const AgentSecurite& agentSecurite)
{
	os << static_cast<Employe>(agentSecurite)
		<< "Niveau d'acces:" << agentSecurite.getNiveauAcces << std::endl
		<< "Classe :" << agentSecurite.getClasseEmploye << std::endl;
	return os;
}
