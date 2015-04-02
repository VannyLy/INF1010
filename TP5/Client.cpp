#include "Client.h"
#include <string>
using namespace std;


Client::Client(unsigned int id, std::string nom, std::string prenom, float solde)
{
	id_ = id;
	nom_ = nom;
	prenom_ = prenom;
	solde_ = solde;
}

bool Client::operator<(const Client& client) const
{
	return (id_ < client.id_);
}


ostream& operator<<(ostream& os, const Client& client)
{
	os << "ID du client: " << client.id_ << endl
		<< "Nom du client: " << client.nom_ << endl
		<< "Solde du client: " << client.solde_ << endl;
	return os;
}

void Client::diminueSolde(float montant)
{
	if (montant < solde_)
	solde_ = solde_ - montant;
}
