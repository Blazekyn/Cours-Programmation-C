/*=============================================================
Programmeur : William Poncelet
Fichier     : Rationnel.cpp
Description : Définition des fonctions membres de Rationnel.h
Date        : 2020/02/23
=============================================================*/

// ReSharper disable CommentTypo

#include <iostream>

using std::cout;
using std::endl;

#include "Rationnel.h"


/**
 * Constructeur.
 * @param a -> Le numérateur.
 * @param b -> Le dénominateur.
 */
Rationnel::Rationnel(const int a, const int b) {
    numerateur_ = a;
    denominateur_ = b;
}

/**
 * Fonction d'addition rationnel. Est appelé d'une instance d'objet rationnel.
 * @param r_addition -> Paramètre Rationnel à effectuer l'addition.
 * @return Un nouveau Rationnel.
 */
Rationnel Rationnel::additionner(const Rationnel& r_addition) const {
    Rationnel r;

    //Multiplication du dénominateur commun.
    r.denominateur_ = r_addition.denominateur_ * denominateur_;

    //Produit croisé additionné.
    r.numerateur_ = r_addition.numerateur_ * denominateur_;
    r.numerateur_ += r_addition.denominateur_ * numerateur_;

    return r;
}

/**
 * Fonction de soustraction rationnel. Est appelé d'une instance d'objet rationnel.
 * @param r_soustraire -> Paramètre Rationnel à effectuer la soustraction.
 * @return Un nouveau Rationnel.
 */
Rationnel Rationnel::soustraire(const Rationnel& r_soustraire) const {

    Rationnel r;

    //Multiplication du dénominateur commun.
    r.denominateur_ = r_soustraire.denominateur_ * denominateur_;

    //Produit croisé soustrait.
    r.numerateur_ = r_soustraire.denominateur_ * numerateur_;
    r.numerateur_ -= r_soustraire.numerateur_ * denominateur_;

    return r;
}

/**
 * Fonction de multiplication rationnel. Est appelé d'une instance d'objet rationnel.
 * @param r_multiplier -> Paramètre Rationnel à effectuer la multiplication.
 * @return Un nouveau Rationnel.
 */
Rationnel Rationnel::multiplier(const Rationnel& r_multiplier) const {

    Rationnel r;

    //Multiplication linéaire
    r.denominateur_ = r_multiplier.denominateur_ * denominateur_;
    r.numerateur_ = r_multiplier.numerateur_ * numerateur_;

    return r;
}

/**
 * Fonction de division rationnel. Est appelé d'une instance d'objet rationnel.
 * @param r_division -> Paramètre Rationnel à effectuer la division.
 * @return Un nouveau Rationnel.
 */
Rationnel Rationnel::diviser(Rationnel& r_division) const {

    Rationnel r;

    // Multiplication de l'inverse
    r.numerateur_ = r_division.denominateur_ * numerateur_;
    r.denominateur_ = r_division.numerateur_ * denominateur_;

    return r;
}

/**
 * Fonction d'affichage d'une fraction avec
 * check pour division par 0.
 */
void Rationnel::affichageFraction() {
    if (denominateur_ == 0) {
        cout << "\nErreur : Division par 0 non permise" << '\n';
    }
    else if (numerateur_ == 0) {
        cout << 0;
    }
    else {
        // Inversion de signe si le dénominateur est plus petit que 0

        reduction(numerateur_, denominateur_);
        cout << numerateur_ << '/' << denominateur_;
    }
}

/**
 * Fonction d'affichage des fractions en nombre flottant.
 */
void Rationnel::affichageFlottant() const {
    cout << static_cast<double>(numerateur_) / denominateur_;
}

/**
 * Fonction de réduction de fraction et inversion de signes pour l'affichage.
 * @param a Le numérateur.
 * @param b Le dénominateur.
 */
void Rationnel::reduction(int a, int b) {

    // Algorithme d'Euclide pour trouver le plus grand commun diviseur.
    while (b != 0) {
        int tempo = b;
        b = a % b;
        a = tempo;
    }

    if (a != 0) {
        //        if (numerateur < 0){
        //            numerateur = -numerateur;
        //        }

        //        cout << "\nNumerateur avant reduction : "<< numerateur << endl;
        //        cout << "\nDenominateur avant reduction : "<< denominateur << endl;
        //        cout << "\nNum : "<< a << endl;

                // Inversion des signes pour avoir le négatif toujours en haut.
        if (denominateur_ < 0 || a == -1) {
            denominateur_ = -denominateur_;
            numerateur_ = -numerateur_;
        }

        numerateur_ /= a;
        denominateur_ /= a;

    }
}




