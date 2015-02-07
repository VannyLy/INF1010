/********************************************************************
 Fichier: main.cpp
 Auteur: Konstantinos Lambrou-Latreille
 Description: 
	Fichier main qui contient l'exécution principale du TP1 de INF1010.
	Bien lire les commentaires et coder les instructions.
********************************************************************/

#include <iostream>
#include "Ecole.h"
#include "Section.h"
#include "Etudiant.h"
#include "Professeur.h"

using namespace std;

int main()
{
	cout << endl;
	
	// 1) Créer automatiquement un objet Ecole avec son constructeur par défaut
	//    et modifier ses attributs :
	//	  nom="École Polytechnique de Montréal"
	//	  adresse="2900 Boulevard Edouard-Montpetit, Montréal, Québec H3T 1J4"

	Ecole polymtl;
	polymtl.setNom("École Polytechnique de Montréal");
	polymtl.setAdresse("2900 Boulevard Edouard-Monpetit,Montreal, Quebec H3T 1J4");

	
	// 2) Créer dynamiquement un objet Ecole avec son constructeur par paramètres
	//    et modifier ses attributs :
	//	  nom="Université de Québec à Montréal"
	//	  adresse="405 Rue Sainte-Catherine Est, Montréal, Québec H2L 2C4"
	
	Ecole* uqam = new Ecole("Universite de Quebec a Montreal", "405 Rue Ste-Catherine Est, Montreal, Quebec H2L 2C4");
	
	

	// 3) Créer automatiquement un objet Professeur avec son constructeur par défaut.
	//    et modifier les arguments suivants:
	//		matricule="p12"
	//		prenom="Jean-Martin"
	//		nom="Aussant"
	//		departement="Département de science économique"
	Professeur jeanMartin;
	jeanMartin.setNumeroEmploye("p12");
	jeanMartin.setPrenom("Jean - Martin");
	jeanMartin.setNom("Aussant");
	jeanMartin.setDepartement("Département de science économique");


	// 4) Créer dynamiquement un objet Professeur avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="p13"
	//		prenom="Chahira"
	//		nom="Bechiri"
	//		departement="Département de science informatique"
	Professeur* chahira = new Professeur("p13", "Chahira", "Bechiri", "Département de science informatique");

	// 5) Créer dynamiquement un objet Professeur avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="p14"
	//		prenom="Samuel"
	//		nom="Kadoury"
	//		departement="Département de génie informatique et logiciel"
	Professeur* samuel = new Professeur("p14", "Samuel", "Kadoury", "Département de génie informatique et logiciel");

	// 6) Créer dynamiquement un objet Professeur avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="p15"
	//		prenom="Michel"
	//		nom="Gagnon"
	//		departement="Département de génie informatique et logiciel"
	Professeur* michel = new Professeur("p15", "Michel", "Gagnon", "Département de génie informatique et logiciel");

	// 7) Créer automatiquement un objet Etudiant avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="1510301"
	//		prenom="Konstantinos"
	//		nom="Lambrou-Latreille"
	Etudiant konstantinos = Etudiant("1510301", "Konstantinos", "Lambrou-Latreille");
	

	// 8) Créer automatiquement un objet Etudiant avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="1475812"
	//		prenom="Kahina"
	//		nom="Bechiri"
	Etudiant kahina = Etudiant("1475812", "Kahina", "Bechiri");

	// 9) Créer automatiquement un objet Etudiant avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		matricule="1506813"
	//		prenom="Mathieu"
	//		nom="Fafard"
	Etudiant mathieu = Etudiant("1506813", "Mathieu", "Fafard");

	// 10) Créer automatiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF1000"
	//		local="C215"
	//		titre="Économie 101"
	//		prof=p12 - Jean-Martin Aussant
	Section economie = Section("ISF1000", "C215", "Économie 101", &jeanMartin);

	// 11) Ajouter le deuxième étudiant au cours ISF1000.
	economie.ajouterEtudiant(&kahina);

	// 12) Créer dynamiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="ISF2000"
	//		local="C214"
	//		titre="Étude en science cognitive"
	//		prof=p13 - Chahira Bechiri
	Section* scienceCognitive = new Section("ISF2000", "C214", "Étude en science cognitive", chahira);

	// 13) Ajouter le premier et le deuxième étudiant au cours ISF2000.
	scienceCognitive->ajouterEtudiant(&konstantinos);
	scienceCognitive->ajouterEtudiant(&kahina);

	// 14) Créer automatiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="INF1010"
	//		local="L6614"
	//		titre="Programmation orientée-objet"
	//		prof=p14 - Samuel Kadoury
	Section progOrienteeObjet("INF1010", "L6614", "Programmation orientée-objet", samuel);

	// 15) Ajouter le premier et le troisième étudiant au cours INF1010.
	progOrienteeObjet.ajouterEtudiant(&kahina);
	progOrienteeObjet.ajouterEtudiant(&mathieu);

	// 16) Créer dynamiquement un objet Section avec son constructeur par paramètre.
	//    Utiliser les arguments suivants:
	//		sigle="LOG4420"
	//		local="M6410"
	//		titre="Conception de sites web dynamiques et transactionnels"
	//		prof=p15 - Michel Gagnon
	Section* conceptionSites = new Section("LOG4420", "M6410", "Conception de sites web dynamiques et transactionnels", michel);

	// 17) Ajouter le premier, le deuxième et le troisième étudiant au cours LOG4420.
	conceptionSites->ajouterEtudiant(&konstantinos);
	conceptionSites->ajouterEtudiant(&kahina);
	conceptionSites->ajouterEtudiant(&mathieu);
	


	// 18) Ajouter le cours INF1010 et le cours LOG4420 à l'École Polytechnique.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section INF1010 et LOG4420 à l'École Polytechnique" << endl;
	cout << "===============================================" << endl;

	polymtl.ajouterSection(&progOrienteeObjet);
	polymtl.ajouterSection(conceptionSites);



	// 19) Ajouter le cours ISF1000 à l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF1000 à l'UQAM" << endl;
	cout << "===============================================" << endl;

	uqam->ajouterSection(&economie);

	// 20) Modifier le local du cours ISF2000 vers le local A250.
	scienceCognitive->setLocal("A250");

	// 21) Ajouter le cours ISF2000 à l'UQAM.
	cout << endl << "===============================================" << endl;
	cout << "Ajout de la section ISF2000 à l'UQAM" << endl;
	cout << "===============================================" << endl;

	uqam->ajouterSection(scienceCognitive);

	// 22) Supprimer le cours ISF2000 de l'UQAM
	cout << endl << "===============================================" << endl;
	cout << "On supprime la section ISF2000 à l'UQAM" << endl;
	cout << "===============================================" << endl;

	uqam->supprimerSection("A250");

	// 23) Afficher les deux écoles créées.
	uqam->afficher();
	cout << endl;
	polymtl.afficher();
	// 24) Libérer la mémoire
	delete uqam;
	delete chahira;
	delete samuel;
	delete michel;
	delete scienceCognitive;
	delete conceptionSites;

	uqam = NULL;
	chahira = NULL;
	samuel = NULL;
	michel = NULL;
	scienceCognitive = NULL;
	conceptionSites = NULL;

	cout << endl;
	return 0;
}
