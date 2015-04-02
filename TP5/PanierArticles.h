//
#ifndef	PANIERARTICLES_H
#define PANIERARTICLES_H
#include <list>
#include <fstream>
#include "Panier.h"
#include "Article.h"



class PanierArticles : public Panier<Article>
{
public:
	PanierArticles();
	PanierArticles(const unsigned int& id);
	float sommeArticles() const;
	float obtenirMoyenne() const;
	std::list<Article> trier() const;
	friend std::ostream& operator<<(std::ostream& os, const PanierArticles& panierArticles); 

};


#endif