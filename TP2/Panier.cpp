#include "Panier.h"

using namespace std;

Panier::Panier(){
	total_ = 0;
}

Panier::Panier(vector<Article> articles){
	for (int j = 0; j < articles.size(); j++)
	{
		listeArticles_.push_back(new Article(articles[j].getId(), articles[j].getNom(), articles[j].getPrix()));
		total_ += articles[j].getPrix();
	}
}

Panier::Panier(const Panier& autrePanier){
	total_ = autrePanier.total_;
	for (int j = 0; j < autrePanier.listeArticles_.size(); j++)
	{
		listeArticles_.push_back(new Article(autrePanier.listeArticles_[j]->getId(), autrePanier.listeArticles_[j]->getNom(), autrePanier.listeArticles_[j]->getPrix()));
	}
}

Panier::~Panier(){}

Panier& Panier::operator= (Panier panier){
	int taille = this->getTaille();
	for (int i = 0; i < taille; i++)
	{
		listeArticles_.pop_back();
	}
	for (int j = 0; j < panier.listeArticles_.size(); j++)
	{
		listeArticles_.push_back(new Article(panier.listeArticles_[j]->getId(), panier.listeArticles_[j]->getNom(), panier.listeArticles_[j]->getPrix()));
	}
	total_ = panier.total_;
	return *this;
}

Panier Panier::operator+ (Article article){
	Panier panierTemporaire(*this);
	panierTemporaire.listeArticles_.push_back(new Article(article.getId(), article.getNom(), article.getPrix()));
	panierTemporaire.total_ += article.getPrix();
	return panierTemporaire;
}

Panier Panier::operator+ (Panier autrePanier){
	Panier panierTemporaire(*this);
	for (int j = 0; j < autrePanier.listeArticles_.size(); j++)
	{
		panierTemporaire.listeArticles_.push_back(new Article(autrePanier.listeArticles_[j]->getPrix(), autrePanier.listeArticles_[j]->getNom(), autrePanier.listeArticles_[j]->getPrix()));
	}

	panierTemporaire.total_ += autrePanier.total_;
	return panierTemporaire;
}


Panier Panier::operator- (Article article)
{
	Panier panierTemporaire(*this);
	for (int i = 0; i < panierTemporaire.listeArticles_.size(); i++)
	{
		if (*panierTemporaire.listeArticles_[i] == article)
		{ 
			panierTemporaire.listeArticles_[i] = panierTemporaire.listeArticles_[panierTemporaire.listeArticles_.size()-1];
			panierTemporaire.listeArticles_.pop_back();
			break;
		}
	}
	return panierTemporaire;
}

Panier Panier::operator- (Panier &autrePanier)
{
	Panier panierTemporaire(*this);
	for (int i = 0; i < autrePanier.listeArticles_.size(); i++)
	{
		panierTemporaire = panierTemporaire - *autrePanier.listeArticles_[i];
	}
	return panierTemporaire;
}

void Panier::operator+= (Article article){
	*this = *this + article;
}

void Panier::operator+= (Panier autrePanier){
	*this = *this + autrePanier;
}

void Panier::operator-= (Article article){
	*this = *this - article;
}

void Panier::operator-= (Panier &autrePanier){
	*this = *this - autrePanier;
}

size_t Panier::getTaille()
{
	return listeArticles_.size();
}

float Panier::getTotal()
{
	return total_;
}

ostream& operator<< (ostream& os, const Panier& panier)
{
	os << "Contenu du panier : " << endl;
	for (int i = 0; i < panier.listeArticles_.size(); i++)
	{
		os << *panier.listeArticles_[i] << endl;
	}
	
		os << "Prix total du panier : " << panier.total_;
		return os;
}

Panier operator+ (Article& article, Panier& panier)
{
	return (panier + article);
}