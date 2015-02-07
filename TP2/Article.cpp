#include "Article.h"

using namespace std;

Article::Article()
	: id_(0), nom_(""), prix_(0)
{
}

Article::Article(int id, const string& nom, float prix)
	: id_(id), nom_(nom), prix_(prix)
{
}

Article::Article(int id)
	: id_(id), nom_("Divers"), prix_(1)
{
}

Article::~Article() {}

unsigned int Article::getId() const
{
	return id_;
}

string Article::getNom() const
{
	return nom_;
}

float Article::getPrix() const
{
	return prix_;
}

void Article::setId(unsigned int id)
{
	id_ = id;
}

void Article::setNom(const string& nom)
{
	nom_ = nom;
}

void Article::setPrix(float prix)
{
	prix_ = prix;
}

bool Article::operator==(const Article& article) const
{
	if (id_ == article.id_)
		return true;
	else 
		return false;
}

bool Article::operator!=(const Article& article) const
{
	if (id_ != article.id_)
		return true;
	else 
		return false;
}

ostream& operator<< (ostream& os, const Article& article)
{
	os << "Article #" << article.getId() << ": " << article.getNom() << ". Prix: " << article.getPrix() << "$";
	return os;
}

 istream& operator >> (istream& os, Article& article)
 { 
	 unsigned int id_;
	 string nom_;
	 float prix_;

	 os >> id_ >> nom_ >> prix_;
	 article.setId(id_); 
	 article.setNom(nom_);
	 article.setPrix(prix_);
	 return os;
 }
