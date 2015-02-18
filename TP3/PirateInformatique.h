#pragma once

////////////////////////////////////////////////////////////////////////////////////
//FICHIER		PIRATEINFORMATIQUE.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type PirateInformatique ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////


#include "AgentSecurite.h"

class PirateInformatique : public AgentSecurite
{
public:
	PirateInformatique();
	PirateInformatique(const AgentSecurite& agentSecurite);
	~PirateInformatique();

	unsigned int getNiveauAcces() const;

};

