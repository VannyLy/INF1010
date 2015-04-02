#include "AfficheurDateHeure.h"
#include "AfficheurMeteo.h"
#include "AfficheurMeteoStatistiques.h"
#include "Meteo.h"
#include "DateHeure.h"
#include "SiteMeteo.h"

#include <Windows.h>
#include <cstdlib>
#include <time.h>

int main()
{
	srand(time(0));

	//Creer un objet AfficheurDateHeure
	AfficheurDateHeure afficheurDateHeure;

	//Creer un objet AfficheurMeteo
	AfficheurMeteo afficheurMeteo;

	//Creer un objet AfficheurMeteoStatistiques
	AfficheurMeteoStatistiques afficheurMeteoStatistique;

	//Creer un objet Meteo avec son constructeur par parametres
	Meteo meteo(20,70,80);

	//Connecter les afficheurs AfficheurMeteo et AfficheurMeteoStatistiques a la base de donnees Meteo
	meteo.ajouterConnection(&afficheurMeteo);
	meteo.ajouterConnection(&afficheurMeteoStatistique);


	//Creer un objet DateHeure
	DateHeure dateHeure;

	//Connecter l'afficheur AfficheurDateHeure a la base de donnees DateHeure
	dateHeure.ajouterConnection(&afficheurDateHeure);

	//Creer un objet SiteMeteo
	SiteMeteo siteMeteo;

	//Ajouter les afficheurs AfficheurDateHeure, AfficheurMeteo et AfficheurMeteoStatistiques
	siteMeteo.ajouterAfficheur(&afficheurDateHeure);
	siteMeteo.ajouterAfficheur(&afficheurMeteo);
	siteMeteo.ajouterAfficheur(&afficheurMeteoStatistique);

	for (;;)
	{
		//Mettre a jour les donnees des objets DonneesMeteo et DateHeure
		meteo.mettreAJourDonnees();
		dateHeure.mettreAJourDonnees();

		//Afficher le site meteo 
		siteMeteo.afficherSite();

		//Pesez sur la touche F pour afficher en francais
		if (GetAsyncKeyState(0x46))	//F
		{
			//Mettre la langue en francais
			siteMeteo.setLangue(FRANCAIS);
		}

		//Pesez sur la touche A pour afficher en francais
		else if (GetAsyncKeyState(0x41)) //A
		{
			//Mettre la langue en Anglais
			siteMeteo.setLangue(ANGLAIS);
		}


		Sleep(1000);
		system("cls");
	}


	return 0;
}