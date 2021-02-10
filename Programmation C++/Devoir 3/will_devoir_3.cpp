/*==========================================================
Programmeur : William Poncelet
Fichier : devoir_3.cpp
Description : Programme de calcul de statistiques simple.
Date : 2021/01/31
==========================================================*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>

using std::setprecision;
using std::setiosflags;

#include <cmath>

//Prototypes de fonctions
void statistiques(int notes[], int N, double &moyenne, double &ecart, double &mediane);

double calculerMoyenne(const int notes[], int N);

double calculerEcartType(const int notes[], int N, double moyenne);

double calculerMediane(int notes[], int N);

void triParBulles(int notes[], int N);

void interchanger(int &a, int &b);


int main() {
    const int N = 4;
    int notes[N] = {0};
    double moyenne, ecart;
    double mediane;

    // Lire les notes
    for (int i = 0; i < N; i++) {
        cout << "Note #" << i + 1 << "? " << endl;
        cin >> notes[i];
    }
// Calculer les statistiques
    statistiques(notes, N, moyenne, ecart,
                 mediane);
//    for (int note : notes){
//        cout<< note << endl;
//    }
// Afficher les résultats
    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2)
         << "Moyenne = " << moyenne
         << "\nEcart-type = " << ecart
         << "\nMediane = " << mediane
         << endl;
    return 0;
}

void statistiques(int notes[], const int N, double &moyenne, double &ecart, double &mediane) {
    moyenne = calculerMoyenne(notes, N);
    ecart = calculerEcartType(notes, N, moyenne);
    mediane = calculerMediane(notes, N);
}

double calculerMoyenne(const int notes[], const int N) {
    double moyenne = 0;

    for (int i = 0; i < N; i++) {
        moyenne += notes[i];
    }
    moyenne /= N;

    return moyenne;
}

double calculerEcartType(const int notes[], const int N, double moyenne) {
    double totalCarreValAbsolue = 0;
    double ecartType = 0;

    //Boucle à travers les notes
    for (int i = 0; i < N; i++) {
        totalCarreValAbsolue += pow(notes[i] - moyenne, 2);
        //cout << totalCarreValAbsolue << endl;
    }
    ecartType = sqrt(totalCarreValAbsolue / N);
    //cout << "Total: " << totalCarreValAbsolue << endl;
    return ecartType;
}

double calculerMediane(int notes[], const int N) {
    double mediane = 0;
    int milieuPair = 0;
    int milieuImpair = 0;

    //1. Ordonner la distribution
    triParBulles(notes, N);

    //2.1 Si la distribution est paire
    if (N % 2 == 0){
        milieuPair = N / 2;
        // Milieu pair - 1 ici car on se base sur un tableau qui commence à 0.
        mediane = static_cast<double> ((notes[milieuPair - 1]) +  (notes[milieuPair])) / 2;
    }

    //2.2 Si la distribution est impaire.
    else{
        milieuImpair = ceil(N / 2);
        mediane = notes[milieuImpair];
    }

    return mediane;
}

void triParBulles(int notes[], const int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            if (notes[j] < notes[j - 1])
                interchanger(notes[j], notes[j - 1]);
        }
    }
}

void interchanger(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}