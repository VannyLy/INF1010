#ifndef	COMMERCE_H
#define COMMERCE_h
#include "Client.h"
#include "Article.h"
#include "PanierArticles.h"
#include <map>

class Rabais
{
public:
	Rabais(float discount){ discount_ = discount; };
	void operator()(Article* article)
	{
		article->setPrix(article->getPrix()*(1 - (discount_ / 100)));
	}
private:
	float discount_;

};

class TrouverNom
{
public:
	TrouverNom(const std::string& nom) : nom_(nom){};
	bool operator() (const std::pair<Client, PanierArticles*> clientPanier) 
	{
		return (clientPanier.first.getNom() == nom_);
	}
private:
	std::string nom_;
};

class PanierAlphabetique
{
public:
	PanierAlphabetique(){};
	std::pair<std::string, PanierArticles*> operator()(const pair<Client, PanierArticles*>& nomPrenomPanier)
	{
		return std::pair<std::string, PanierArticles*>(nomPrenomPanier.first.getNom() + "," + nomPrenomPanier.first.getPrenom(), nomPrenomPanier.second);
	}
};

class PanierPrixMoyen
{
public:
	PanierPrixMoyen(){};
	std::pair<float, PanierArticles*> operator()(const pair<Client, PanierArticles*>& prixPanier)
	{
		return std::pair<float, PanierArticles*>(prixPanier.second->obtenirMoyenne(), prixPanier.second);
	}
};

class Commerce
{
public:

	Commerce();
	~Commerce();

	bool ajouterCommande(const Client& client, PanierArticles* panierArticles);
	bool ajouterArticle(const Client& client, Article* article);
	bool supprimerCommande(const Client& client);
	bool supprimerArticleCommande(const Client& client, Article* article);

	void appliquerRabais(const Client& client, Rabais& rabais);
	void payerPanier(Client& client, const float& montant); ////pk pas const Client???
	void afficher(const Client& client) const;
	void afficher(const std::string& nomClient) const;
	void afficherParOrdreAlphabetique() const;
	void afficherParPrixMoyenDecroissant() const;

private:
	std::map<Client, PanierArticles*> mapClientPanier_;
};

#endif