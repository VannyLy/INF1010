#ifndef	FONCTEURPRIXZERO_H
#define FONCTEURPRIXZERO_H
#include "Article.h"

class FoncteurPrixZero
{
public:
	FoncteurPrixZero(){ prix_ = 0.0; };
	bool operator()(Article* article)
	{
		return (article->getPrix() == prix_);
	}
private:
	float prix_;
};

#endif