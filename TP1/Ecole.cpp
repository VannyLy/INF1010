////////////////////////////////////////////////////////////////////////////////////
//FICHIER		ECOLE.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, de modification des atributs de l'objet,
//				d'ajout d'un objet section, de suppression d'un objet section et d'affichage des attributs d'un objet Ecole
////////////////////////////////////////////////////////////////////////////////////
#include "Ecole.h"


//Initialisation d'un objet Ecole par defaut
Ecole::Ecole()
{
	nom_ = "";
	adresse_ = "";
	nombreSection_ = 0;
}

//Initialisation d'un objet Ecole par parametre

Ecole::Ecole(const string& nom, const string& adresse)
{
	nom_ = nom;
	adresse_ = adresse;
	nombreSection_ = 0;
}

//Supression d'un objet Ecole

Ecole::~Ecole()
{
	for (size_t i = 0; i < 50; i++)
	{
		sections_[i] = NULL;
	}
		
}

//Methode d'acces des attributs d'un objet Ecole

string Ecole::getNom() const {
	return nom_;
}

string Ecole::getAdresse() const {
	return adresse_;
}

unsigned int Ecole::getNombreSection() const {
	return nombreSection_;
}

//Methode de modification des atributs d'un objet Ecole

void Ecole::setNom(const string& nom) {
	nom_ = nom;
}

void Ecole::setAdresse(const string& adresse){
	adresse_ = adresse;
}

//Methode pour ajouter une section
bool Ecole::ajouterSection(Section* section){
	if (nombreSection_ < 50){//Si le nombre de section n'a pas ete atteint
		for (int i = 0; i < nombreSection_; i++)
		{
			if (sections_[i]->getLocal() == section->getLocal())//comparaison des locaux
			{
				cout << "La section existe deja!" << endl;
				return false;
			}
		}
		sections_[nombreSection_] = section;
		cout << "La section a bien ete ajoutee!" << endl;
		nombreSection_++;
		return true;
			

	}
}

//Methode pour supprimer une section
bool Ecole::supprimerSection(const string& local){
	for (int i = 0; i < nombreSection_; i++)
	{
		if (sections_[i]->getLocal() == local)
		{
			sections_[i] = 0;
			for (int j = i; j < 49;j++)
			{
				sections_[j] = sections_[j + 1];
			}
			nombreSection_--;
			sections_[nombreSection_] = NULL;
			cout << "La section a ete supprimee!" << endl;
			return true;
		}
	}
	cout << "La section n'existe pas!" << endl;
	return false;
}

//Methode d'affichage des attributs d'un objet Ecole

void Ecole::afficher() const{
	cout << "Nom : " << nom_ << endl << "Adresse : " << adresse_ << endl << "Nombre De Section : " << nombreSection_ << endl;
}