/*==================================================================
Programmeur : William Poncelet
Fichier : exercice4_1.cpp
Description : Programme de transformation minuscules -> majuscules.
Date : 2021/01/31
===================================================================*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Prototype de fonctions
void majuscules(char chaine[]);
void majusculesV2(char chaine[]);

// Programme principal
int main() {
    const int MAXLEN = 256; // longueur maximale de chaîne traitée
    char chaine[MAXLEN] = ""; // tableau stockant la chaîne à traiter

    // Lire la chaîne à traiter
    cout << "Chaîne ? ";
    cin >> chaine;

    // Convertir en majuscules
    majusculesV2(chaine);

    // Afficher le résultat
    cout << "\nRésultat: " << chaine << endl;
    return 0;
}

//Avec la fonction "toupper" de la libraire standard
void majuscules(char chaine[]) {
    for (int i = 0; chaine[i] != '\0'; i++)
        chaine[i] = static_cast<char> (toupper(chaine[i]));
}

// Avec la table ascii
void majusculesV2(char chaine[]) {
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] >= 97 && chaine[i] <= 122) {
            chaine[i] = static_cast<char> (chaine[i] - 32);
        }
    }
}