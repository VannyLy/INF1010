//NE PAS OUBLIER D'ENLEVER DEFINE T INT ET UNCOMMENT TEMPLATE T

#ifndef	ARTICLE_H
#define ARTICLE_H
#include <list>
#include <fstream>


class Article
{
public:
	Article(unsigned int id, std::string nom, float prix);

	unsigned int getId() const{ return id_; };
	std::string getNom() const{ return nom_; };
	float getPrix() const{ return prix_; };
	void setPrix(const float& prix) { prix_ = prix; };
	bool operator<(Article& article2);
	friend std::ostream& operator<<(std::ostream& os, const Article& article);
private:
	unsigned int id_;
	std::string nom_;
	float prix_;
};

#endif