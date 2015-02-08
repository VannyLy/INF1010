#ifndef PANIER_H
#define PANIER_H

#include <iostream>
#include <vector>
#include "Article.h"
using namespace std;
class Panier
{
public:
	Panier();
	Panier(vector<Article> articles);
	Panier(const Panier& autrePanier);
	~Panier();

	Panier& operator= (const Panier panier);

	Panier operator+ (const Article &article) const;
	Panier operator+ (const Panier &autrePanier) const;
	Panier operator- (const Article &article) const;
	Panier operator- (const Panier &autrePanier) const;

	void operator+= (const Article &article);
	void operator+= (const Panier &autrePanier);
	void operator-= (const Article &article);
	void operator-= (const Panier &autrePanier);

	friend ostream& operator<< (ostream& os, const Panier& panier);
	friend Panier operator+ (const Article& article, const Panier& panier);
	friend Panier operator+ (const int& id, const Panier& panier);

	size_t getTaille() const;
	float getTotal() const;

private:
	vector<Article*> listeArticles_;
	float total_;
};
#endif