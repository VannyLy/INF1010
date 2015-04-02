////////////////////////////////////////////////////////////////////////////////////
//FICHIER AFFICHER.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type Afficheur ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <string>

using namespace std;

class Afficheur
{
public:
	virtual ~Afficheur(){}

	virtual void	afficherFrancais()	const = 0; //Méthode permettant l'affichage des données en anglais

	virtual void	afficherAnglais()	const = 0; //Méthode permettant l'affichage des données en francais

	virtual string	getTypeAfficheur()	const  //Méthode qui retourne un string qui représente le type de l'afficheur 
	{
		return typeid(Afficheur).name();
	}
};

#endif