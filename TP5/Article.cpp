#include "Article.h"
#include <string>
using namespace std;

Article::Article(unsigned int id, std::string nom, float prix)
{
	id_ = id;
	nom_ = nom;
	prix_ = prix;
}

bool Article::operator<(Article& article2)
{
	if (prix_ < article2.prix_)
		return true;
	else return false;
}

ostream& operator<<(std::ostream& os, const Article& article)
{
	os << "ID de l'article: " << article.id_ << endl
		<< "Nom de l'article: " << article.nom_ << endl
		<< "Prix de l'article: " << article.prix_ << endl;
	return os;
}
