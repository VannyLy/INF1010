#include <iostream>
#include <vector>
#include "Panier.h"

using namespace std;

int main()
{
	// 1. Créer un panier vide panierUn

	Panier panierUn;

	// 2. Créer quelques articles (au moins trois) avec  les constructeurs et 
	// l'opérateur >>

	Article banane(123, "Banane", 0.02);
	Article pomme(456, "Pomme", 0.03);
	Article chocolatHershey(69, "Hershey", 1.00);
	Article articlePerso;
	cout << "Entrez l'article " << endl;
	cin >> articlePerso;


	// 3. Ajouter les articles au panier

	panierUn += banane;
	panierUn += pomme;
	panierUn += chocolatHershey;
	panierUn += articlePerso;
	

	// 4. Afficher le panier

	cout << "Panier 1 : " << endl << panierUn << endl << "=====================================================" << endl << endl;

	// 5. Créer d'autres articles (au moins deux) et les placer dans un vecteur
	
	Article tamponTampax(707, "Tampon Tampax", 13.00);
	Article shampooPantene(489, "Shampooing Pantene Pro V", 9.00);
	vector<Article> vecteur;
	vecteur.push_back(tamponTampax);
	vecteur.push_back(shampooPantene);

	// 6. Créer un panierDeux qui contient initialement les articles du vecteur créé en 5
	Panier panierDeux(vecteur);

	// 7. Créer un panierTrois qui contient l'ensemble des articles du panierUn et du panierDeux (+)
	Panier panierTrois = panierUn + panierDeux;

	// 8. Retirer un article créé en 2 du panierTrois avec l'operateur -=
	panierTrois -= chocolatHershey;

	// 9. Afficher le panierTrois
	cout << "Panier 3 : " << endl << panierTrois << endl << "=====================================================" << endl << endl;
	// 10. Créer un panierQuatre vide puis lui assigner le second panier
	Panier panierQuatre;
	panierQuatre = panierDeux;

	// 11. Ajouter au panierQuatre  un article en utilisant uniquement un id (non utilisé précédement)

	Article divers(978);
	panierQuatre += divers;

	// 12. Afficher le panierQuatre

	cout << "Panier 4 : " << endl << panierQuatre << endl << "=====================================================" << endl << endl;

	// 13. Créer un panierCinq vide

	Panier panierCinq;

	// 14. Effectuer l'opération "panierCinq = article + panierQuatre" puis afficher le panier 5

	panierCinq = banane + panierQuatre;
	cout << "Panier 5 : " << endl << panierCinq << endl << "=====================================================" << endl << endl;

	// 15. Créer un panierSix vide et ajouter au moins  4 articles.

	Panier panierSix;
	panierSix += banane;
	panierSix += pomme;
	panierSix += chocolatHershey;
	panierSix += articlePerso;
	panierSix += shampooPantene;

	// 16. créer un panierSept vide

	Panier panierSept;

	//  17. Effectuer l'opération panierSept = panierSix  - panierCinq 
	
	panierSept = panierSix - panierCinq;

	//  18. Afficher le panierSept

	cout << "Panier 7 : " << endl << panierSept << endl << "=====================================================" << endl << endl;

	return 0;
}
