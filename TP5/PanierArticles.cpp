//
#include "PanierArticles.h"
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

PanierArticles::PanierArticles(const unsigned int& id) : Panier(id){};

float PanierArticles::sommeArticles() const
{
	auto it = this->getConteneur().begin();
	float somme = 0;
	while (it != this->getConteneur().end()) {
		somme += (*it)->getPrix();
		++it;
	}
	return somme;
}

float PanierArticles::obtenirMoyenne() const
{
	return (sommeArticles() / this->getConteneur().size());
}

list<Article> PanierArticles::trier() const
{
	auto it = this->getConteneur().begin();
	list<Article> nouvelleListe;
	while (it != this->getConteneur().end()) 
	{
		nouvelleListe.push_back(**it);
		++it;
	}
	nouvelleListe.sort();
	nouvelleListe.reverse();
	return nouvelleListe;
}

ostream& operator<<(ostream& os, const PanierArticles& panierArticles)
{	
	auto it = panierArticles.getConteneur().begin();
	while (it != panierArticles.getConteneur().end())
	{
		os << **it << endl;
		++it;
	}
		return os;
}
