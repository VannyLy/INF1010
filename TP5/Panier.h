//NE PAS OUBLIER D'ENLEVER DEFINE T INT ET UNCOMMENT TEMPLATE T

#ifndef	PANIER_H
#define PANIER_H
#include "Article.h"
#include "FoncteurPrixZero.h"
#include <list>
#include <algorithm>
#include <fstream>

//Classe servant a trouver l'article le moins cher
class PlusPetit
{
public:
	bool operator()(Article* article1, Article* article2)
	{
		return (article1->getPrix() < article2->getPrix());
	}
};

//Classe servant a la deuxieme methode "supprimer"
class predUnaire
{
public:
	predUnaire(unsigned int id) :id_(id){};
	
	bool operator() (Article* article)
	{
		return(article->getId() == id_);
	}
private:
	unsigned int id_;
};

//Classe generique Panier
template<typename T>
class Panier
{
public:
	Panier(const unsigned int& id) :id_(id){};
	//Accesseurs
	unsigned int getId() const{ return id_; };
	const std::list<T*>& getConteneur() const { return liste_; };
	//Methodes
	void ajouter(T* ajoutListe){ liste_.push_back(ajoutListe); };
	T& obtenirPlusPetitElement() const { return **(std::min_element(liste_.begin() , liste_.end(), PlusPetit())); };
	T& obtenirPlusGrandElement() const { return **(std::max_element(liste_.begin(), liste_.end(), PlusPetit())); };
	void supprimer(const unsigned int& id)
	{ 
		liste_.erase(std::find_if(liste_.begin(), liste_.end(), predUnaire(id)));
	};
	void supprimer(FoncteurPrixZero pred){ liste_.erase(std::find_if(liste_.begin(), liste_.end(), pred)); };
	friend std::ostream& operator<<(std::ostream& os, const Panier& panier) {
		std::list<T*>::iterator iter = liste_.begin();
		while (iterator!=liste_.end())
			{
				os << **iter << endl;
				++iter;
			}
		return os;
	};


private:
	unsigned int id_;
	std::list<T*> liste_;
};
#endif