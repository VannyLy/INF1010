#include "Commerce.h"
#include <iostream>
#include <functional>
#include <iterator>
using namespace std;

Commerce::Commerce() {}

Commerce::~Commerce() {}

bool Commerce::ajouterCommande(const Client& client, PanierArticles* panierArticles)
{
	if (mapClientPanier_.find(client) != mapClientPanier_.end())
	{
		return false;
	}
	else
	mapClientPanier_.insert(pair<Client, PanierArticles*>(client, panierArticles));
	return true;
}

bool Commerce::ajouterArticle(const Client& client, Article* article)
{
	auto trouverClient = mapClientPanier_.find(client);
	if (trouverClient != mapClientPanier_.end())
	{
		trouverClient->second->ajouter(article); 
		return true;
	}
	else return false;
}

bool Commerce::supprimerCommande(const Client& client)
{
	auto trouverClient = mapClientPanier_.find(client);
	if (trouverClient != mapClientPanier_.end())
	{
		mapClientPanier_.erase(trouverClient);
		return true;
	}
	else return false;
}

bool Commerce::supprimerArticleCommande(const Client& client, Article* article)
{
	auto trouverClient = mapClientPanier_.find(client);
	if (trouverClient != mapClientPanier_.end())
	{
		trouverClient->second->supprimer(article->getId());
		return true;
	}
	else return false;
}

void Commerce::appliquerRabais(const Client& client, Rabais& rabais)
{
	auto trouverClient = mapClientPanier_.find(client);
	if (trouverClient != mapClientPanier_.end()) //////////NECESSAIRE??  ANTONIO EN A PAS
	{
		for_each(trouverClient->second->getConteneur().begin(), trouverClient->second->getConteneur().end(), rabais);
	}
}

void Commerce::payerPanier(Client& client, const float& montant)
{
	client.diminueSolde(montant);
}

void Commerce::afficher(const Client& client) const
{
	auto trouverClient = mapClientPanier_.find(client);
	cout << *(trouverClient->second) << endl;  

	///cout << trouverClient->second->getConteneur() << endl;  
	/////	ANTONIO JUSTE PANIER NON?
}

void Commerce::afficher(const std::string& nomClient) const
{
	auto trouverClient = find_if(mapClientPanier_.begin(), mapClientPanier_.end(), TrouverNom(nomClient));
	cout << *(trouverClient->second) << endl;
}

void Commerce::afficherParOrdreAlphabetique() const
{
	multimap<string, PanierArticles*> nomPanierMap;
	//Au lieu d'avoir une map <cient, panier>, on veut une map <nom, panier>, alors on fait une transformation
	transform(mapClientPanier_.begin(), mapClientPanier_.end(), inserter(nomPanierMap, nomPanierMap.begin()), PanierAlphabetique());
	auto nomPrenomPanier = mapClientPanier_.begin();
	while (nomPrenomPanier != mapClientPanier_.end())
	{
		cout << nomPrenomPanier->first << endl << *(nomPrenomPanier->second) << endl << endl;
		++nomPrenomPanier;
	}
}

void Commerce::afficherParPrixMoyenDecroissant() const
{
	multimap<float, PanierArticles*, greater<float>> prixPanierMap;
	//Au lieu d'avoir une map <cient, panier>, on veut une map <prix, panier>, alors on fait une transformation
	transform(mapClientPanier_.begin(), mapClientPanier_.end(), inserter(prixPanierMap, prixPanierMap.begin()), PanierPrixMoyen());
	auto prixPanier = mapClientPanier_.begin();
	while (prixPanier != mapClientPanier_.end())
	{
		cout << "Prix Moyen : " << prixPanier->first << endl << *(prixPanier->second) << endl << endl;
		++prixPanier;
	}
}
