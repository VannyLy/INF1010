#include "RegleAcces.h"

RegleAcces::RegleAcces()
{
	local_ = "";
	niveauAccesRequis_ = 1;
	periode_ = "Matin";
}

RegleAcces::RegleAcces(unsigned int niveau, const string& local, const string& periode)
{
	local_ = local;
	niveauAccesRequis_ = niveau;
	periode_ = periode;
}


string RegleAcces::getLocal() const
{
	return local_;
}
unsigned int RegleAcces::getNiveauAccesRequis()	const
{
	return niveauAccesRequis_;
}
string RegleAcces::getPeriode() const
{
	return periode_;
}

bool RegleAcces::operator == (const RegleAcces& regle) const
{
	if (local_ == regle.local_ && niveauAccesRequis_ == regle.niveauAccesRequis_ && periode_ == regle.periode_)
		return true;
	else
		return false;
}