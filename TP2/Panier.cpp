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

Panier::~Panier()
{
	for (int i = 0; i < listeArticles_.size(); i++)
	{
		delete listeArticles_[i];
	}

}

Panier& Panier::operator= (const Panier panier)
{
	int taille = this->getTaille();
	for (int i = 0; i < taille; i++)
	{
		delete listeArticles_[taille - i - 1];
		listeArticles_.pop_back();
	}
	for (int j = 0; j < panier.listeArticles_.size(); j++)
	{
		listeArticles_.push_back(new Article(panier.listeArticles_[j]->getId(), panier.listeArticles_[j]->getNom(), panier.listeArticles_[j]->getPrix()));
	}
	total_ = panier.total_;
	return *this;
}

Panier Panier::operator+ (const Article &article) const
{
	Panier panierTemporaire(*this);
	panierTemporaire.listeArticles_.push_back(new Article(article.getId(), article.getNom(), article.getPrix()));
	panierTemporaire.total_ += article.getPrix();
	return panierTemporaire;
}

Panier Panier::operator+ (const Panier &autrePanier) const{
	Panier panierTemporaire(*this);
	for (int j = 0; j < autrePanier.listeArticles_.size(); j++)
	{
		panierTemporaire.listeArticles_.push_back(new Article(autrePanier.listeArticles_[j]->getPrix(), autrePanier.listeArticles_[j]->getNom(), autrePanier.listeArticles_[j]->getPrix()));
	}

	panierTemporaire.total_ += autrePanier.total_;
	return panierTemporaire;
}


Panier Panier::operator- (const Article &article) const
{
	Panier panierTemporaire(*this);
	for (int i = 0; i < panierTemporaire.listeArticles_.size(); i++)
	{
		if (*panierTemporaire.listeArticles_[i] == article)
		{ 
			delete panierTemporaire.listeArticles_[i];
			panierTemporaire.listeArticles_[i] = panierTemporaire.listeArticles_[panierTemporaire.listeArticles_.size()-1];
			panierTemporaire.listeArticles_.pop_back();
			break;
		}
	}
	return panierTemporaire;
}

Panier Panier::operator- (const Panier &autrePanier) const
{
	Panier panierTemporaire(*this);
	for (int i = 0; i < autrePanier.listeArticles_.size(); i++)
	{
		panierTemporaire = panierTemporaire - *autrePanier.listeArticles_[i];
	}
	return panierTemporaire;
}

void Panier::operator+= (const Article &article)
{
	*this = *this + article;
}

void Panier::operator+= (const Panier &autrePanier)
{
	*this = *this + autrePanier;
}

void Panier::operator-= (const Article &article)
{
	*this = *this - article;
}

void Panier::operator-= (const Panier &autrePanier)
{
	*this = *this - autrePanier;
}

size_t Panier::getTaille() const
{
	return listeArticles_.size();
}

float Panier::getTotal() const
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

Panier operator+ (const Article& article, const Panier& panier)
{
	return (panier + article);
}

Panier operator+ (const int& id, const Panier& panier)
{
	Article article(id);
	return (panier + article);
}