/*==========================================================
Programmeur : William Poncelet
Fichier : main.cpp
Description : Programme de calcul de la paye d'un employé.
Date : 2021/01/07
==========================================================*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void menuPrompt() {
    cout << "\n------------------------ Menu ------------------------\n"
         << "1: Cadre                                \n"
         << "2: Travailleur horaire                  \n"
         << "3: Travailleur commission               \n"
         << "4: Travailleur piece                    \n"
         << "Veuillez selectionner (1,2,3,4) ou 0 pour quitter:";
}

int inputPrompt() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cout << "\nValeur numerique seulement !" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        menuPrompt();
        cin >> input;
    }
    return input;
}


int main() {
    int codePaye;
    int pieces;

    double salaireCadre, salaireTHoraire, salaireTCommission, salaireTPiece;
    double heures, paye;

    do {
        menuPrompt();
        codePaye = inputPrompt();

        switch (codePaye) {
            case 1:
                cout << "-- Cadre --\n"
                     << "Salaire hebdomadaire fixe:";
                cin >> salaireCadre;
                cout << "Le cadre a fait " << salaireCadre << "$ cette semaine.\n";
                break;

            case 2:
                cout << "-- Travailleur horaire --\n"
                     << "Taux horaire:";
                cin >> salaireTHoraire;
                cout << "Nombre dheures:";
                cin >> heures;

                if (heures > 40) {
                    paye = (salaireTHoraire * 40) + (heures - 40) * 1.5 * salaireTHoraire;
                } else {
                    paye = salaireTHoraire * 40;
                }
                cout << "Le travailleur horaire a fait " << paye << "$ cette semaine.\n";
                break;

            case 3:
                cout << "-- Travailleur commission --\n"
                     << "Ventes hebdomadaires:";
                cin >> salaireTCommission;
                paye = 250.0 + (0.057 * salaireTCommission);
                cout << "Le travailleur commission a fait " << paye << "$ cette semaine.\n";
                break;

            case 4:
                cout << "-- Travailleur piece --\n"
                     << "Nombre de piece:";
                cin >> pieces;
                cout << "Taux par piece:";
                cin >> salaireTPiece;
                paye = pieces * salaireTPiece;
                cout << "Le travailleur piece a fait " << paye << "$ cette semaine.\n";
                break;

            default:
                cout << "Veuillez entrer un code de paye valide.\n";
                break;
        }
    } while (codePaye != 0);

    cout << "Fermeture du programme ...";
    return 0;
}
