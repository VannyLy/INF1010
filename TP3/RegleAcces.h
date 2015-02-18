#ifndef REGLES_ACCES_H
#define	REGLES_ACCES_H

////////////////////////////////////////////////////////////////////////////////////
//FICHIER		REGLEACCES.H
//AUTEURS		Minh DUONG & Thuy-Vanny LY
//DATE			23 FEVRIER 2015
//DESCRIPTION	Ce fichier d'entete declare un objet de type RegleAcces ainsi que ses atributs et methodes.
////////////////////////////////////////////////////////////////////////////////////


#include <string>


const std::string PERIODE_ACCES_MATIN = "Matin";
const std::string PERIODE_ACCES_SOIR = "Soir";
const std::string PERIODE_ACCES_NUIT = "Nuit";


class RegleAcces
{
public:
	RegleAcces();
	RegleAcces(unsigned int niveau, const std::string& local, const std::string& periode);

	std::string			getLocal()				const;
	unsigned int	getNiveauAccesRequis()	const;
	std::string			getPeriode()			const;

	bool operator==(const RegleAcces& regle) const;

private:
	std::string			local_;
	unsigned int	niveauAccesRequis_;
	std::string			periode_;
};

#endif	//REGLES_ACCES_H