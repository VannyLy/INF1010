////////////////////////////////////////////////////////////////////////////////////
//FICHIER AFFICHEURDATEHEURE.CPP
//AUTEURS Minh DUONG & Thuy-Vanny LY
//DATE 15 MARS 2015
//DESCRIPTION Ce programme implemente les fonctions publiques d'un objet SiteMeteo: afficherSite(), 
//				ajouterAfficheur(), retirerAfficheur().
////////////////////////////////////////////////////////////////////////////////////

#include "SiteMeteo.h"
#include <iostream>
using namespace std;

SiteMeteo::SiteMeteo(){};

void SiteMeteo::ajouterAfficheur(Afficheur* afficheur)//Méthode qui prend un paramettre un pointeur d'afficheur en paramettre et l'ajoute au site.
{
	afficheurs_.push_back(afficheur);
}

void SiteMeteo::retirerAfficheur(Afficheur* afficheur)//Méthode qui prend en parametre un pointeur d'afficheur et le retire du site tout en maintenant l'ordre.
{
	for (int i = 0; i < afficheurs_.size(); i++)
	{
		if (afficheurs_[i] == afficheur)
		{
			afficheurs_.erase(afficheurs_.begin() + i);
			break;
		}		
	}
}

void SiteMeteo::afficherSite() //Méthode qui affiche tous les afficheurs que l'attribut afficheurs_ contient.
{
	for (Afficheur* afficheur_ : afficheurs_)
	{
		switch (langue_)
		{
		case FRANCAIS: afficheur_->afficherFrancais();
			break;
		case ANGLAIS: afficheur_->afficherAnglais();
			break;
		}
	}
}

Langue SiteMeteo::getLangue() const
{
	return langue_;
}

void SiteMeteo::setLangue(Langue langue)
{
	langue_ = langue;
}