/*============================================================================
Programmeur : William Poncelet
Fichier     : CompteEpargne.cpp
Description : Définition des functions membres de la classe CompteEpargne.h
=============================================================================*/

#include "CompteEpargne.h"

// Initialiser le constructeur
double CompteEpargne::tauxInteretAnnuel_ = 0.03;

// Construteur avec check pour le soldeEpargne
CompteEpargne::CompteEpargne(const double soldeEpargne)
{
	if (soldeEpargne >= 0)
	{
		soldeEpargne_ = soldeEpargne;
	}
	else
	{
		soldeEpargne_ = 0;
	}
}

// Applique les intêrets mneusel sur le solde épargne.
void CompteEpargne::appliquerInteretMensuel()
{
	soldeEpargne_ += soldeEpargne_ * (tauxInteretAnnuel_ / 12.0);
}

// Modifie le taux d'intêrets mensuel (statique)
void CompteEpargne::modifierTauxInteret(double interet)
{
	interet = interet / 100;

	if (interet >= 0 && interet <= 1.0)
	{
		tauxInteretAnnuel_ = interet;
	}
	else
	{
		tauxInteretAnnuel_ = 0.00;
	}
}

double CompteEpargne::getTauxInteretAnnuel()
{
	return tauxInteretAnnuel_ * 100;
}

double CompteEpargne::getSoldeEpargne() const
{
	return soldeEpargne_;
}
