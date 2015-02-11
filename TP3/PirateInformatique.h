#pragma once

#include "AgentSecurite.h"

class PirateInformatique : public AgentSecurite
{
public:
	PirateInformatique();
	PirateInformatique(const AgentSecurite& agentSecurite);
	~PirateInformatique();

	unsigned int getNiveauAcces() const;

};

