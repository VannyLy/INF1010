/********************************************************************
Fichier: main.cpp
Auteur: Minh DUONG & Thuy-Vanny LY
Description:
Fichier main qui contient l'exécution principale du TP3 de INF1010.
Bien lire les commentaires et coder les instructions.
********************************************************************/

#include "SystemeSecurite.h"
#include "PirateInformatique.h"
using namespace std;

int main()
{
	//Creer le systeme de securite
	
	SystemeSecurite secuPoly;
	/////////////////////////////////////////////////////////////
	//Ajouter les regles suivantes:
	//
	//	niveau d'acces	Local		Periode
	//
	//	1,				"L-3589",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(1, "L-3589", PERIODE_ACCES_MATIN));
	//	1,				"L-3587",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(1, "L-3587", PERIODE_ACCES_MATIN));
	//	1,				"L-3588",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(1, "L-3588", PERIODE_ACCES_MATIN));
	//
	//	5,				"L-3589",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(5, "L-3589", PERIODE_ACCES_SOIR));
	//	5,				"L-3587",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(5, "L-3587", PERIODE_ACCES_SOIR));
	//	5,				"L-3588",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(5, "L-3588", PERIODE_ACCES_SOIR));
	//
	//	20,				"L-3589",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(20, "L-3589", PERIODE_ACCES_NUIT));
	//	20,				"L-3587",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(20, "L-3587", PERIODE_ACCES_NUIT));
	//	25,				"L-3588",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(25, "L-3588", PERIODE_ACCES_NUIT));
	//
	//	10,				"L-4489",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(10, "L-4489", PERIODE_ACCES_MATIN));
	//	10,				"L-4487",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(10, "L-4487", PERIODE_ACCES_MATIN));
	//
	//	10,				"L-4489",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(10, "L-4489", PERIODE_ACCES_SOIR));
	//	10,				"L-4487",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(10, "L-4487", PERIODE_ACCES_SOIR));
	//
	//	20,				"L-4489",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(20, "L-4489", PERIODE_ACCES_NUIT));
	//	25,				"L-4487",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(25, "L-4487", PERIODE_ACCES_NUIT));
	//
	////////////////////////////////////////////////////////////

	


	//Creer un agent de securite
	//
	//	nom: Nelson
	//  prenom: Garry
	//
	AgentSecurite agentNelson("Nelson","Garry");
	
    // afficher les infos de l'agent de sécurité (operator <<)
	
	cout << agentNelson << endl;

	//Creer un professeur
	//
	//	nom: Rios
	//  prenom: Janet
	//
	Professeur profRios("Rios", "Janet");
	// afficher les infos du professeur (operator <<)
	cout << profRios << endl;
	//Creer un etudiant
	//
	//	nom: Ball
	//  prenom: Damon
	//
	Etudiant etudiantBall("Ball", "Damon");
	// afficher les infos de l'étudiant (operator <<)
	cout << etudiantBall << endl;

	//Cree un pirate Informatique qui prendra l'identite 
	//du gardien de securite

	PirateInformatique hacker(agentNelson);
	

	//L'agent de securite tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(agentNelson, "L-3587", PERIODE_ACCES_NUIT);
	//	"L-4489",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal(agentNelson, "L-4489", PERIODE_ACCES_SOIR);
	//	"L-4487",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(agentNelson, "L-4487", PERIODE_ACCES_NUIT);
	//
	//
	
	

	//Le professeur tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_MATIN
	secuPoly.accederLocal(profRios, "L-3587", PERIODE_ACCES_MATIN);
	//	"L-4489",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(profRios, "L-4489", PERIODE_ACCES_NUIT);
	//	"L-4487",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal(profRios, "L-4487", PERIODE_ACCES_SOIR);
	//
	//
	


	//L'etudiant tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3589",	PERIODE_ACCES_MATIN
	secuPoly.accederLocal(etudiantBall, "L-3589", PERIODE_ACCES_MATIN);
	//	"L-4489",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(etudiantBall, "L-4489", PERIODE_ACCES_NUIT);
	//	"L-3589",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal(etudiantBall, "L-3589", PERIODE_ACCES_SOIR);
	//
	//
	


	//Le pirate informatique tente d'acceder aux locaux suivants a l'aide de la fonction suivante:
	//
	//	bool accederLocal(string nom, string prenom, string fonction, unsigned int niveauAcces, string local, string periode);
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal("Nelson", "Garry", "AgentSecurite", 25, "L-3587", PERIODE_ACCES_NUIT);
	//	"L-4489",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal("Nelson", "Garry", "AgentSecurite", 25, "L-3587", PERIODE_ACCES_SOIR);
	//	"L-4487",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal("Nelson", "Garry", "AgentSecurite", 25, "L-4487", PERIODE_ACCES_NUIT);
	//
	//
	

	
	//Afficher le journal d'acces du systeme de securite
	secuPoly.imprimerJournal();
	


	return 0;
}


//Reponse a la question:
//	
//	
//	Employe* etudiant = new Etudiant("Ball", "Damon");
//
//	sysSecu.accederLocal	(	etudiant->getNom(), 
//								etudiant->getPrenom(), 
//								etudiant->getFonction(), 
//								etudiant->getNiveauAcces(), 
//								"L-3589", 
//								PERIODE_ACCES_NUIT
//							);
//
//	delete etudiant;
//	
//	L'etudiant peut accéder le local avec un niveau d'acces requis de 5, car un pointeur utilise 
//  les methodes de la classe mère c-a-d Employe au lieu de la classe dérivée Etudiant.Nous utilisons 
//  donc la methode getNiveauAcces de la classe Employe qui elle retourne le niveau d'acces d'un 
//  employé donc[5] au lieu de[1] de la classe Etudiant.C'est pour cela que nous devons utiliser le 
//  polymorphisme.
//	




