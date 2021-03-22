/*=============================================================
Programmeur : Marco Lavoie
Fichier     : main.cpp
Description : Calcul d'intérêt mensuel sur solde de compte.
Date        : 2010/03/27
Source      : Deitel & Deitel, exercice 7.8, page 522.
=============================================================*/

#include "stdafx.h"					// exclusif à Visual Studio

#include <iostream>					// cout, endl
#include <iomanip>					// setprecision
#include <conio.h>					// _getch()

#include "CompteEpargne.h"			// classe CompteEpargne

using namespace std;

// Programme principal
int _tmain(int argc, _TCHAR* argv[]) {
	CompteEpargne epargne1 = CompteEpargne( 2000.00 );
	CompteEpargne epargne2 = CompteEpargne( 3000.00 );

	cout << fixed << setprecision(2);								// ajuster l'affichage des flottants

	// Appliquer les soldes du premier mois
	cout << "Taux interest = " 
		 << CompteEpargne::getTauxInteretAnnuel() << "%" << endl;	// affiche 3.00%

	cout << "epargne1: solde:            " 
		 << epargne1.getSoldeEpargne() << " $" << endl;				// affiche 2000.00 $
	epargne1.appliquerInteretMensuel();
	cout << "          solde + interest: " 
		 << epargne1.getSoldeEpargne() << " $" << endl;				// affiche 2005.00 $

	cout << "epargne2: solde:            " 
		 << epargne2.getSoldeEpargne() << " $" << endl;				// affiche 3000.00 $
	epargne2.appliquerInteretMensuel();
	cout << "          solde + interest: " 
		 << epargne2.getSoldeEpargne() << " $" << endl << endl;		// affiche 3007.50$

	// Appliquer les soldes du second mois
	CompteEpargne::modifierTauxInteret(4.0);
	cout << "Taux interest = " 
		 << CompteEpargne::getTauxInteretAnnuel() << "%" << endl;	// affiche 4.00%

	cout << "epargne1: solde:            " 
		 << epargne1.getSoldeEpargne() << " $" << endl;				// affiche 2005.00 $
	epargne1.appliquerInteretMensuel();
	cout << "          solde + interest: " 
		 << epargne1.getSoldeEpargne() << " $" << endl;				// affiche 2011.68 $

	cout << "epargne2: solde:            " 
		 << epargne2.getSoldeEpargne() << " $" << endl;				// affiche 3007.50 $
	epargne2.appliquerInteretMensuel();
	cout << "          solde + interest: " 
		 << epargne2.getSoldeEpargne() << " $" << endl;				// affiche 3017.53 $

	// Éviter que la console soit fermée immédiatement
	cout << "\nPressez une touche pour terminer...";
	_getch();

	return 0;
}

