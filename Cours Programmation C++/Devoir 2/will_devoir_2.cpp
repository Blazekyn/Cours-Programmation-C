/*==========================================================
Programmeur : William Poncelet
Fichier : devoir_2.cpp
Description : Programme de jeux de barbote.
Date : 2021/01/31
==========================================================*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::time;

enum Statut {
    CONTINUER, GAGNE, PERD
};

// Prototypes de fonctions
int lancerDes();

int barbote();

void bavardage();

/// Programme principal, point d'entrée.
/// @return 0 -> Terminé correctement.
int main() {
    int rejouer, resultat;
    double soldeBanque = 100, pari = 0;

    do {
        cout << "Solde dans la banque " << soldeBanque << "$"
             << "\nEntrer le montant du pari : ";
        cin >> pari;

        while (pari > soldeBanque || pari <= 0) {
            cout << "\nEntrer un pari valide !"
                 << "\nEntrer le montant du pari : ";
            cin >> pari;
        }

        resultat = barbote();

        if (resultat == PERD) {
            soldeBanque -= pari;
            cout << "\nLa nouvelle balance est de : " << soldeBanque << "$\n";

            if (soldeBanque == 0) {
                cout << "\nDésolé. Vous avez fait faillite! \n";
                break;
            }
        } else {
            soldeBanque += pari;
            cout << "\nLa nouvelle balance est de : " << soldeBanque << "$\n";
        }

        cout << "\nVoulez vous recommencer ? oui : 1 / non : 0\n";
        cin >> rejouer;
    } while (rejouer != 0);

    return 0;
}

/// Fonction principale du jeux de la barbote.
/// Détermine si le jouer gagne ou perd une partie en cours.
/// Selon les la somme des dés lancés.
/// @return [Statut] Retourne le statut de la partie déclarer en énumération.
int barbote() {

    int somme, monPoint;
    Statut statutPartie;

    srand(time(NULL));
    somme = lancerDes(); // premier lancer des dés.

    switch (somme) {
        case 7:
        case 11: // victoire au premier lancer.
            statutPartie = GAGNE;
            bavardage();
            break;
        case 2:
        case 3:
        case 12: // défaite au premier lancer.
            statutPartie = PERD;
            bavardage();
            break;
        default: // point de rappel.
            statutPartie = CONTINUER;
            monPoint = somme;
            cout << "Le point est " << monPoint << endl;
            break; // facultatif.
    }

    while (statutPartie == CONTINUER) { // relancer les dés.

        bavardage();
        somme = lancerDes();

        if (somme == monPoint) // victoire en faisant le point.
            statutPartie = GAGNE;
        else if (somme == 7) // défaite en lançant 7.
            statutPartie = PERD;
    }

    if (statutPartie == GAGNE) {
        cout << "\nLe joueur gagne" << endl;
        return GAGNE;
    } else {
        cout << "\nLe joueur perd" << endl;
        return PERD;
    }
}

// Routine retournant le résultat d’un lancer de deux dés.
/// @return [int] Retourne la somme des deux dés.
int lancerDes() {
    int de1, de2, sommeDes;

    de1 = 1 + rand() % 6;
    de2 = 1 + rand() % 6;
    sommeDes = de1 + de2;

    cout << "\nLe joueur a lance " << de1 << " + " << de2
         << " = " << sommeDes << endl;

    return sommeDes;
}


/// Routine imprimant à la console différent message de bavardages,
/// rendant le jeux plus interactif.
void bavardage() {
    int random = 1 + rand() % 3; // 1 - 3

    switch (random) {
        case 1:
            cout << "Hmmm! Vous voulez vraiment tout perdre, n'est-ce pas?";
            break;
        case 2:
            cout << "Allez-y quoi! Tentez votre chance!";
            break;
        case 3:
            cout << "Vous êtes en pleine montée. Le temps est venu de remporter le magot!";
            break;
        default:
            break;
    }

    cout << "\n";
}

