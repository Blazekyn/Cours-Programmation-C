/*============================================================================
Programmeur : William Poncelet
Fichier     : CompteEpargne.h
Description : Classe CompteEpargne.h
=============================================================================*/

#ifndef COMPTE_EPARGNE_H
#define COMPTE_EPARGNE_H

class CompteEpargne
{
public:

	// Construteur avec check pour le soldeEpargne
	explicit CompteEpargne(double soldeEpargne);
	
	// Prototypes de fonctions membre
	void appliquerInteretMensuel();
	static void modifierTauxInteret(double);
	
	//Getter
	static double getTauxInteretAnnuel();
	double getSoldeEpargne() const;

private:
	static double tauxInteretAnnuel_;
	double soldeEpargne_;
};

#endif
