////////////////////////////////////////////////////////////////////////////////////
//FICHIER		AGENTSECURITE.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, 
//				de suppression d'un objet section et d'affichage des attributs d'un objet AgentSecurite.
////////////////////////////////////////////////////////////////////////////////////

#include "AgentSecurite.h"
#include <string>
using namespace std;

//Initialisation par defaut
AgentSecurite::AgentSecurite()
{
	nom_ = "";
	prenom_ = "";
}

//Initialisation par parametre 
AgentSecurite::AgentSecurite(const std::string nom, const std::string prenom)
{
	nom_ = nom;
	prenom_ = prenom;
}

//Methode de suppression
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
		<< "Niveau d'acces:" << agentSecurite.getNiveauAcces() << std::endl
		<< "Classe :" << agentSecurite.getClasseEmploye() << std::endl;
	return os;
}
