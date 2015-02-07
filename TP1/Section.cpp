////////////////////////////////////////////////////////////////////////////////////
//FICHIER		ECOLE.CPP
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			2 FEVRIER 2015
//DESCRIPTION	Ce programme déclare les méthodes d'initialisation par defaut et par parametre, de modification des atributs de l'objet,
//				d'ajout d'un objet Etudiant, de suppression d'un objet Etudiant et d'affichage des attributs d'un objet Section
////////////////////////////////////////////////////////////////////////////////////
#include "Section.h"

//initialisation par defaut d'un objet Section
Section::Section()
{
	sigle_ = "";
	local_ = "";
	titre_ = "";
	nbEtudiant_ = 0;
	tableauEtudiants_ = new Etudiant[75];
}

//Initialisation par parametre d'un objet Section
Section::Section(const string& sigle, const string& local, const string& titre, Professeur* prof)
{
	sigle_ = sigle;
	local_ = local;
	titre_ = titre;
	prof_ = prof;
	tableauEtudiants_ = new Etudiant[75];

}

//Methode de suppression d'un objet Section
Section::~Section()
{
}


//Methode d'acces aux atributs d'un objet Section 
string Section::getSigle() const {
	return sigle_;
}

string Section::getLocal() const {
	return local_;
}

string Section::getTitre() const {
	return titre_;
}

Professeur* Section::getProf() const {
	return prof_;
}


unsigned int Section::getNbEtudiant() const {
	return nbEtudiant_;
}
//Methode de modification des atributs d'un objet Section
void Section::setSigle(const string& sigle){
	sigle_ = sigle;
}

void Section::setLocal(const string& local){
	local_ = local;
}

void Section::setTitre(const string& titre){
	titre_ = titre;
}

void Section::setProf(Professeur* prof){
	prof_ = prof;
}


//Methode d'ajout d'un objet Etudiant a l'objet Section
bool Section::ajouterEtudiant(Etudiant* etudiant){
	if(nbEtudiant_ < 75)
	{
		for (int i = 0; i < 75; i++){
			if (tableauEtudiants_[i].getMatricule() == etudiant->getMatricule())
			{
				cout << "L'etudiant est deja inscrit!" << endl;
				return false;
			}
			else
			{
				tableauEtudiants_[nbEtudiant_] = *etudiant;
				nbEtudiant_++;
				cout << "L'etudiant a ete ajoute dans la section avec succes!" << endl;
				return true;
			}
		}
	}
	else
	{
		cout << "La section est deja pleine!";
		return false;
	}
}

//Methode d'affichage des atributs d'un objet Section
void Section::afficher() const{
	cout << "Sigle : " << sigle_ << endl << "Local : " << local_ << endl << "Titre : " << titre_ << endl;
}