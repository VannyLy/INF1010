////////////////////////////////////////////////////////////////////////////////////
//FICHIER		PIRATEINFORMATIQUE.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, 
//				de suppression d'un objet section et d'affichage des attributs d'un objet PirateInformatique.
////////////////////////////////////////////////////////////////////////////////////

#include "PirateInformatique.h"
using namespace std;
//Initialisation par defaut
PirateInformatique::PirateInformatique()
{
}

//Initialisation par parametre 
PirateInformatique::PirateInformatique(const AgentSecurite& agentSecurite)
{
	nom_ = agentSecurite.getNom();
	prenom_ = agentSecurite.getPrenom();

}

//Methode de suppression
PirateInformatique::~PirateInformatique()
{
}

//Methode d'acces aux atributs
unsigned int PirateInformatique::getNiveauAcces() const
{
	return AgentSecurite::getNiveauAcces() + Employe::getNiveauAcces();
}
