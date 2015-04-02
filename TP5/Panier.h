//NE PAS OUBLIER D'ENLEVER DEFINE T INT ET UNCOMMENT TEMPLATE T

#ifndef	PANIER_H
#define PANIER_H
#include <list>
#include <algorithm>
#include <fstream>


//Classe servant a la deuxieme methode "supprimer"
template<typename T>
class predUnaire
{
public:
	predUnaire(unsigned int id) :id_(id){};
	
	bool operator() (T* article)
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
	T& obtenirPlusPetitElement() const { return **(std::min_element(liste_.begin() , liste_.end())); };
	T& obtenirPlusGrandElement() const { return **(std::max_element(liste_.begin(), liste_.end())); };
	void supprimer(const unsigned int& id)
	{ 
		//predUnaire condition(id);
		liste_.erase(std::find_if(liste_.begin(), liste_.end(), predUnaire<T>(id)));
	};	
	template<typename Predicat>
	void supprimer(Predicat pred){ liste_.erase(std::find_if(liste_.begin(), liste_.end(), !pred)); };
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