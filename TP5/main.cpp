
#include <vector>
#include <iostream>
#include "Foncteur.h"
#include "PanierArticles.h"
#include "Commerce.h"
#include "FoncteurPrixZero.h"

using namespace std;

class FoncteurAfficherArticle
{
public:
	FoncteurAfficherArticle(){};
	void operator() (const Article article)
	{
		cout << article;
	}
};

int main() {
	// 1) Créer une classe PanierArticle avec un id quelconque.
	PanierArticles panier1(1);
    
	// 2) Ajouter les articles suivants dans le panier
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$
	// Article 2 -> id = 2, nom = Film, prix = 34.97$
	// Article 3 -> id = 3, nom = Accessoire, prix = 12.12$
	// Article 4 -> id = 4, nom = Article bizarre, prix = 0.0$
	// Article 5 -> id = 5, nom = Mauvais article, prix = 0.0$
	Article* article1 = new Article(1,"Livre", 32.73);
	Article* article2 = new Article(2, "Film", 34.97);
	Article* article3 = new Article(3, "Accessoire", 12.12);
	Article* article4 = new Article(4, "Article Bizarre", 0.0);
	Article* article5 = new Article(5, "Mauvais Article", 0.0);

	panier1.ajouter(article1);
	panier1.ajouter(article2);
	panier1.ajouter(article3);
	panier1.ajouter(article4);
	panier1.ajouter(article5);

	// Afficher le panier avec l'opérateur <<
	cout << panier1 << endl;
    
	// 3) Afficher la moyenne des prix des articles du panier
	panier1.obtenirMoyenne();
	
	// 4) Afficher l'id de l'article le moins cher et l'id de l'article le plus cher
	cout << "L'ID de l'article le moins cher" <<panier1.obtenirPlusPetitElement().getId() << endl;
	cout << "L'ID de l'article le moins cher" << panier1.obtenirPlusGrandElement().getId() << endl;
    
	// 5) Supprimer l'article avec id = 2.
	cout << "Supprimer l'article avec id = 2..." << endl << endl;
	panier1.supprimer(2);
    
	// 6) Supprimer les articles qui ont un prix == 0. Créer un foncteur FoncteurPrixZero
	// et le passer en paramètre dans la méthode supprimer.
	cout << "Supprimer les articles avec un prix = 0..." << endl << endl;
	panier1.supprimer(FoncteurPrixZero());
    
	// 7) Afficher de nouveau le panier
	cout << "Afficher de nouveau le panier..." << endl;
	cout << panier1 << endl;
    
	// 8) Appeller la fonction trier du panier et afficher la liste d'article obtenue avec
	// la fonction for_each.
	cout << "Trier le panier" << endl;
	list<Article> listeTriee = panier1.trier();
	cout << "=============================" << endl;
	for_each(listeTriee.begin(), listeTriee.end(), FoncteurAfficherArticle()); 
	cout << "=============================" << endl << endl << endl;
	
    
	// 9) Créer un nouveau panier avec id = 2.
	PanierArticles panier2(2);
    
	// 10) Ajouter les articles suivants dans ce panier:
	// Article 1 -> id = 1, nom = Livre, prix = 32.73$ (reprendre celui créer plus haut)
	// Article 6 -> id = 6, nom = Laptop, prix = 400.0$
	panier2.ajouter(article1);
	Article* article6 = new Article(6, "Laptop", 400.00);
	panier2.ajouter(article6);

	// 11) Créer les clients suivants:
	// Client 1 -> id = 1, nom = Doe, prenom = John
	// Client 2 -> id = 2, nom = Tremblay, prenom = Martin
	Client clientJohn(1, "Doe", "John", 0.0);
	Client clientMartin(2, "Tremblay", "Martin", 0.0);

	cout << "*********** COMMERCE ***********" << endl;
	// 12) Créer un commerce et ajouter deux commandes
	// Commande 1 -> John Doe avec panier 1
	// Commande 2 -> Martin Tremblay avec panier 2
	Commerce target;
	target.ajouterCommande(clientJohn, &panier1);
	target.ajouterCommande(clientMartin, &panier2);

	// 13) Afficher les commandes par ordre alphabétique
	cout << "************* Affichage alphabetique ****************" << endl;
	target.afficherParOrdreAlphabetique();

	// 14) Afficher les commandes en ordre décroissant par le prix moyen des panier
	cout << "************* Affichage prix moyen decroissant **************" << endl;
	target.afficherParPrixMoyenDecroissant();

	// 15) Appliquer 10% de rabais sur le panier de Martin. 
	cout << "*********** Affichage apres modifications ***********" << endl;
	target.appliquerRabais(clientJohn, Rabais(10.0));
	target.afficher("Tremblay");

	// 16) Créer l'article suivant:
	// Article 7 -> id = 7, nom = "Bureau", prix = 200
	Article* article7 = new Article(7, "Bureau", 200.0);

	// 17) Ajouter l'article 7 au panier de John
	target.ajouterArticle(clientJohn, article7);

	// 18) Supprimer l'article 3 de John
	target.supprimerArticleCommande(clientJohn, article3);

	// 19) Afficher les commandes en ordre décroissant par le prix moyen des panier
	target.afficherParPrixMoyenDecroissant();

	// 20) Supprimer la commande de Martin et afficher les commandes en ordre alphabétique
	cout << "******** Affichage apres suppression commande ************" << endl;
	target.supprimerCommande(clientMartin);
	target.afficherParOrdreAlphabetique();

	// 21) Libérer la mémoire (si nécessaire)
	delete article1;
	delete article2;
	delete article3;
	delete article4;
	delete article5;
	delete article6;
	delete article7;

	return 0;
}
