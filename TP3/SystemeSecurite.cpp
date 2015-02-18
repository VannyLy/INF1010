////////////////////////////////////////////////////////////////////////////////////
//FICHIER		SYSTEMESECURITE.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, 
//				de suppression d'un objet section et d'affichage des attributs d'un objet SystemeSecurite.
////////////////////////////////////////////////////////////////////////////////////

#include "SystemeSecurite.h"
using namespace std;

//Initialisation par defaut
SystemeSecurite::SystemeSecurite() {}

//Surcharge de la methode accederLocal pour une classe AgentSecurite
bool SystemeSecurite::accederLocal(const AgentSecurite& agent, const string& local, const string& periode)
{
	return accederLocal(agent.getNom(), agent.getPrenom(), agent.getClasseEmploye(), agent.getNiveauAcces(), local, periode);
}

//Surcharge de la methode accederLocal pour une classe Professeur
bool SystemeSecurite::accederLocal(const Professeur& prof, const string& local, const string& periode)
{
	return accederLocal(prof.getNom(), prof.getPrenom(), prof.getClasseEmploye(), prof.getNiveauAcces(), local, periode);
}


//Surcharge de la methode accederLocal pour une classe Etudiant
bool SystemeSecurite::accederLocal(const Etudiant& etudiant, const string& local, const string& periode)
{
	return accederLocal(etudiant.getNom(), etudiant.getPrenom(), etudiant.getClasseEmploye(), etudiant.getNiveauAcces(), local, periode);
}

//Methode accederLocal principale avec creation de journal
bool SystemeSecurite::accederLocal(const string& nom, const string& prenom, const string& fonction, unsigned int niveauAcces, const string& local, const string& periode)
{
	stringstream ss;
	//RegleAcces uneRegle(1, local, periode);
	bool acces = false;
	for (int i = 0; i < regles_.size(); i++)
	{
		if (regles_[i].getLocal() == local && regles_[i].getPeriode() == periode && niveauAcces >= regles_[i].getNiveauAccesRequis())
			acces = true;
	}
	string etatAcces;
	if (acces == true)
	{
		etatAcces = "Accorde";
	}
	else etatAcces = "Refuse";
	ss << "Nom, Prenom: " << nom << " " << prenom << endl
		<< "Classe d'employe: " << fonction << endl
		<< "Niveau d'acces: " << niveauAcces << endl
		<< "Local: " << local << endl
		<< "Periode: " << periode << endl
		<< "Acces: " << etatAcces << endl << endl;

	journalAcces_.push_back(ss.str());

	return acces;
}


//Methode ajouterRegle qui sert a ajouter une regle au vecteur regles_
bool SystemeSecurite::ajouterRegle(const RegleAcces& regle)
{
	bool present = false;
	for (int i = 0; i < regles_.size(); i++)
	{
		if (regles_[i] == regle)
		{
			present = true;
		}
	}
	if(!present)
		regles_.push_back(regle);
	return !present;
}

//Methode d'affichage du journal
void SystemeSecurite::imprimerJournal() const
{
	for (int i = 0; i < journalAcces_.size(); i++)
		cout << "-----------------------------------------------------" << endl << journalAcces_[i] ;
}