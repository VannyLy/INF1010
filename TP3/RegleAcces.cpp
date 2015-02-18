////////////////////////////////////////////////////////////////////////////////////
//FICHIER		REGLEACCES.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, 
//				de suppression d'un objet section et d'affichage des attributs d'un objet RegleAcces.
////////////////////////////////////////////////////////////////////////////////////

#include "RegleAcces.h"

using namespace std;

//Initialisation par defaut
RegleAcces::RegleAcces()
{
	local_ = "";
	niveauAccesRequis_ = 1;
	periode_ = "Matin";
}

//Initialisation par parametre 
RegleAcces::RegleAcces(unsigned int niveau, const string& local, const string& periode)
{
	local_ = local;
	niveauAccesRequis_ = niveau;
	periode_ = periode;
}


//Methode d'acces aux atributs
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

//Surcharge d'operateur==
bool RegleAcces::operator == (const RegleAcces& regle) const
{
	if (local_ == regle.getLocal() && niveauAccesRequis_ == regle.getNiveauAccesRequis() && periode_ == regle.getLocal())
		return true;
	else
		return false;
}