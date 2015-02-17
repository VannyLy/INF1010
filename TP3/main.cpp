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
	secuPoly.ajouterRegle(RegleAcces(1, "L-3589", "Matin"));
	//	1,				"L-3587",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(1, "L-3587", "Matin"));
	//	1,				"L-3588",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(1, "L-3588", "Matin"));
	//
	//	5,				"L-3589",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(5, "L-3589", "Soir"));
	//	5,				"L-3587",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(5, "L-3587", "Soir"));
	//	5,				"L-3588",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(5, "L-3588", "Soir"));
	//
	//	20,				"L-3589",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(20, "L-3589", "Nuit"));
	//	20,				"L-3587",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(20, "L-3587", "Nuit"));
	//	25,				"L-3588",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(25, "L-3588", "Nuit"));
	//
	//	10,				"L-4489",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(10, "L-4489", "Matin"));
	//	10,				"L-4487",	PERIODE_ACCES_MATIN
	secuPoly.ajouterRegle(RegleAcces(10, "L-4487", "Matin"));
	//
	//	10,				"L-4489",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(10, "L-4489", "Soir"));
	//	10,				"L-4487",	PERIODE_ACCES_SOIR
	secuPoly.ajouterRegle(RegleAcces(10, "L-4487", "Soir"));
	//
	//	20,				"L-4489",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(20, "L-4489", "Nuit"));
	//	25,				"L-4487",	PERIODE_ACCES_NUIT
	secuPoly.ajouterRegle(RegleAcces(25, "L-4487", "Nuit"));
	//
	////////////////////////////////////////////////////////////

	


	//Creer un agent de securite
	//
	//	nom: Nelson
	//  prenom: Garry
	//
	AgentSecurite agentNelson("Nelson","Garry");
	
    // afficher les infos de l'agent de sécurité (operator <<)
	
	cout << agentNelson;

	//Creer un professeur
	//
	//	nom: Rios
	//  prenom: Janet
	//
	Professeur profRios("Rios", "Janet");
	// afficher les infos du professeur (operator <<)
	cout << profRios;
	//Creer un etudiant
	//
	//	nom: Ball
	//  prenom: Damon
	//
	Etudiant etudiantBall("Ball", "Damon");
	// afficher les infos de l'étudiant (operator <<)
	cout << etudiantBall;

	//Cree un pirate Informatique qui prendra l'identite 
	//du gardien de securite

	PirateInformatique hacker(agentNelson);
	

	//L'agent de securite tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(agentNelson,"L-3587", "Nuit");
	//	"L-4489",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal(agentNelson, "L-4489", "Soir");
	//	"L-4487",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(agentNelson, "L-4487", "Nuit");
	//
	//
	
	

	//Le professeur tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_MATIN
	secuPoly.accederLocal(profRios, "L-3587", "Matin");
	//	"L-4489",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(profRios, "L-4489", "Nuit");
	//	"L-4487",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal(profRios, "L-4487", "Soir");
	//
	//
	


	//L'etudiant tente d'acceder aux locaux suivants
	//
	//	Local		Periode
	//
	//	"L-3589",	PERIODE_ACCES_MATIN
	secuPoly.accederLocal(etudiantBall, "L-3589", "Matin");
	//	"L-4489",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal(etudiantBall, "L-4489", "Nuit");
	//	"L-3589",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal(etudiantBall, "L-3589", "Soir");
	//
	//
	


	//Le pirate informatique tente d'acceder aux locaux suivants a l'aide de la fonction suivante:
	//
	//	bool accederLocal(string nom, string prenom, string fonction, unsigned int niveauAcces, string local, string periode);
	//
	//	Local		Periode
	//
	//	"L-3587",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal("Nelson", "Garry", "AgentSecurite", 25, "L-3587", "Nuit");
	//	"L-4489",	PERIODE_ACCES_SOIR
	secuPoly.accederLocal("Nelson", "Garry", "AgentSecurite", 25, "L-3587", "Soir");
	//	"L-4487",	PERIODE_ACCES_NUIT
	secuPoly.accederLocal("Nelson", "Garry", "AgentSecurite", 25, "L-4487", "Nuit");
	//
	//
	

	
	//Afficher le journal d'acces du systeme de securite
	secuPoly.imprimerJournal;
	


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
//	
//	
//	




