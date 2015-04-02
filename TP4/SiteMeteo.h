////////////////////////////////////////////////////////////////////////////////////
//FICHIER SITEMETEO.H
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce fichier d'entete declare un objet de type SiteMeteo ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////

#ifndef	SITE_METEO_H
#define SITE_METEO_H

#include "Afficheur.h"
#include <vector>

using namespace std;

enum Langue
{
	FRANCAIS,
	ANGLAIS
};


class SiteMeteo
{
public:
	SiteMeteo();


	void ajouterAfficheur(Afficheur* afficheur);
	void retirerAfficheur(Afficheur* afficheur);

	void afficherSite();

	Langue getLangue() const;
	void setLangue(Langue langue);


private:
	vector<Afficheur*> afficheurs_;

	Langue langue_;
};


#endif