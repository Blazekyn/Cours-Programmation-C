/*=============================================================
Programmeur : William Poncelet
Fichier     : Devoir_5.cpp
Description : Implantation de la classe Rationnel
Date        : 2020/02/23
Source      : Notes de cours de 20887 ORD, Marco Lavoie, 6.49
=============================================================*/

//LIGNE COMMENTÉ CAR JE N'UTILISE PAS VISUAL STUDIO
//#include "stdafx.h"					// exclusif à Visual Studio

#include <iostream>					// cin, cout et endl
#include <conio.h>					// _getch()

#include "Rationnel.h"

// Fonction d'affichage de fraction.
// Paramètres:
//   chaine : étiquette à afficher avant la fraction
//   r      : fraction à afficher
void afficherRationnel(const char* chaine, Rationnel& r) {
    std::cout << chaine << '\t';
    r.affichageFraction();
    std::cout << ", \t";
    r.affichageFlottant();
    std::cout << std::endl;
}


// ** IMPORTANT LIRE **
// Bonjour Mr Bois, la façon dont j'ai fais le devoir est un peu différente car je retourne un Rationnel.
// Faire des opérations sur les rationnel r1, r2, r3 et r4 ne changera donc pas leur valeur.
// Il ne faut donc pas se fier aux "devrait afficher" ci-bas.

// Programme principal : teste la classe Rationnel
int main()
{
    Rationnel r1,			// devrait être 1/1
    r2(2),		// devrait être 2/1
    r3(6, 9),	// devrait être 2/3
    r4(3, -5);  // devrait être -3/5 (le signe doit toujours être attribué au numérateur)

    // Afficher les instances pour validation
    afficherRationnel("r1 = ", r1);		// devrait afficher 1/1, 1
    afficherRationnel("r2 = ", r2);		// devrait afficher 2/1, 2
    afficherRationnel("r3 = ", r3);		// devrait afficher 2/3, 0.666667
    afficherRationnel("r4 = ", r4);		// devrait afficher -3/5, -0.6

    // Tester l'addition de r2 à r4, puis afficher le résultat pour validation
    Rationnel addition = r4.additionner(r2);
    afficherRationnel("\nr4 = r4 + r2 >>> r4 = ", addition);	// devrait afficher 7/5, 1.4

    //// Tester la soustraction de r3 à r4, puis afficher le résultat pour validation
    Rationnel soustraction = r4.soustraire(r3);
    afficherRationnel("r4 = r4 - r3 >>> r4 = ", soustraction);		// devrait afficher 11/15, 0.733333

    //// Tester la division de r4 à r3, puis afficher le résultat pour validation
    Rationnel division = r4.diviser(r3);
    afficherRationnel("r4 = r4 / r3 >>> r4 = ", division);		// devrait afficher 11/10, 1.1

    //// Tester la multiplication de r2 à r4, puis afficher le résultat pour validation
    Rationnel multiplication = r4.multiplier(r2);
    afficherRationnel("r4 = r4 * r2 >>> r4 = ", multiplication);		// devrait afficher 11/5, 2.2

    // Attendre confirmation pour fermer la console
    std::cout << "\n\nPressez une touche pour terminer..." << std::endl;
    _getch();


    return 0;
}


