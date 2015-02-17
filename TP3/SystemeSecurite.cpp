#include "SystemeSecurite.h"

SystemeSecurite::SystemeSecurite() {}

bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode)
{
	stringstream ss;
	RegleAcces uneRegle(1, local, periode);
	bool acces = false;
	for (int i = 0; i < regles_.size(); i++)
	{
		if (uneRegle == regles_[i] && agent.getNiveauAcces() >= regles_[i].getNiveauAccesRequis)
			acces = true;
	}

	ss << agent << endl
		<< "Local" << local << endl
		<< "Periode" << periode << endl
		<< "Acces: " << (acces ? "Accorde" : "Refuse") << endl << endl;

	journalAcces_.push_back(ss.str());

	return acces;
}

bool SystemeSecurite::accederLocal(const Professeur& prof, const string& local, const string& periode)
{
	stringstream ss;
	RegleAcces uneRegle(1, local, periode);
	bool acces = false;
	for (int i = 0; i < regles_.size(); i++)
	{
		if (uneRegle == regles_[i] && prof.getNiveauAcces() >= regles_[i].getNiveauAccesRequis)
			acces = true;
	}

	ss << prof << endl
		<< "Local" << local << endl
		<< "Periode" << periode << endl
		<< "Acces: " << (acces ? "Accorde" : "Refuse") << endl << endl;

	journalAcces_.push_back(ss.str());

	return acces;
}

bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode)
{
	stringstream ss;
	RegleAcces uneRegle(1, local, periode);
	bool acces = false;
	for (int i = 0; i < regles_.size(); i++)
	{
		if (uneRegle == regles_[i] && etudiant.getNiveauAcces() >= regles_[i].getNiveauAccesRequis)
			acces = true;
	}

	ss << etudiant << endl
		<< "Local" << local << endl
		<< "Periode" << periode << endl
		<< "Acces: " << (acces ? "Accorde" : "Refuse") << endl << endl;

	journalAcces_.push_back(ss.str());

	return acces;
}


bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode)
{
	stringstream ss;
	RegleAcces uneRegle(1, local, periode);
	bool acces = false;
	for (int i = 0; i < regles_.size(); i++)
	{
		if (uneRegle == regles_[i] && niveauAcces >= regles_[i].getNiveauAccesRequis)
			acces = true;
	}

	ss << "Nom, Prenom: " << nom << " " << prenom << endl
		<< "Classe d'employe: " << fonction << endl
		<< "Niveau d'acces: " << niveauAcces << endl
		<< "Local" << local << endl
		<< "Periode" << periode << endl
		<< "Acces: " << (acces ? "Accorde" : "Refuse") << endl << endl;

	journalAcces_.push_back(ss.str());

	return acces;
}

bool SystemeSecurite::ajouterRegle(const RegleAcces& regle)
{
	for (int i = 0; i < regles_.size(); i++)
	{
		if (regles_[i] == regle)
			return false;
		else
		{
			regles_.push_back(regle);
			return true;
		}
	}
}

void SystemeSecurite::imprimerJournal() const
{
	for (int i = 0; i < journalAcces_.size(); i++)
		cout << "-----------------------------------------------------" << endl << journalAcces_[i] ;
}