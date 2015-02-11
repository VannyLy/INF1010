#include "PirateInformatique.h"


PirateInformatique::PirateInformatique()
{
}

PirateInformatique::PirateInformatique(const AgentSecurite& agentSecurite)
{
	nom_ = agentSecurite.getNom();
	prenom_ = agentSecurite.getPrenom();

}

PirateInformatique::~PirateInformatique()
{
}

//Methode d'acces aux atributs
unsigned int PirateInformatique::getNiveauAcces() const
{
	return AgentSecurite::getNiveauAcces() + Employe::getNiveauAcces();
}
