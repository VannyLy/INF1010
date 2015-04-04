//NE PAS OUBLIER D'ENLEVER DEFINE T INT ET UNCOMMENT TEMPLATE T

#ifndef	CLIENT_H
#define CLIENT_H
#include <list>
#include <fstream>


class Client
{
public:
	Client(unsigned int id, std::string nom, std::string prenom, float solde);
	unsigned int getId() const{ return id_; };
	std::string getNom() const{ return nom_; };
	std::string getPrenom() const{ return prenom_; };
	float getSolde(){ return solde_; };
	bool operator<(const Client& client) const;
	friend std::ostream& operator<<(std::ostream& os, const Client& client);
	void diminueSolde(float montant);

private:
	unsigned int id_;
	std::string nom_;
	std::string prenom_;
	float solde_;

};

#endif